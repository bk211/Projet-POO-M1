#ifndef HPP_GAMELIB
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

class CollectionCarte;
class PlayerManager;
class GameModel;
class GameView;
class GameController;

class Parseur{
private:
    const std::string filename;
    const int nb_column; 
    mutable std::vector<std::vector<std::string>> lignes;
    const bool strict_reading;
    char delim{','};

public:
    //Parseur(std::string filename, const int nb_column, const bool strict = true);
    Parseur(std::string filename, const int nb_column, const bool strict = true);
    virtual ~Parseur();
    std::vector<std::string> split(const std::string s, const char delim);
    void print_lines() const;
    std::vector<std::vector<std::string>> get_lignes();
};


class Carte
{
private:
protected:
    std::string name;
    std::vector<std::string> attributs;
    virtual void addAttribut(std::string name);

public:
    virtual void setName(std::string str);
    virtual std::string getAttribut(int pos);
    virtual ~Carte();
    virtual std::string toString() const;
    friend const std::ostream& operator<<(std::ostream& out, const Carte& mat);
    virtual std::string getName()const;
    virtual int operator==(Carte second);
    virtual int operator==(std::string name);
    Carte();
    Carte(std::string name);
    friend CollectionCarte;
};


class CollectionCarte
{
private:
    std::vector<Carte *> data;

public:
    CollectionCarte(){};
    virtual ~CollectionCarte();
    virtual void addData(Carte *c);
    virtual int deleteData(Carte* c);
    virtual int deleteDataByName(std::string name);
    virtual int deleteData(Carte *c, int (*compareFunction)(Carte* first, Carte* second));
    virtual int deleteData(int pos);
    virtual Carte * draw();
    virtual int size()const;
    virtual Carte * operator [](int pos)const;
    virtual std::string toString()const;
    virtual bool isEmpty()const;
    virtual void clear();
    virtual void shuffle();
};


class Player{
private:
protected:
    std::string name;
    int status;
    int classId;
    int score;
    CollectionCarte hand;

public:
    virtual ~Player();
    Player(std::string _name, int _status = 0, int _classId = 0, int _score =0 );
    virtual std::string getName()const;
    void setName(std::string str);
    CollectionCarte& getHand();
    friend PlayerManager;
    std::string toString() const;
    friend const std::ostream& operator<<(std::ostream& out, const Player& p);
};

class PlayerManager{
protected:
public:
    PlayerManager();
    virtual ~PlayerManager();
    std::vector<Player *> players;
    int currentPlayer;
    int direction;
    int step;
    Player* getCurrentPlayer();
    Player* getPlayer(int pos);
    void swapDirection();
    void setStep(unsigned int s);
    void rotateToNext();
    void addPlayer(Player *p);
    friend GameModel;
};


class GameModel{
protected:
    CollectionCarte * data;
    PlayerManager * playerManager;
    GameView * gameView;
    GameController * gameController;
    
public:
    GameModel();
    virtual int initGameData(std::vector<std::vector<std::string>> configData);
    virtual CollectionCarte* getDataCollection();
    virtual PlayerManager* getPlayerManager();
    virtual void pushDataFromStrLine(std::vector<std::string>) = 0;
    virtual void initPlayers() = 0;
    virtual void startGame() = 0;
    virtual void countScore();
    virtual bool isGameOver();
    virtual void attach(GameView * gv);
    virtual void attach(GameController * gc);
    

    //to be deleted
    virtual void test();
};

class GameController
{
private:
public:
    GameController(/* args */);
    virtual ~GameController();
    virtual std::string getUserInput();
};

class GameView
{
private:
public:
    virtual void afficher(std::string msg); 
    GameView();
    virtual ~GameView();
};



class Command{
private:
    GameModel * gameModel;
    GameController * gameController;
    GameView * gameView;
public:
    Command(GameModel * gm = nullptr, GameController * gc = nullptr, GameView * gv = nullptr);
    virtual ~Command();
};


#endif