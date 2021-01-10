#include "Huit.hpp"

PiocherCommand::PiocherCommand(HuitGameModel * gameModel, GameController * gameController, HuitGameView * gameView, bool *actionEnCours)
:Command(gameModel, gameController, gameView), actionEnCours(actionEnCours)
{
}

PiocherCommand::~PiocherCommand()
{
}


void PiocherCommand::run()
{
    HuitCard * pioche = dynamic_cast<HuitCard*>(gameModel->getDataCollection()->drawRandom());
    gameView->afficher("Vous venez de piocher la carte suivante :");
    gameView->afficher(pioche->toStringLess());
    gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->addData(pioche);
    gameView->afficher("Voici votre nouvel main: ");
    dynamic_cast<HuitGameView*>(gameView)->afficherPlayersCollection(gameModel->getPlayerManager()->getCurrentPlayer()->getHand());
    *actionEnCours = false;
}
