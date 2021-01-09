#include "Uno.hpp"

JouerCommand::JouerCommand(GameModel * gameModel, GameController * gameController, GameView * gameView)
:Command(gameModel, gameController, gameView)
{
}

JouerCommand::~JouerCommand()
{
}

void JouerCommand::run()
{
}
