#ifndef BASE_HPP
#define BASE_HPP
#include "libCardGame.hpp"


class BaseJeu;
class BaseGameModel: public GameModel
{
private:
    void pushDataFromStrLine(std::vector<std::string> line);
    void initPlayers();
    void startGame();
    bool isGameOver();
public:
    void countScore();
    ~BaseGameModel();
    BaseGameModel();
    friend BaseJeu;
};

int compare(Carte * first, Carte * second);


class BaseJeu
{
private:
public:
    BaseGameModel gameModel;
    GameView gameView;
    GameController gameController;
    Parseur parseur;
    BaseJeu();
    ~BaseJeu();
    void start();
};

#endif