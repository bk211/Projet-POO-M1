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

std::string GameController::askCommandString(std::vector<std::string> commandStrings){    
    std::cout<<"Voici les commandes disponibles:" <<std::endl;
    for (size_t i = 0; i < commandStrings.size(); i++){
        std::cout<< i <<" :"<< commandStrings[i] <<std::endl;
    }
    std::string userInput = askUser("Merci de saisir un numero de commande");
    int userChoice;
    try{
        userChoice = std::stoi(userInput);
        if(userChoice>=0 && userChoice < (int)commandStrings.size()){
            return commandStrings[userChoice];
        }
    }
    catch(const std::exception& e){
        std::cout<<"Merci de saisir une entree valide"<<std::endl;
        return askCommandString(commandStrings);
    }

    return askCommandString(commandStrings);
}
