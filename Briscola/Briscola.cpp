#include "Briscola.hpp"

BriscolaGameModel::BriscolaGameModel()
{
}

BriscolaGameModel::~BriscolaGameModel()
{
}

void BriscolaGameModel::startGame(){
    data->shuffle();
    while (!data->isEmpty()) {//tant que la pioche n'est pas vide

    }
    //TODO()
}

void BriscolaGameModel::countScore(){
    //TODO()
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
    Player* p1 = new Player{"joueur 1",1};
    Player* p2 = new Player{"joueur 2",1};
    playerManager->addPlayer(p1);
    playerManager->addPlayer(p2);
    // TODO()
}

bool BriscolaGameModel::isGameOver(){ // verifie les conditions de fin de jeu
    // TODO()
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