#ifndef HPP_GAMELIB
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
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

class CollectionCarte;
class PlayerManager;

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
    ~CollectionCarte();
    virtual void addData(Carte *c);
    virtual int deleteData(Carte* c);
    virtual int deleteDataByName(std::string name);
    virtual int deleteData(Carte *c, int (*compareFunction)(Carte* first, Carte* second));
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
    CollectionCarte hand;

public:
    Player(std::string _name, int _status = 0, int _classId = 0);
    virtual std::string getName()const;
    void setName(std::string str);
    CollectionCarte& getHand();
    friend PlayerManager;

};

class PlayerManager{
protected:
public:
    std::vector<Player> players;
    int currentPlayer;
    int direction;
    int step;
    PlayerManager();
    Player& getCurrentPlayer();
    Player& getPlayer(int pos);
    void swapDirection();
    void setStep(unsigned int s);
    void rotateToNext();
    void addPlayer(Player p);

};


class GameModel{
protected:
    CollectionCarte data;
    PlayerManager playerManager;

public:
    GameModel();
    virtual int initGameData(std::vector<std::vector<std::string>> configData);
    virtual void pushDataFromStrLine(std::vector<std::string>) = 0;
    virtual CollectionCarte getDataCollection()const;
    virtual void initPlayers() = 0;

};

#endif
