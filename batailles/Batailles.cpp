#include "batailles.hpp"

MyGameModel::MyGameModel()
{
}

MyGameModel::~MyGameModel()
{
}

void MyGameModel::startGame(){
    
    data->shuffle();
    while (!data->isEmpty()){//tant que le deck n'est pas vide
        //tirer une carte, la donner au joueur qui joue, puis passer au joueur suivant
        //std::cout<<"current player is : "<<playerManager->currentPlayer<<std::endl;
        playerManager->getCurrentPlayer()->getHand().addData(data->draw());
        playerManager->rotateToNext();   
        //std::cout<<"next player is : "<<playerManager->currentPlayer<<std::endl;
    }
}

void MyGameModel::countScore(){

}


void MyGameModel::pushDataFromStrLine(std::vector<std::string> line){
    
    //cout<<"Dealing with line content: ";
    //for (auto word : line){ std::cout<< word +", ";}
    //cout<<std::endl;
    
    // Creer ici votre class de carte
    for (int i = 0; i < stoi(line[0]); i++){
        Carte * result = new Carte(line[1]);
        result->addAttribut(line[2]);
        result->addAttribut(line[3]);
        data->addData(result);
    }
}

void MyGameModel::initPlayers(){
    Player* p1 = new Player{"joueur 1",1};
    Player* p2 = new Player{"joueur 2",1};
    playerManager->addPlayer(p1);
    playerManager->addPlayer(p2);
}

bool MyGameModel::isGameOver(){ // verifie les conditions de fin de jeu
    for (Player * p : playerManager->players){
        if(p->getHand().size() > 32)
            return true;
    }

    return false;
    
}


Batailles::Batailles(): parseur(Parseur("BataillesConfig32.txt", 4)){
    //parseur.print_lines();
    gameModel.data = new CollectionCarte();
    gameModel.initGameData(parseur.get_lignes());
    gameModel.playerManager = new PlayerManager();
    gameModel.initPlayers();
    std::cout<<gameModel.playerManager->getCurrentPlayer()->toString();

}

Batailles::~Batailles()
{
}

void Batailles::start(){
    gameModel.startGame();// distribuer les cartes au joueurs
    //decommenter pour voir la distribution
    /*
    std::cout<<gameModel.playerManager->getPlayer(0)->getHand().toString();
    std::cout<<"===========================\n";
    std::cout<<gameModel.playerManager->getPlayer(1)->getHand().toString();
    */

    std::vector<Carte *> stack;
    int diff;
    
    std::vector<Carte *> stack_p1;
    std::vector<Carte *> stack_p2;

    std::cout<<"\nDebut du jeu ====================================================== \n";
    while(!gameModel.isGameOver()){
        Player * p1 = gameModel.getPlayerManager()->getPlayer(0);
        Player * p2 = gameModel.getPlayerManager()->getPlayer(1);
        if(p1->getHand().isEmpty() ||p2->getHand().isEmpty()) break;

        gameView.afficher(p1->getName()+" has draw :"); 
        Carte * c1 = p1->getHand().drawRandom();
        stack.push_back(c1);
        gameView.afficher(c1->getName()); 
        
        gameView.afficher(p2->getName()+" has draw :");
        Carte * c2 = p2->getHand().drawRandom();
        stack.push_back(c2);
        gameView.afficher(c2->getName()); 

        std::cout<<"\ncomparaison en cours ...\n";
        diff = compare(c1,c2);
        if(diff == 0){// bataille
            std::cout<<"Batailles !!"<<std::endl;
        }else if(diff >0){
            gameView.afficher(p1->getName()+" a gagne\n"); 
            gameModel.TakeStack(stack, p1);
        }else{
            gameView.afficher(p2->getName()+" a gagne\n"); 
            gameModel.TakeStack(stack, p2);
        }
        
        gameView.afficher(p1->getName()+" possede :" + std::to_string(gameModel.playerManager->getPlayer(0)->getHand().size()) +" cartes\n"); 
        gameView.afficher(p2->getName()+" possede :" + std::to_string(gameModel.playerManager->getPlayer(1)->getHand().size()) +" cartes\n"); 
            
        //std::string userInput = gameController.getUserInput(); // verifier si l'entree est valide
        std::cout<<"====================================================== \n";
        std::getchar(); //faire une pause

    }

    std::cout<<"GAME OVER\n";
    
}

/* compare 2 cartes:
    -> negatif si first < second
    -> positif si first >= second
*/
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


void MyGameModel::TakeStack(std::vector<Carte *>& stack, Player * player){
    for (Carte * carte : stack){
        player->getHand().insertFront(carte);
    }
    stack.clear();
}
