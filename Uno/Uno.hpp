#ifndef UNO_HPP
#define UNO_HPP
#include "libCardGame.hpp"
#include <map>

class Uno;
class UnoGameModel: public GameModel
{
private:
    void pushDataFromStrLine(std::vector<std::string> line);
    void initPlayers();
    void startGame();
    bool isGameOver();
public:
    void countScore();
    ~UnoGameModel();
    UnoGameModel();
    friend Uno;
};

int compare(Carte * first, Carte * second);


class Uno
{
private:
public:
    UnoGameModel gameModel;
    GameView gameView;
    GameController gameController;
    Parseur parseur;
    Uno();
    ~Uno();
    void start();
};

#endif