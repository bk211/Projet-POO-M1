#include "Uno.hpp"

PiocherCommand::PiocherCommand(UnoGameModel * gameModel, GameController * gameController, UnoGameView * gameView, bool *actionEnCours)
:Command(gameModel, gameController, gameView), actionEnCours(actionEnCours)
{
}

PiocherCommand::~PiocherCommand()
{
}


void PiocherCommand::run()
{
    UnoCard * pioche = dynamic_cast<UnoCard*>(gameModel->getDataCollection()->drawRandom());
    gameView->afficher("Vous venez de piocher la carte suivante :");
    gameView->afficher(pioche->toStringLess());
    gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->addData(pioche);

    if(dynamic_cast<UnoGameModel*>(gameModel)->currentPenalty != 0){
            gameView->afficher("Vous avez pris la penalite");
            gameView->afficher("Vous allez piocher " + std::to_string(dynamic_cast<UnoGameModel*>(gameModel)->currentPenalty)+ " cartes");
            dynamic_cast<UnoGameModel*>(gameModel)->applyPenalty();
    }

    gameView->afficher("Voici votre nouvel main: ");
    dynamic_cast<UnoGameView*>(gameView)->afficherPlayersCollection(gameModel->getPlayerManager()->getCurrentPlayer()->getHand());
    *actionEnCours = false;
}
