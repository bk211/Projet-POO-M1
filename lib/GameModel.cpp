#include "../libCardGame.hpp"

GameModel::GameModel(){

}

int GameModel::initGameData(std::vector<std::vector<std::string>> configData)
{

    if (!data.isEmpty())
    { // une partie a déjà été joué, refaire le deck et refaire la main des joueurs
        data.clear();
        //TODO joueur.clear()
    }
    try
    {
        //std::cout<<"in initGameData"<<std::endl;
        for (auto lines : configData)
        {
            pushDataFromStrLine(lines);
        }
    }
    catch (std::exception &e)
    { // TODO tester l'erreur s'il marche en cas de pb de lecture de fichier config
        std::cout << "reading failed" << std::endl;
        return 0;
    }
    //std::cout<<"done reading"<<std::endl;

    return 1;
}


CollectionCarte& GameModel::getDataCollection()
{
    return data;
}

PlayerManager& GameModel::getPlayerManager()
{
    return playerManager;
}


void GameModel::test(){
    std::cout<<"in gameModel test\n";
    std::cout<<*playerManager.getCurrentPlayer();
}

void GameModel::countScore(){

}

bool GameModel::isGameOver(){
    return false;
}

void GameModel::attach(GameView * gv){
    gameView = gv;
}

void GameModel::attach(GameController * gc){
    gameController = gc;
}
