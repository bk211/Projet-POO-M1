#ifndef BRISCOLA_HPP
#define BRISCOLA_HPP
#include "libCardGame.hpp"


class Briscola;
class BriscolaGameModel: public GameModel
{
private:
    void pushDataFromStrLine(std::vector<std::string> line);
    void initPlayers();
    void startGame();
    bool isGameOver();
public:
    void countScore();
    ~BriscolaGameModel();
    BriscolaGameModel();
    friend Briscola;
};

int compare(Carte * first, Carte * second);


class Briscola
{
private:
public:
    BriscolaGameModel gameModel;
    GameView gameView;
    GameController gameController;
    Parseur parseur;
    Briscola();
    ~Briscola();
    void start();
};

#endif