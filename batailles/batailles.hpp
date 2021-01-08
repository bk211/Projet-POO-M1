#ifndef BATAILLES_HPP
#define BATAILLES_HPP
#include "libCardGame.hpp"

class MyGameModel:public GameModel
{
private:
    virtual void pushDataFromStrLine(std::vector<std::string>);
    virtual void initPlayers();
    virtual void startGame();
    virtual void countScore();
    virtual bool isGameOver();
public:
    MyGameModel();
    ~MyGameModel();
};




/*
class Batailles
{
private:
    MyGameModel gameModel;
    GameView GameView;
    GameController GameController;
    Parseur * parseur;
public:
    Batailles();
    ~Batailles();
};
*/

#endif