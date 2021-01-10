#include "Huit.hpp"

Huit::Huit():parseur(Parseur("HuitConfig.txt",42,false)){
    //parseur.print_lines();//affiche toutes les lignes lu par le parseur
    gameModel.data = new CollectionCarte(); 
    gameModel.table = new CollectionCarte();
    gameModel.playerManager = new PlayerManager();
    gameModel.initGameData(parseur.get_lignes());

    gameModel.gameView = &gameView;
    gameModel.gameController = &gameController;
    gameModel.initPlayers();

    if(gameModel.playerManager->nbPlayers()>3){
        gameView.afficher("Il y a un nombre important de joueur, un deck supplementaire a ete rajoute");
        gameModel.initGameData(parseur.get_lignes());
    }
    
}

Huit::~Huit()
{
}

void Huit::start(){
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
            gameView.afficher(dynamic_cast<HuitCard*>(gameModel.table->last())->toStringLess());
            
            gameView.afficher("Quelle est votre action? ");
            int userAction = gameController.askCommandString(gameModel.commandStrings);
        
            // switch pour savoir quel command executer
            Command * command;
            if(userAction == 0){
                command = new JouerCommand(&gameModel, &gameController, &gameView, &actionEnCours);
            }else if(userAction == 1){
                command = new PiocherCommand(&gameModel, &gameController, &gameView, &actionEnCours);
            }else if(userAction == 2){
                command = new HuitCommand(&gameModel, &gameController, &gameView, &actionEnCours);
            }
            command->run();

        }
        gameModel.playerManager->rotateToNext();

    }

    gameView.afficher("-------------------------------------------------");
    gameView.afficher("La partie est terminee");

    gameModel.CelebrateVictory();

    int rejouer = gameController.askCommandString({"Non", "Oui"});
    if(rejouer){
        gameModel.reset(); // reset les cartes 
        gameModel.initGameData(parseur.get_lignes());
        if(gameModel.playerManager->nbPlayers()>3){
        gameView.afficher("Il y a un nombre important de joueur, un deck supplementaire a ete rajoute");
        gameModel.initGameData(parseur.get_lignes());
        }
        start();
    }
}