#ifndef HPP_PARSEUR
#define HPP_PARSEUR
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Parseur{
private:
    const std::string filename;
    int nb_column; 
    std::vector<std::vector<int>> lignes;
    bool strict_reading;
public:
    //Parseur(std::string filename, const int nb_column, const bool strict = true);
    Parseur(std::string filename);
    virtual ~Parseur();
};

#endif