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

void BriscolaGameModel::pushDataFromStrLine(std::vector<std::string> line){
    Carte* result = new Carte(line[0]); // valeur de la carte ( de 1 a 10 )
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
    gameModel.initPlayers();
}

Briscola::~Briscola()
{
}

void Briscola::start(){
    gameModel.startGame();// distribuer les cartes au joueurs + atout
    Player * winnerManche = gameModel.getPlayerManager()->getCurrentPlayer();

    while (!gameModel.data->isEmpty()){

        Player * player = winnerManche;
        for(int i=0;i<gameModel.getPlayerManager()->nbPlayers();i++){
            gameView.afficher("==============================================\n");
            gameView.afficher("C'est au tour de : "+ player->getName());
            gameView.afficherPlayersCollection(player->getHand());
            if(i==0){
                gameView.afficher("Vous etes le gagnant de la derniere manche, veuillez poser la premiere carte :");
            }else{
                gameView.afficher("La carte actuellement mise sur la table est :");
                gameView.afficher(gameModel.table->toString());
            }
        }
        bool actionEnCours = true;
        while(actionEnCours){
            gameView.afficher("==============================================\n");
            gameView.afficher("C'est au tour de : "+ player->getName());
            gameView.afficherPlayersCollection(player->getHand());
            gameView.afficher("La carte actuellement mise sur la table est :");
        }





    }




    
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