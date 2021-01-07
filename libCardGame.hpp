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

class Carte
{
private:
protected:
    std::string name;
public:
    Carte();
    Carte(std::string name);
    virtual ~Carte();
    virtual std::string toString() const;
    friend const std::ostream& operator<<(std::ostream& out, const Carte& mat);
    virtual std::string getName()const;
    virtual void setName(std::string str);
    virtual int operator==(Carte second);
    virtual int operator==(std::string name);
    
};


template<typename T>
class CollectionData
{
private:
    std::vector<T> data;

public:
    CollectionData(){};
    ~CollectionData(){};
    virtual void addData(T c){
        data.push_back(c);
    }

    virtual int deleteData(T c){
        if(data.size() == 0){
        return 0;
        }
        for (size_t i = 0; i < data.size(); i++){
            if(data.at(i) == c){
                data.erase(data.begin()+i);
                return 1;
            }
        }
        return 0;
    }

    virtual int deleteDataByName(std::string name){
        if(data.size() == 0){
        return 0;
        }
        for (size_t i = 0; i < data.size(); i++){
            if(data.at(i) == name){
                data.erase(data.begin()+i);
                return 1;
            }
        }
        return 0;
    }

    virtual int deleteData(T c, int (*compareFunction)(T first, T second)){
        if(data.size() == 0){
            return 0;
        }
    
        for (size_t i = 0; i < data.size(); i++){
            if(compareFunction(data.at(i), c)){
                data.erase(data.begin()+i);
                return 1;
                }
            }    
        return 0;
    }

    virtual T draw(){
        T result = data.back();
        data.pop_back();
        return result;
    }
    
    virtual int size()const{
        return data.size();
    };

    virtual T operator [](int pos)const{
        return data.at(pos);
    }
    
    virtual T& operator [](int pos){
        return data.at(pos);
    }

    virtual std::string toString()const{
        std::string result{};
        for (auto obj : data){
            result += obj.toString();
        }
        return result;
    }

    virtual bool isEmpty()const{
        return data.size() != 0;
    }

    virtual void clear(){
        data.clear();
    }

    virtual void shuffle(){
        shuffleVector(data);
    }


};

template<typename Data>
void shuffleVector(std::vector<Data>& vec){
    std::srand(std::time(0));
    int size = vec.size();
    int pick;
    Data tmp;
    for (int i = 0; i < size; i++){
        pick = std::rand() % size;
        tmp = vec.at(i);
        vec.at(i) = vec.at(pick);
        vec.at(pick) = tmp;
    }
    std::cout<<"shuffle done"<<std::endl;
}


template<typename CardType, template <typename> class PlayerManager>
class GameModel{
protected:
    CollectionData<CardType> data;
    PlayerManager<CardType> playerManager;

public:
    GameModel(){};
    virtual int initGameData(std::vector<std::vector<std::string>> configData){

        if(!data.isEmpty()){// une partie a déjà été joué, refaire le deck et refaire la main des joueurs
            data.clear();
            //TODO joueur.clear()
        }
        try{
            //std::cout<<"in initGameData"<<std::endl;
            for (auto lines : configData){
                pushDataFromStrLine(lines);
            }
        
        }catch(std::exception &e){ // TODO tester l'erreur s'il marche en cas de pb de lecture de fichier config
            std::cout<<"reading failed"<<std::endl;     
            return 0;
        }
        //std::cout<<"done reading"<<std::endl;


        return 1;
    }

    virtual void pushDataFromStrLine(std::vector<std::string>) = 0;

    virtual CollectionData<CardType> getDataCollection()const{
        return data;    
    }

    virtual void initPlayers() = 0;

};

template<typename CardType>
class Player{
private:
protected:
    std::string name;
    int status;
    int classId;
    CollectionData<CardType> hand;

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

    CollectionData<CardType>& getHand(){
        return hand;
    }

};


template<typename CardType>
class PlayerManager{
private:
    std::vector<Player<CardType>> players;
    int currentPlayer;
    int direction;
    int step;
    friend class GameModel<CardType, PlayerManager>;
    PlayerManager():currentPlayer(0), direction(1), step(1){}
    Player<CardType>& getCurrentPlayer(){
        return players[currentPlayer];
    }

    Player<CardType>& getPlayer(int pos){
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

            if(players[next].status == 1){
                step--;
            }
        }
        step = 1;
    }

public:
    void addPlayer(Player<CardType> p){
        players.push_back(p);
    }

};


#endif
