#include "Uno.hpp"

UnoCommand::UnoCommand(GameModel * gameModel, GameController * gameController, GameView * gameView)
:Command(gameModel, gameController, gameView)
{
}

UnoCommand::~UnoCommand()
{
}


void UnoCommand::run()
{
}
