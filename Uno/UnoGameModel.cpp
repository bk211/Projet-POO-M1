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
    std::cout<<"Dealing with line content: ";
    for (auto word : line){ std::cout<< word +", ";}
    std::cout<<std::endl;
    

    for (int i = 0; i < std::stoi(line[0]); i++){
        UnoCard * result = new UnoCard(line[1],std::stoi(line[2]),line[3]);
        std::cout<<*result;
        std::cout<<"\n";
    }
    
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