#include "Uno.hpp"

PiocherCommand::PiocherCommand(GameModel * gameModel, GameController * gameController, GameView * gameView)
:Command(gameModel, gameController, gameView)
{
}

PiocherCommand::~PiocherCommand()
{
}


void PiocherCommand::run()
{
}
