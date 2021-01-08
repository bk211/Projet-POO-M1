#ifndef BATAILLES_HPP
#define BATAILLES_HPP
#include "libCardGame.hpp"


class Batailles;
class MyGameModel: public GameModel
{
private:
    void pushDataFromStrLine(std::vector<std::string> line);
    void initPlayers();
    void startGame();
public:
    void countScore();
    ~MyGameModel();
    MyGameModel();
    friend Batailles;


};



class Batailles
{
private:
public:
    MyGameModel gameModel;
    GameView gameView;
    GameController gameController;
    Parseur parseur;
    Batailles();
    ~Batailles();
    void start();
};

#endif