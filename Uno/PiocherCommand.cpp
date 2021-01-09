#include "Uno.hpp"

PiocherCommand::PiocherCommand(GameModel * gameModel, GameController * gameController, GameView * gameView, bool *actionEnCours)
:Command(gameModel, gameController, gameView), actionEnCours(actionEnCours)
{
}

PiocherCommand::~PiocherCommand()
{
}


void PiocherCommand::run()
{
    std::cout<<"dans run du PiocherCommand"<<std::endl;
    
    *actionEnCours = false;
}
