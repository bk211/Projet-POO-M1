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
    std::cout<<gameModel.playerManager->players[0]->getHand().toString();


    while (!gameModel.isGameOver()){
        Player * player = gameModel.getPlayerManager()->getCurrentPlayer();
        if(player->getStatus() == 0){ // si le joueur ne peux pas jouer, passer au suivant 
            gameModel.playerManager->rotateToNext();
            continue;
        }
        std::cout<<"=============================\n";
        //gameView.afficherPlayersCollection(player->getHand());
        //std::string userInput = gameController.askUser("Quelle est votre commande? ");
        std::cout<<"=============================\n";
        //std::cout<< player->getHand().toString();
        break;
        gameModel.playerManager->rotateToNext();
    }
    
}