#include "Briscola.hpp"

JouerCommand::JouerCommand(BriscolaGameModel * gameModel, GameController * gameController, BriscolaGameView * gameView)
:Command(gameModel, gameController, gameView)
{
}

JouerCommand::~JouerCommand()
{
}

bool JouerCommand::playCard(int playedCardId){
    Carte * toBePlayedCard;
    //On cherche la bonne carte
    for (int i = 0; i < gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->size(); i++){
        toBePlayedCard = dynamic_cast<Carte*>(gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->at(i));
        std::string cardString = toBePlayedCard->getAttribut(2);
        if(cardString == dynamic_cast<BriscolaGameModel *>(gameModel)->getPlayerManager()->getCurrentPlayer()->getHand()->at(playedCardId)->getAttribut(2)){    
            //retirer la carte de la main du joueur
            gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->draw(i);
            break;
        }
    }
    if((dynamic_cast<BriscolaGameModel *>(gameModel)->getTable()==nullptr)){
        dynamic_cast<BriscolaGameModel *>(gameModel)->setTable(toBePlayedCard);
        dynamic_cast<BriscolaGameModel *>(gameModel)->addPoints(std::stoi(toBePlayedCard->getAttribut(4)));
        return true;
    }
    else if(toBePlayedCard->getAttribut(1) == dynamic_cast<BriscolaGameModel *>(gameModel)->getAtout()->getAttribut(1)){
        //Si on pose une carte de la couleur de l'atout
        dynamic_cast<BriscolaGameModel *>(gameModel)->setTable(toBePlayedCard);
        dynamic_cast<BriscolaGameModel *>(gameModel)->addPoints(std::stoi(toBePlayedCard->getAttribut(4)));
        return true;
    }
    else if((dynamic_cast<BriscolaGameModel *>(gameModel)->getTable()->getAttribut(1)==toBePlayedCard->getAttribut(1))
    && (std::stoi(dynamic_cast<BriscolaGameModel *>(gameModel)->getTable()->getAttribut(3))<std::stoi(toBePlayedCard->getAttribut(3)))){
        dynamic_cast<BriscolaGameModel *>(gameModel)->setTable(toBePlayedCard);
        dynamic_cast<BriscolaGameModel *>(gameModel)->addPoints(std::stoi(toBePlayedCard->getAttribut(4)));
        return true;
    }else{
        dynamic_cast<BriscolaGameModel *>(gameModel)->addPoints(std::stoi(toBePlayedCard->getAttribut(4)));
        return false;
    }

}