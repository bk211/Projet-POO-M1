#ifndef BATAILLES_HPP
#define BATAILLES_HPP
#include "libCardGame.hpp"

class MyGameModel: public GameModel
{
private:
public:
    MyGameModel();
    ~MyGameModel();
    virtual void pushDataFromStrLine(std::vector<std::string> line);
    virtual void initPlayers();
    virtual void startGame();
    virtual void countScore();
    
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