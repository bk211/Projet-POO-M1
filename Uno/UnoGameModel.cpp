#include "Uno.hpp"

UnoGameModel::UnoGameModel()
{
    
}

UnoGameModel::~UnoGameModel()
{
}


void UnoGameModel::countScore()
{
}

void UnoGameModel::pushDataFromStrLine(std::vector<std::string> line)
{
    /*
    std::cout << "Dealing with line content: ";
    for (auto word : line) std::cout << word + ", ";
    std::cout << std::endl;
    */

    int nombre = std::stoi(line[0]);
    int value = std::stoi(line[2]);
    int type = std::stoi(line[3]);
    auto description = line[5];
    for (int i = 0; i < nombre; i++)
    {
        int nbCouleur = std::stoi(line[4]);
        for (int i = 0; i < nbCouleur; i++)
        {
            auto couleur = line[6 + i];
            UnoCard *result = new UnoCard(line[1], type, couleur, value, description);

            //decommenter ici pour voir les cartes;
            //std::cout << *result;
            //std::cout << "\n";

            data->addData(result);
        }
    }    
}

void UnoGameModel::startGame()
{                    //debut de la partie, distribuer les cartes
    data->shuffle(); // melanger les cartes;
    std::cout<<"--------------------------start game ----------------------------\n";
    int nbCarte = 7;
    for (Player *player : playerManager->players)
    {
        for (int i = 0; i < nbCarte; i++){ 
            player->getHand().addData(data->draw());
        }
    }
}

void UnoGameModel::initPlayers()
{
    Player *p1 = new Player{"joueur 1", 1};
    Player *p2 = new Player{"joueur 2", 1};
    playerManager->addPlayer(p1);
    playerManager->addPlayer(p2);
    // TODO()
}

bool UnoGameModel::isGameOver()
{ // verifie les conditions de fin de jeu
    // TODO()
    return false;
}
