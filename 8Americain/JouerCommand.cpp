#include "Huit.hpp"

JouerCommand::JouerCommand(HuitGameModel * gameModel, GameController * gameController, HuitGameView * gameView,bool *actionEnCours)
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
bool JouerCommand::playable(HuitCard* first, HuitCard* second)const{
    if(first->getName() == "Joker" || first->getName() == "+4"){//cas specifiques
        return true;
    }else if (first->getCouleur() == second->getCouleur()){ // si 2 cartes de meme couleurs
        return true;
    }else if(first->getValue() == second->getValue()){ // si les 2 cartes on la meme valeur
        return true;
    }else if(second->getCouleur() == "null"){
        return true;
    }else if(first->getName() == "+2" && second->getName() == "+2"){
        return true;
    }
    
    
    return false;
}

int JouerCommand::foundPlayableCards(){
    int result = 0;

    HuitCard * carteTable = dynamic_cast<HuitCard*>(dynamic_cast<HuitGameModel*>(gameModel)->table->last());
    for (int i = 0; i < gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->size(); i++){
        HuitCard* currentCard = dynamic_cast<HuitCard*>(gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->at(i));
        if(playable( currentCard, carteTable)){
            result++;
            std::string cardString = currentCard->getName() + "\t" + currentCard->getCouleur();
            availbleCardsString.push_back(cardString);
        }
    }
    
    return result;
}

void JouerCommand::playCard(int playedCardId){
    HuitCard* toBePlayedCard;
    // retrouver la bonne carte 
    for (int i = 0; i < gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->size(); i++){
        toBePlayedCard = dynamic_cast<HuitCard*>(gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->at(i));
        std::string cardString = toBePlayedCard->getName() + "\t" + toBePlayedCard->getCouleur();
        if(cardString == availbleCardsString[playedCardId]){    
            //retirer la carte de la main du joueur
            gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->draw(i);
            break;
        }
    }

    int couleur;
    int currentPenalty = dynamic_cast<HuitGameModel*>(gameModel)->currentPenalty;
    //mettre la carte sur la table et appliquer son effet
    dynamic_cast<HuitGameModel*>(gameModel)->table->addData(toBePlayedCard);
    if(toBePlayedCard->getType() == 0){
        if(currentPenalty != 0){
            gameView->afficher("Vous avez pris la penalite");
            gameView->afficher("Vous allez piocher " + std::to_string(currentPenalty)+ " cartes");
            dynamic_cast<HuitGameModel*>(gameModel)->applyPenalty();
        }
    }else if(toBePlayedCard->getName() == "Joker"){
        couleur = gameController->askCommandString(couleurString);
        toBePlayedCard->changeColor(couleurString[couleur]);
    }else if (toBePlayedCard->getName() == "+2"){
        dynamic_cast<HuitGameModel*>(gameModel)->currentPenalty +=2;
        gameView->afficher("Une penalite de +2 a ete ajoute");
        gameView->afficher("Une penalite cummule vaut maintenant: " + std::to_string(dynamic_cast<HuitGameModel*>(gameModel)->currentPenalty));

    }else if(toBePlayedCard->getName() == "Pass")
    {
        gameView->afficher("Une carte [Pass] a ete joue");
        gameView->afficher("Le tour du prochain joueur saute");
        gameModel->getPlayerManager()->setStep(2);
        
        if(currentPenalty != 0){
            gameView->afficher("Vous avez pris la penalite");
            gameView->afficher("Vous allez piocher " + std::to_string(currentPenalty)+ " cartes");
            dynamic_cast<HuitGameModel*>(gameModel)->applyPenalty();
        }

    }else if(toBePlayedCard->getName() == "Inv")
    {
        gameModel->getPlayerManager()->swapDirection();
        if(currentPenalty != 0){
            gameView->afficher("Vous avez pris la penalite");
            gameView->afficher("Vous allez piocher " + std::to_string(currentPenalty)+ " cartes");
            dynamic_cast<HuitGameModel*>(gameModel)->applyPenalty();
        }
        
    }else if(toBePlayedCard->getName() == "+4")
    {
        // penalite +4
        dynamic_cast<HuitGameModel*>(gameModel)->currentPenalty +=4;
        gameView->afficher("Une penalite de +4 a ete ajoute");
        gameView->afficher("Une penalite cummule vaut maintenant: " + std::to_string(dynamic_cast<HuitGameModel*>(gameModel)->currentPenalty));
        // change ou non la couleur
        couleur = gameController->askCommandString(couleurString);
        toBePlayedCard->changeColor(couleurString[couleur]);
        toBePlayedCard->changeColor(dynamic_cast<HuitCard*>(dynamic_cast<HuitGameModel*>(gameModel)->table->last())->getCouleur());
        //le prochaine pass son tour
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
