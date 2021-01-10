#include "Briscola.hpp"

BriscolaGameModel::BriscolaGameModel()
{
}

BriscolaGameModel::~BriscolaGameModel()
{
}

void BriscolaGameModel::startGame(){
    data->shuffle();
    ptsManche = 0;
    table = nullptr;
    std::cout<<"--------------------------start game ----------------------------\n";
    for(Player *player : playerManager->players){
        for(int i=0; i<3;i++){ // on distribue 3 carte à chaque joueur
            player->getHand()->addData(data->draw());
        }
    }
    atout = data->draw(); // a verif
    //TODO()
}

void BriscolaGameModel::countScore(){
    //TODO()
}

Carte* BriscolaGameModel::getTable(){
    return table;
}

Carte* BriscolaGameModel::getAtout(){
    return atout;
}

void BriscolaGameModel::setTable(Carte* newCarte){
    table = newCarte;
}

void BriscolaGameModel::resetManche(){
    ptsManche = 0;
    table  = nullptr;
}

void BriscolaGameModel::addPoints(int pts){
    ptsManche += pts;
}

int BriscolaGameModel::getPtsManche(){
    return ptsManche;
}

void BriscolaGameModel::pushDataFromStrLine(std::vector<std::string> line){
    Carte* result = new Carte(line[2]); // description utilise pour le nom
    result->addAttribut(line[1]);        // les differentes enseignes (coupes, batons, etc...) (carte italienne)
    result->addAttribut(line[2]);        // description pour Vue
    result->addAttribut(line[3]);        // Hierarchie des cartes dans la partie. Carte de hierarchie x gagne contre une carte de hierarchie y ssi x>y
    result->addAttribut(line[4]);        // points que vaut la carte lors du comptage des points
    data->addData(result);
   
}

void BriscolaGameModel::initPlayers(){

    int nbPlayer = std::stoi(gameController->askUser("Combien de joueur vous etes?"));
    for (int i = 0; i < nbPlayer; i++){
    
        std::string playerName = gameController->askUser("Quelle est votre nom?");      
        Player *p = new Player{playerName, 1};
        playerManager->addPlayer(p);
        gameView->afficher("Le joueur "+ p->getName() + " a rejoins la partie");
    }
}

bool BriscolaGameModel::isGameOver(){ // verifie les conditions de fin de jeu
    //TODO (non necessaire)
    return false;
}


Briscola::Briscola():parseur(Parseur("BriscolaCarte40.txt", 5,false)){
    //parseur.print_lines();
    gameModel.data = new CollectionCarte();
    gameModel.initGameData(parseur.get_lignes());
    gameModel.playerManager = new PlayerManager();
    
    gameModel.gameView = &gameView;
    gameModel.gameController = &gameController;
    gameModel.initPlayers();
}

Briscola::~Briscola()
{
}

void Briscola::start(){
    gameModel.startGame();// distribuer les cartes au joueurs + atout
    std::string nameWinner;

    while (!gameModel.data->isEmpty()){

        gameView.afficher("==============================================");
        for(Player *player : gameModel.getPlayerManager()->players){
            std::cout<<player->getName()<<" : "<<player->getScore()<<" points, ";
        }
        std::cout<<std::endl;
        gameView.afficher("==============================================\n");
        gameView.afficher("La carte Atout est : "+gameModel.getAtout()->getName());
        for(int i=0;i<gameModel.getPlayerManager()->nbPlayers();i++){
            Player * player = gameModel.getPlayerManager()->getCurrentPlayer();
            gameView.afficher("==============================================\n");
            gameView.afficher("C'est au tour de : "+ player->getName());
            //gameView.afficherPlayersCollection(player->getHand()); 
            if(i==0){
                gameView.afficher("Veuillez poser la premiere carte :");
            }else{
                gameView.afficher("La carte actuellement mise sur la table est :");
                gameView.afficher(gameModel.table->toString());
            }
            bool succeed = false;
            Command * command;
            command = new JouerCommand(&gameModel,&gameController,&gameView,&succeed);
            command->run();
            if(succeed){
            nameWinner = player->getName();
            }
            gameModel.playerManager->rotateToNext();
        }
        //on modifie maintenant le current player pour la prochaine manche
        //le premier joueur est le gagnant de l'ancienne manche
        while(gameModel.getPlayerManager()->getCurrentPlayer()->getName()!=nameWinner){
             gameModel.playerManager->rotateToNext();
        }
        int oldScore = gameModel.getPlayerManager()->getCurrentPlayer()->getScore();
        gameModel.getPlayerManager()->getCurrentPlayer()->setScore(oldScore += gameModel.getPtsManche());
        //puis on reinitialise la manche
        gameModel.resetManche();

        //on redistribue 1 carte a chaque joueur
        for(Player *player : gameModel.getPlayerManager()->players){
            if(gameModel.data->size()>0){
                player->getHand()->addData(gameModel.data->draw());
            }else{
                player->getHand()->addData(gameModel.getAtout());
            }
            
        }
        

    }
    gameView.afficher("-------------------------------------------------");
    gameView.afficher("La partie est terminee");
    std::string gagnant = "";
    int scoreGagnant =0;
    for(Player *player : gameModel.getPlayerManager()->players){
        if(player->getScore()>scoreGagnant){
            scoreGagnant=player->getScore();
            gagnant = player->getName();
        }
    }
    gameView.afficher("Le joueur gagnant est :");
    gameView.afficher(gagnant);
    std::cout<<"( "<<scoreGagnant<<" points )"<<std::endl;

}

int compare(Carte * first, Carte * second){

    std::map<std::string, int> order;
    order["2"] = 2;
    order["4"] = 4;
    order["5"] = 5;
    order["6"] = 6;
    order["7"] = 7;
    order["8"] = 8;
    order["9"] = 9;
    order["10"] = 10;
    order["V"] = 11;
    order["D"] = 12;
    order["R"] = 13;
    order["A"] = 14;

    //std::cout<<"premier :" <<order[first->getName()]<< "\t deuxieme " <<order[second->getName()];
    //std::cout<<" result = " << order[first->getName()] - order[second->getName()] <<std::endl;
    return order[first->getName()] - order[second->getName()];

}