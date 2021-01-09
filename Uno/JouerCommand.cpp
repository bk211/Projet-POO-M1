#include "Uno.hpp"

JouerCommand::JouerCommand(UnoGameModel * gameModel, GameController * gameController, UnoGameView * gameView,bool *actionEnCours)
:Command(gameModel, gameController, gameView), actionEnCours(actionEnCours)
{
}

JouerCommand::~JouerCommand()
{
}





/*
    * true -> si on peut jouer first au dessus de second
    * false -> sinon
*/
bool JouerCommand::playable(UnoCard* first, UnoCard* second)const{
    if(first->getName() == "Joker" || first->getName() == "+4"){//cas specifiques
        return true;
    }else if (first->getCouleur() == second->getCouleur()){ // si 2 cartes de meme couleurs
        return true;
    }else if(first->getValue() == second->getValue()){
        return true;
    }
    
    return false;
}

int JouerCommand::foundPlayableCardCount()const{
    int result = 0;
    CollectionCarte * cartes = gameModel->getPlayerManager()->getCurrentPlayer()->getHand();
    UnoCard * carteTable = dynamic_cast<UnoCard*>(dynamic_cast<UnoGameModel*>(gameModel)->table->last());

    for (int i = 0; i < gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->size(); i++){
        if(playable(dynamic_cast<UnoCard*>(gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->at(i)), carteTable)){
            result++;
        }
    }
    
    return result;
}


void JouerCommand::run()
{
    int playableCardCount = foundPlayableCardCount();
    gameView->afficher("Vous pouvez jouer " + std::to_string(playableCardCount) +" cartes");
    if(playableCardCount == 0){
        gameView->afficher("Vous n'avez aucun carte jouable");
        return;
    }
    gameView->afficher("Quel carte voulez vous jouer?");
    std::vector<std::string> availble = {"dwa", "dawd"};
    std::cout<<"djaiwodjawodijawoda";
    std::cout<< gameModel->getPlayerManager()->getCurrentPlayer()->getHand()->toString();
    //->getCurrentPlayer()->getHand().toString();
    std::cout<<"djaiwodjawodijawoda";

    /*for (int i = 0; i < gameModel->getPlayerManager()->getCurrentPlayer()->getHand().size(); i++){
        std::string name =gameModel->getPlayerManager()->getCurrentPlayer()->getHand().at(i)->getName(); 
        availble.push_back(name);
    }
    */
    

    gameController->askCommandString(availble);
    gameController->askUser("sdadw? ");
    std::cout<<"out ==========================\n";


    *actionEnCours = false;
}
