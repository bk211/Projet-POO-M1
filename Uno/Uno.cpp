#include "Uno.hpp"

Uno::Uno():parseur(Parseur("UnoConfig.txt",42,false)){
    //parseur.print_lines();//affiche toutes les lignes lu par le parseur
    gameModel.data = new CollectionCarte(); 
    gameModel.table = new CollectionCarte();
    gameModel.initGameData(parseur.get_lignes());
    gameModel.playerManager = new PlayerManager();

    gameModel.gameView = &gameView;
    gameModel.gameController = &gameController;
    gameModel.initPlayers();

}

Uno::~Uno()
{
}

void Uno::start(){
    gameModel.startGame();// distribuer les cartes au joueurs

    while (!gameModel.isGameOver()){
        if(gameModel.data->size() < 10 || gameModel.currentPenalty > gameModel.data->size()){
            //si la pioche est presque vide ou bientot vide
            gameModel.reFill();
        }

        Player * player = gameModel.getPlayerManager()->getCurrentPlayer();
        bool actionEnCours = true;
        while (actionEnCours){
            gameView.afficher("==============================================\n");
            gameView.afficher("C'est au tour de : "+ player->getName());
            gameView.afficherPlayersCollection(player->getHand());
            gameView.afficher("La carte actuellement mise sur la table est :");
            gameView.afficher(dynamic_cast<UnoCard*>(gameModel.table->last())->toStringLess());
            
            gameView.afficher("Quelle est votre action? ");

            Command * command;
            if(player->getClassId() == 0){// joueur IA
                int userAction = gameController.askCommandString(gameModel.commandStrings);
                // switch pour savoir quel command executer
                if(userAction == 0){
                    command = new JouerCommand(&gameModel, &gameController, &gameView, &actionEnCours);
                }else if(userAction == 1){
                    command = new PiocherCommand(&gameModel, &gameController, &gameView, &actionEnCours);
                }else if(userAction == 2){
                    command = new UnoCommand(&gameModel, &gameController, &gameView, &actionEnCours);
                }
            }else if(player->getClassId() == 1){ // joueur IA
                command = new IAJouerCommand(&gameModel, &gameController, &gameView, &actionEnCours);    
            }

            command->run();

        }
        gameModel.playerManager->rotateToNext();

    }

    gameView.afficher("-------------------------------------------------");
    gameView.afficher("La partie est terminee");
    int rejouer = gameController.askCommandString({"Non", "Oui"});
    if(rejouer){
        gameModel.reset(); // reset les cartes 
        gameModel.initGameData(parseur.get_lignes());
        start();
    }
}