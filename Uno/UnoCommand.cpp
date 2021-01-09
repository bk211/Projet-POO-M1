#include "Uno.hpp"

UnoCommand::UnoCommand(GameModel * gameModel, GameController * gameController, GameView * gameView, bool *actionEnCours)
:Command(gameModel, gameController, gameView), actionEnCours(actionEnCours)
{
}

UnoCommand::~UnoCommand()
{
}


void UnoCommand::run(){
    gameView->afficher("Vous avez crié UNO");
    gameView->afficher("Mais il ne s'est rien passé");
}
