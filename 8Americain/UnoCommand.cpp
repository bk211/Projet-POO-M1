#include "Uno.hpp"

UnoCommand::UnoCommand(UnoGameModel * gameModel, GameController * gameController, UnoGameView * gameView, bool *actionEnCours)
:Command(gameModel, gameController, gameView), actionEnCours(actionEnCours)
{
}

UnoCommand::~UnoCommand()
{
}


void UnoCommand::run(){
    gameView->afficher("Vous avez crié UNO");
    if(gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->size() == 1){
        gameView->afficher("Il ne vous reste plus qu'une seule carte WOW SO STRONG VERY COOL");
    }else{
        gameView->afficher("Mais il ne s'est rien passé");
    }
}
