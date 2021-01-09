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
    std::string toStringLess()const;

};


class Uno;
class JouerCommand;
class PiocherCommand;
class UnoCommand;
    

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
    friend JouerCommand;
    friend PiocherCommand;
    friend UnoCommand;
    
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
    bool * actionEnCours;
public:
    JouerCommand(UnoGameModel * gameModel, GameController * gameController, UnoGameView * gameView, bool *actionEnCours);
    ~JouerCommand();
    void run();
};

class PiocherCommand:public Command
{
private:
    bool * actionEnCours;
public:
    PiocherCommand(UnoGameModel * gameModel, GameController * gameController, UnoGameView * gameView,bool *actionEnCours);
    ~PiocherCommand();
    void run();
};


class UnoCommand:public Command
{
private:
    bool * actionEnCours;
public:
    UnoCommand(UnoGameModel * gameModel, GameController * gameController, UnoGameView * gameView, bool *actionEnCours);
    ~UnoCommand();
    void run();
};



#endif