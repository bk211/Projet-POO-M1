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
};


class CollectionCarte
{
private:
    std::vector<Carte> data;

public:
    CollectionCarte();
    ~CollectionCarte();
    virtual void addCarte(Carte c);
    virtual int removeCarte(Carte c);
    virtual int removeCarte(Carte c, int (*compareFunction)(Carte first, Carte second));
    int size()const;

};



#endif
