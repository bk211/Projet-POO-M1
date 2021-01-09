#include "Base.hpp"

BaseGameModel::BaseGameModel()
{
}

BaseGameModel::~BaseGameModel()
{
}

void BaseGameModel::startGame(){
    //TODO()
}

void BaseGameModel::countScore(){
    //TODO()
}


void BaseGameModel::pushDataFromStrLine(std::vector<std::string> line){
    for (int i = 0; i < stoi(line[0]); i++){
        Carte * result = new Carte(line[1]);
        result->addAttribut(line[2]);
        result->addAttribut(line[3]);
        data->addData(result);
    }
}

void BaseGameModel::initPlayers(){
    Player* p1 = new Player{"joueur 1",1};
    Player* p2 = new Player{"joueur 2",1};
    playerManager->addPlayer(p1);
    playerManager->addPlayer(p2);
    // TODO()
}

bool BaseGameModel::isGameOver(){ // verifie les conditions de fin de jeu
    // TODO()
    return false;
}


BaseJeu::BaseJeu():parseur(Parseur("ConfigCarte52.txt", 4)){
    //parseur.print_lines();
    gameModel.data = new CollectionCarte();
    gameModel.initGameData(parseur.get_lignes());
    gameModel.playerManager = new PlayerManager();
    gameModel.initPlayers();
}

BaseJeu::~BaseJeu()
{
}

void BaseJeu::start(){
    gameModel.startGame();// distribuer les cartes au joueurs
    
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