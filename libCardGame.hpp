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
    Player(std::string _name, int _status = 0, int _classId = 0):
    name(_name), status(_status), classId(_classId)
    {}

    virtual std::string getName()const{
        return name;
    }

    void setName(std::string str){
        name = str;
    }

    CollectionCarte& getHand(){
        return hand;
    }
    friend PlayerManager;

};

class PlayerManager{
protected:
public:
    std::vector<Player> players;
    int currentPlayer;
    int direction;
    int step;
    PlayerManager():currentPlayer(0), direction(1), step(1){}
    Player& getCurrentPlayer(){
        return players[currentPlayer];
    }

    Player& getPlayer(int pos){
        return players[pos];
    }

    void swapDirection(){
        direction = (direction ==1)? -1 : 1;
    }

    void setStep(unsigned int s){
        step = s;
    }

    void rotateToNext(){
        int next = currentPlayer;
        int size = players.size();
        while(step > 0){
            next += direction;
            if(next >= size){
                next %= size; 
            }else if(next < 0){
                next = size - next;
            }

            //if(players[next].status == 1){
              //  step--;
            //}
        }
        step = 1;
    }

    void addPlayer(Player p){
        players.push_back(p);
    }

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
