#include "Uno.hpp"

JouerCommand::JouerCommand(GameModel * gameModel, GameController * gameController, GameView * gameView,bool *actionEnCours)
:Command(gameModel, gameController, gameView), actionEnCours(actionEnCours)
{
}

JouerCommand::~JouerCommand()
{
}

void JouerCommand::run()
{

    *actionEnCours = false;
}
