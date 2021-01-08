#include "../libCardGame.hpp"

Command::Command(GameModel * gm, GameController * gc, GameView * gv)
: gameModel(gm), gameController(gc), gameView(gv)
{
}

Command::~Command()
{
}
