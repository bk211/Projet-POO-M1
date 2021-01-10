#include "Huit.hpp"

HuitCommand::HuitCommand(HuitGameModel * gameModel, GameController * gameController, HuitGameView * gameView, bool *actionEnCours)
:Command(gameModel, gameController, gameView), actionEnCours(actionEnCours)
{
}

HuitCommand::~HuitCommand()
{
}


void HuitCommand::run(){
    gameView->afficher("Vous avez crié Huit");
    if(gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->size() == 1){
        gameView->afficher("Il ne vous reste plus qu'une seule carte WOW SO STRONG VERY COOL");
    }else{
        gameView->afficher("Mais il ne s'est rien passé");
    }
}
