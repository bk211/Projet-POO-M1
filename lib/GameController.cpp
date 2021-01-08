#include "../libCardGame.hpp"


GameController::GameController(/* args */)
{
}

GameController::~GameController()
{
}


std::string GameController::getUserInput(){
    std::string result;
    std::cin >>result;
    return result;
}