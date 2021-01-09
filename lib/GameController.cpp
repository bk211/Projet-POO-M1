#include "../libCardGame.hpp"


GameController::GameController(/* args */)
{
}

GameController::~GameController()
{
}


std::string GameController::getUserInput(){
    std::string userAnswer;
    std::cin >>userAnswer;
    return userAnswer;
}

std::string GameController::askUser(std::string question){
    std::cout<<question<<std::endl;
    std::string userAnswer;
    std::cin >>userAnswer;
    return userAnswer;
}