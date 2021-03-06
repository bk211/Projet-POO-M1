#ifndef UNO_HPP
#define UNO_HPP
#include "libCardGame.hpp"
#include <map>

class UnoCard:public Carte{
private:
    int type;
    std::string couleur;
    std::string description;
    bool hasChangedColor;
public:
    void changeColor(std::string couleur);
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
class IAJouerCommand;
    

class UnoGameView: public GameView
{
private:
public:
    UnoGameView(/* args */);
    ~UnoGameView();
    void afficherPlayersCollection(CollectionCarte * deck);

};



class UnoGameModel: public GameModel
{
private:
    void pushDataFromStrLine(std::vector<std::string> line);
    void initPlayers();
    void startGame();
    bool isGameOver();
    CollectionCarte * table;
    int currentPenalty;
    std::vector<std::string> commandStrings{"Jouer une carte", "Piocher", "Uno"};
    void applyPenalty();
    int currentWinnerId;
    void countScore();
    void reFill();
    void reset();
    void CelebrateVictory();
public:
    ~UnoGameModel();
    UnoGameModel();
    friend Uno;
    friend JouerCommand;
    friend PiocherCommand;
    friend UnoCommand;
    friend IAJouerCommand;
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
protected:
    bool * actionEnCours;
    int foundPlayableCards();
    bool playable(UnoCard* first, UnoCard* second)const;
    std::vector<std::string> availbleCardsString;
    std::vector<std::string> couleurString{"Bleu", "Rouge", "Jaune", "Verte"};

public:
    JouerCommand(UnoGameModel * gameModel, GameController * gameController, UnoGameView * gameView, bool *actionEnCours);
    ~JouerCommand();
    virtual void run();
    virtual void playCard(int playedCardId);
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

class IAJouerCommand:public JouerCommand
{
private:
public:
    IAJouerCommand(UnoGameModel * gameModel, GameController * gameController, UnoGameView * gameView, bool *actionEnCours);
    ~IAJouerCommand();
    virtual void run();
    virtual void playCard(int playedCardId);
};


#endif