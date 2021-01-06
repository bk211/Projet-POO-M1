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
    virtual ~Carte();
    virtual std::string toString() const;
    friend const std::ostream& operator<<(std::ostream& out, const Carte& mat);
    virtual std::string getName()const;
    virtual void setName(std::string str);
    virtual int operator==(Carte second);
    virtual int operator==(std::string name);
    
};


template<class T>
class CollectionCarte
{
private:
    std::vector<T> data;

public:
    CollectionCarte(){};
    ~CollectionCarte(){};
    virtual void addCarte(T c){
        data.push_back(c);
    }

    virtual int removeCarte(T c){
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

    virtual int removeCarteByName(std::string name){
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

    virtual int removeCarte(T c, int (*compareFunction)(T first, T second)){
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

    int size()const{
        return data.size();
    };

    virtual T operator [](int pos)const{
        return data.at(pos);
    }
    
    
    virtual T& operator [](int pos){
        return data.at(pos);
    }
    
};




#endif
