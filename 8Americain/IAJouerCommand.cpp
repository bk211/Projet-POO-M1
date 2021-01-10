#include "Huit.hpp"

IAJouerCommand::IAJouerCommand(HuitGameModel * gameModel, GameController * gameController, HuitGameView * gameView,bool *actionEnCours)
:JouerCommand(gameModel, gameController, gameView, actionEnCours)
{
}

IAJouerCommand::~IAJouerCommand()
{
}

/**
 * retourne aleatoirement un entier au hasard compris entre 0 et number exclus 
*/
int playRandom(int number){
    std::srand(std::time(0));
    int result = std::rand() % number;
    return result;    

}


void IAJouerCommand::playCard(int playedCardId){
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
    

    int couleur = playRandom(4); 
    int currentPenalty = dynamic_cast<HuitGameModel*>(gameModel)->currentPenalty;
    //mettre la carte sur la table et appliquer son effet
    dynamic_cast<HuitGameModel*>(gameModel)->table->addData(toBePlayedCard);
    if(toBePlayedCard->getType() == 0){
        if(currentPenalty != 0){
            gameView->afficher("Vous avez pris la penalite");
            gameView->afficher("Vous allez piocher " + std::to_string(currentPenalty)+ " cartes");
            dynamic_cast<HuitGameModel*>(gameModel)->applyPenalty();
        }
    }else if(toBePlayedCard->getName() == "8"){// 8-> changement de couleur
        toBePlayedCard->changeColor(couleurString[couleur]);
    }else if (toBePlayedCard->getName() == "2"){
        dynamic_cast<HuitGameModel*>(gameModel)->currentPenalty +=2;
        gameView->afficher("Une penalite de +2 a ete ajoute");
        gameView->afficher("Une penalite cummule vaut maintenant: " + std::to_string(dynamic_cast<HuitGameModel*>(gameModel)->currentPenalty));

    }else if(toBePlayedCard->getName() == "Valet")
    {
        gameView->afficher("Une carte [Valet] a ete joue");
        gameView->afficher("Le tour du prochain joueur saute");
        gameModel->getPlayerManager()->setStep(2);
        
        if(currentPenalty != 0){
            gameView->afficher("Vous avez pris la penalite");
            gameView->afficher("Vous allez piocher " + std::to_string(currentPenalty)+ " cartes");
            dynamic_cast<HuitGameModel*>(gameModel)->applyPenalty();
        }

    }else if(toBePlayedCard->getName() == "As")
    {
        gameModel->getPlayerManager()->swapDirection();
        if(currentPenalty != 0){
            gameView->afficher("Vous avez pris la penalite");
            gameView->afficher("Vous allez piocher " + std::to_string(currentPenalty)+ " cartes");
            dynamic_cast<HuitGameModel*>(gameModel)->applyPenalty();
        }
        
    }else if(toBePlayedCard->getName() == "Joker")
    {
        // penalite +4
        dynamic_cast<HuitGameModel*>(gameModel)->currentPenalty +=4;
        gameView->afficher("Une penalite de +4 a ete ajoute");
        gameView->afficher("Une penalite cummule vaut maintenant: " + std::to_string(dynamic_cast<HuitGameModel*>(gameModel)->currentPenalty));
    }
    


    
}
void IAJouerCommand::run()
{
    int playableCardCount = foundPlayableCards();
    gameView->afficher("Vous pouvez jouer " + std::to_string(playableCardCount) +" cartes");
    if(playableCardCount == 0){
        gameView->afficher("Vous n'avez aucun carte jouable");
        PiocherCommand * pioche = new PiocherCommand((HuitGameModel*)gameModel, gameController, (HuitGameView*)gameView, actionEnCours);
        pioche->run();
        delete pioche;
        return;
    }
    gameView->afficher("Quel carte voulez vous jouer?");
    // joueur au hasard parmi les cartes jouables
    int playedCardId = playRandom(playableCardCount);
    playCard(playedCardId);
    *actionEnCours = false;

}