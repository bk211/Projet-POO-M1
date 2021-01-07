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

    virtual int removeData(T c){
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

    virtual int removeDataByName(std::string name){
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

    virtual int removeData(T c, int (*compareFunction)(T first, T second)){
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

template<typename CardData, typename Player>
class GameModel{
protected:
    CollectionData<CardData> data;
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

    virtual CollectionData<CardData> getDataCollection()const{
        return data;
    }

};

class Player{
private:
protected:
    std::string name;
public:
    Player(std::string);
    virtual void setName(std::string str);
    virtual std::string getName()const;
};

#endif
