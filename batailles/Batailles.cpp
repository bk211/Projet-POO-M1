#include "batailles.hpp"

MyGameModel::MyGameModel()
{
}

MyGameModel::~MyGameModel()
{
}

void MyGameModel::startGame(){

}

void MyGameModel::countScore(){
    
}


void MyGameModel::pushDataFromStrLine(std::vector<std::string> line){
    
    //cout<<"Dealing with line content: ";
    //for (auto word : line){ std::cout<< word +", ";}
    //cout<<std::endl;
    //for (int i = 0; i < stoi(line[0]); i++){
    //    MyCard * result = new MyCard{line[1], line[2], line[3]};
        //cout<<"generated card: "<< result;
    //    data->addData(result);
    //}
}

void MyGameModel::initPlayers(){
    Player* p1 = new Player{"joueur 1",1};
    playerManager->addPlayer(p1);
}


Batailles::Batailles(){
    parseur.setFilename("BataillesConfig32.txt");
    gameModel.initGameData(parseur.get_lignes());
}

Batailles::~Batailles()
{
}