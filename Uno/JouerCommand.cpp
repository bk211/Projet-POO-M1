#include "Uno.hpp"

JouerCommand::JouerCommand(UnoGameModel * gameModel, GameController * gameController, UnoGameView * gameView,bool *actionEnCours)
:Command(gameModel, gameController, gameView), actionEnCours(actionEnCours)
{
}

JouerCommand::~JouerCommand()
{
}





/*
    * true -> si on peut jouer first au dessus de second
    * false -> sinon
*/
bool JouerCommand::playable(UnoCard* first, UnoCard* second)const{
    if(first->getName() == "Joker" || first->getName() == "+4"){//cas specifiques
        return true;
    }else if (first->getCouleur() == second->getCouleur()){ // si 2 cartes de meme couleurs
        return true;
    }else if(first->getValue() == second->getValue()){
        return true;
    }
    
    return false;
}

int JouerCommand::foundPlayableCards(){
    int result = 0;

    UnoCard * carteTable = dynamic_cast<UnoCard*>(dynamic_cast<UnoGameModel*>(gameModel)->table->last());
    for (int i = 0; i < gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->size(); i++){
        UnoCard* currentCard = dynamic_cast<UnoCard*>(gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->at(i));
        if(playable( currentCard, carteTable)){
            result++;
            availbleCardsString.push_back(currentCard->getName());
        }
    }
    
    return result;
}


void JouerCommand::run()
{
    int playableCardCount = foundPlayableCards();
    gameView->afficher("Vous pouvez jouer " + std::to_string(playableCardCount) +" cartes");
    if(playableCardCount == 0){
        gameView->afficher("Vous n'avez aucun carte jouable");
        return;
    }
    gameView->afficher("Quel carte voulez vous jouer?");
    std::string playedCard = gameController->askCommandString(availbleCardsString);

    std::cout<<"out ==========================\n";
    *actionEnCours = false;
}
