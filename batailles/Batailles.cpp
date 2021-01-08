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
    while(!gameModel.isGameOver()){

        
        std::cout<<" round of player : " << gameModel.playerManager->currentPlayer<<std::endl;
        gameView.afficher("afficher la main du joueur :"); // affichage a faire
        std::string userInput = gameController.getUserInput(); // verifier si l'entree est valide
        gameModel.playerManager->rotateToNext();
        
    }
    
}