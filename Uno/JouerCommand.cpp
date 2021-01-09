#include "Uno.hpp"

JouerCommand::JouerCommand(UnoGameModel * gameModel, GameController * gameController, UnoGameView * gameView,bool *actionEnCours)
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
