#ifndef BRISCOLA_HPP
#define BRISCOLA_HPP
#include "libCardGame.hpp"
#include <map>


class Briscola;
class BriscolaGameModel: public GameModel
{
private:
    void pushDataFromStrLine(std::vector<std::string> line);
    void initPlayers();
    void startGame();
    bool isGameOver();
    Carte * atout;
    Carte * table;
public:
    void countScore();
    ~BriscolaGameModel();
    BriscolaGameModel();
    friend Briscola;
};

class BriscolaGameView: public GameView
{
private:
public:
    BriscolaGameView(/* args */);
    ~BriscolaGameView();
    void afficherPlayersCollection(CollectionCarte * deck);

};
int compare(Carte * first, Carte * second);


class Briscola
{
private:
public:
    BriscolaGameModel gameModel;
    BriscolaGameView gameView;
    GameController gameController;
    Parseur parseur;
    Briscola();
    ~Briscola();
    void start();
};


#endif