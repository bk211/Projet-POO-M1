#ifndef UNO_HPP
#define UNO_HPP
#include "libCardGame.hpp"
#include <map>

class UnoCard:public Carte{
private:
    int type;
    std::string couleur;
    std::string description;

public:
    UnoCard(std::string name,int type,std::string couleur, int value, std::string description);
    ~UnoCard();
    std::string getCouleur();
    std::string getDescription();
    int getType();
    std::string toString()const;

};


class Uno;

class UnoGameView: public GameView
{
private:
public:
    UnoGameView(/* args */);
    ~UnoGameView();
    void afficherPlayersCollection(CollectionCarte & deck);

};



class UnoGameModel: public GameModel
{
private:
    void pushDataFromStrLine(std::vector<std::string> line);
    void initPlayers();
    void startGame();
    bool isGameOver();
    CollectionCarte * table;

public:
    void countScore();
    ~UnoGameModel();
    UnoGameModel();
    friend Uno;
};

class Uno
{
private:
public:
    UnoGameModel gameModel;
    UnoGameView gameView;
    GameController gameController;
    Parseur parseur;
    Uno();
    ~Uno();
    void start();
};

#endif