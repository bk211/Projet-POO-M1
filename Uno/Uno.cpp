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
}