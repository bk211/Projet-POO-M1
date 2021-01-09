#include "Uno.hpp"

Uno::Uno():parseur(Parseur("UnoConfig.txt",42,false)){
    //parseur.print_lines();//affiche toutes les lignes lu par le parseur
    gameModel.data = new CollectionCarte(); 
    gameModel.table = new CollectionCarte();
    gameModel.initGameData(parseur.get_lignes());
    gameModel.playerManager = new PlayerManager();
    gameModel.initPlayers();
    


}

Uno::~Uno()
{
}

void Uno::start(){
    gameModel.startGame();// distribuer les cartes au joueurs
//    std::cout<<gameModel.playerManager->players[0]->getHand().toString();


    while (!gameModel.isGameOver()){
        Player * player = gameModel.getPlayerManager()->getCurrentPlayer();

        bool actionEnCours = true;
        while (actionEnCours){
            gameView.afficher("==============================================\n");
            gameView.afficher("C'est au tour de : "+ player->getName());
            gameView.afficherPlayersCollection(player->getHand());
            std::cout<<"get card uscces\n";
            gameView.afficher("==============================================");
            gameView.afficher("La carte actuellement mise sur la table est :");
            gameView.afficher(dynamic_cast<UnoCard*>(gameModel.table->last())->toStringLess());
            
            gameView.afficher("Quelle est votre action? ");
            std::string userAction = gameController.askCommandString(gameModel.commandStrings);
            std::cout<<"utilisateur a choisi : " << userAction<<std::endl;


            // switch pour savoir quel command executer
            Command * command;
            if(userAction == "Jouer une carte"){
                command = new JouerCommand(&gameModel, &gameController, &gameView, &actionEnCours);
            }else if(userAction == "Piocher"){
                command = new PiocherCommand(&gameModel, &gameController, &gameView, &actionEnCours);
            }else if(userAction == "Uno"){
                command = new UnoCommand(&gameModel, &gameController, &gameView, &actionEnCours);
            }
            command->run();

        }
        
        gameModel.playerManager->rotateToNext();
    }
    
}