#include "Briscola.hpp"

JouerCommand::JouerCommand(BriscolaGameModel * gameModel, GameController * gameController, BriscolaGameView * gameView,bool *succeed)
:Command(gameModel, gameController, gameView), succeed(succeed)
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
        std::string cardString = toBePlayedCard->getAttribut(1);
        if(cardString == dynamic_cast<BriscolaGameModel *>(gameModel)->getPlayerManager()->getCurrentPlayer()->getHand()->at(playedCardId)->getAttribut(1)){    
            //retirer la carte de la main du joueur
            gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->draw(i);
            break;
        }
    }

    if((dynamic_cast<BriscolaGameModel *>(gameModel)->getTable()==nullptr)){
        dynamic_cast<BriscolaGameModel *>(gameModel)->setTable(toBePlayedCard);
        dynamic_cast<BriscolaGameModel *>(gameModel)->addPoints(std::stoi(toBePlayedCard->getAttribut(3)));
        
        return true;
    }
    else if(toBePlayedCard->getAttribut(0) == dynamic_cast<BriscolaGameModel *>(gameModel)->getAtout()->getAttribut(0)){
        //Si on pose une carte de la couleur de l'atout
        dynamic_cast<BriscolaGameModel *>(gameModel)->setTable(toBePlayedCard);
        dynamic_cast<BriscolaGameModel *>(gameModel)->addPoints(std::stoi(toBePlayedCard->getAttribut(3)));
        return true;
    }
    else if((dynamic_cast<BriscolaGameModel *>(gameModel)->getTable()->getAttribut(0)==toBePlayedCard->getAttribut(0))
    && (std::stoi(dynamic_cast<BriscolaGameModel *>(gameModel)->getTable()->getAttribut(2))<std::stoi(toBePlayedCard->getAttribut(2)))){
        dynamic_cast<BriscolaGameModel *>(gameModel)->setTable(toBePlayedCard);
        dynamic_cast<BriscolaGameModel *>(gameModel)->addPoints(std::stoi(toBePlayedCard->getAttribut(3)));
        return true;
    }else{
        dynamic_cast<BriscolaGameModel *>(gameModel)->addPoints(std::stoi(toBePlayedCard->getAttribut(3)));
        return false;
    }

}

void JouerCommand::run(){
    gameView->afficher("Quelle carte voulez vous jouer?");
    gameView->afficher("");
    std::vector<std::string> ensCarteString;
    for (int i = 0; i < gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->size(); i++){
        Carte* currentCard = dynamic_cast<Carte*>(gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->at(i));
        std::string cardString =currentCard->getAttribut(1);
        ensCarteString.push_back(cardString);
    }
    int playedCardId = gameController->askCommandString(ensCarteString);
    *succeed = playCard(playedCardId);
}