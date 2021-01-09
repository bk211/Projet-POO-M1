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
    }else if(first->getValue() == second->getValue()){ // si les 2 cartes on la meme valeur
        return true;
    }else if(second->getCouleur() == "null"){
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
            std::string cardString = currentCard->getName() + "\t" + currentCard->getCouleur();
            availbleCardsString.push_back(cardString);
        }
    }
    
    return result;
}

void JouerCommand::playCard(int playedCardId){
    UnoCard* toBePlayedCard;
    // retrouver la bonne carte 
    for (int i = 0; i < gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->size(); i++){
        toBePlayedCard = dynamic_cast<UnoCard*>(gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->at(i));
        std::string cardString = toBePlayedCard->getName() + "\t" + toBePlayedCard->getCouleur();
        if(cardString == availbleCardsString[playedCardId]){    
            //retirer la carte de la main du joueur
            gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->draw(i);
            break;
        }
    }

    //mettre la carte sur la table et appliquer son effet
    dynamic_cast<UnoGameModel*>(gameModel)->table->addData(toBePlayedCard);
    if(toBePlayedCard->getType() == 0){// carte numerique, rien a faire
    }else if(toBePlayedCard->getName() == "Joker"){
        int couleur = gameController->askCommandString(couleurString);
        toBePlayedCard->changeColor(couleurString[couleur]);
    }else if(toBePlayedCard->getName() == "+4"){
        toBePlayedCard->changeColor(dynamic_cast<UnoCard*>(dynamic_cast<UnoGameModel*>(gameModel)->table->last())->getCouleur());
    }else if(toBePlayedCard->getName() == "Pass"){
        gameView->afficher("Une carte [Pass] a ete joue");
        gameView->afficher("Le tour du prochain joueur saute");
        gameModel->getPlayerManager()->setStep(2);
    }
    
    


    
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
    gameView->afficher("");
    
    int playedCardId = gameController->askCommandString(availbleCardsString);
    playCard(playedCardId);
    *actionEnCours = false;
}
