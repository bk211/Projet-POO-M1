#include "Uno.hpp"

Uno::Uno():parseur(Parseur("UnoConfig.txt",42,false)){
    //parseur.print_lines();//affiche toutes les lignes lu par le parseur
    gameModel.data = new CollectionCarte(); 
    gameModel.initGameData(parseur.get_lignes());
    //gameModel.playerManager = new PlayerManager();
    //gameModel.initPlayers();
}

Uno::~Uno()
{
}

void Uno::start(){
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