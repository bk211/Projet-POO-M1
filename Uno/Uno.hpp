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
    std::vector<std::string> commandStrings{"Jouer une carte", "Piocher", "Uno"};

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


class JouerCommand:public Command
{
private:
public:
    JouerCommand(GameModel * gameModel, GameController * gameController, GameView * gameView);

    ~JouerCommand();
    void run();
};

class PiocherCommand:public Command
{
private:
public:
    PiocherCommand(GameModel * gameModel, GameController * gameController, GameView * gameView);
    ~PiocherCommand();
    void run();
};


class UnoCommand:public Command
{
private:
public:
    UnoCommand(GameModel * gameModel, GameController * gameController, GameView * gameView);
    ~UnoCommand();
    void run();
};



#endif