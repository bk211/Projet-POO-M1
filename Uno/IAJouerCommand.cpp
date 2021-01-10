#include "Uno.hpp"

IAJouerCommand::IAJouerCommand(UnoGameModel * gameModel, GameController * gameController, UnoGameView * gameView,bool *actionEnCours)
:JouerCommand(gameModel, gameController, gameView, actionEnCours)
{
}

IAJouerCommand::~IAJouerCommand()
{
}

void IAJouerCommand::run()
{
    int playableCardCount = foundPlayableCards();
    gameView->afficher("Vous pouvez jouer " + std::to_string(playableCardCount) +" cartes");
    if(playableCardCount == 0){
        gameView->afficher("Vous n'avez aucun carte jouable");
        PiocherCommand * pioche = new PiocherCommand((UnoGameModel*)gameModel, gameController, (UnoGameView*)gameView, actionEnCours);
        pioche->run();
        delete pioche;
        return;
    }
    gameView->afficher("Quel carte voulez vous jouer?");
    
    int playedCardId = gameController->askCommandString(availbleCardsString);
    playCard(playedCardId);
    *actionEnCours = false;
}
