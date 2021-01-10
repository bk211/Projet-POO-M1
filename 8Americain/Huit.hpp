#ifndef UNO_HPP
#define UNO_HPP
#include "libCardGame.hpp"
#include <map>

class HuitCard:public Carte{
private:
    int type;
    std::string couleur;
    std::string description;
    bool hasChangedColor;
public:
    void changeColor(std::string couleur);
    HuitCard(std::string name,int type,std::string couleur, int value, std::string description);
    ~HuitCard();
    std::string getCouleur();
    std::string getDescription();
    int getType();
    std::string toString()const;
    std::string toStringLess()const;

};


class Huit;
class JouerCommand;
class PiocherCommand;
class HuitCommand;
    

class HuitGameView: public GameView
{
private:
public:
    HuitGameView(/* args */);
    ~HuitGameView();
    void afficherPlayersCollection(CollectionCarte * deck);

};



class HuitGameModel: public GameModel
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
public:
    ~HuitGameModel();
    HuitGameModel();
    friend Huit;
    friend JouerCommand;
    friend PiocherCommand;
    friend UnoCommand;
    
};

class Huit
{
private:

public:
    HuitGameModel gameModel;
    HuitGameView gameView;
    GameController gameController;
    Parseur parseur;
    Huit();
    ~Huit();
    void start();
};


class JouerCommand:public Command
{
private:
    bool * actionEnCours;
    int foundPlayableCards();
    bool playable(HuitCard* first, HuitCard* second)const;
    std::vector<std::string> availbleCardsString;
    std::vector<std::string> couleurString{"Bleu", "Rouge", "Jaune", "Verte"};

public:
    JouerCommand(HuitGameModel * gameModel, GameController * gameController, HuitGameView * gameView, bool *actionEnCours);
    ~JouerCommand();
    void run();
    void playCard(int playedCardId);

};

class PiocherCommand:public Command
{
private:
    bool * actionEnCours;
public:
    PiocherCommand(HuitGameModel * gameModel, GameController * gameController, HuitGameView * gameView,bool *actionEnCours);
    ~PiocherCommand();
    void run();
};


class UnoCommand:public Command
{
private:
    bool * actionEnCours;
public:
    UnoCommand(HuitGameModel * gameModel, GameController * gameController, HuitGameView * gameView, bool *actionEnCours);
    ~UnoCommand();
    void run();
};



#endif