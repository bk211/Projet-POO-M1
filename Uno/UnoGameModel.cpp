#include "Uno.hpp"

UnoGameModel::UnoGameModel()
{
}

UnoGameModel::~UnoGameModel()
{
}

void UnoGameModel::startGame(){
    //TODO()
}

void UnoGameModel::countScore(){
    //TODO()
}


void UnoGameModel::pushDataFromStrLine(std::vector<std::string> line){
    
}

void UnoGameModel::initPlayers(){
    Player* p1 = new Player{"joueur 1",1};
    Player* p2 = new Player{"joueur 2",1};
    playerManager->addPlayer(p1);
    playerManager->addPlayer(p2);
    // TODO()
}

bool UnoGameModel::isGameOver(){ // verifie les conditions de fin de jeu
    // TODO()
    return false;
}