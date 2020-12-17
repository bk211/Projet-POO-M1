#ifndef HPP_PARSEUR
#define HPP_PARSEUR
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>



class Parseur{
private:
    const std::string filename;
    const int nb_column; 
    std::vector<std::vector<std::string>> lignes;
    const bool strict_reading;
    char delim{','};
    

public:
    //Parseur(std::string filename, const int nb_column, const bool strict = true);
    Parseur(std::string filename, const int nb_column, const bool strict = true);
    virtual ~Parseur();
    std::vector<std::string> split(const std::string s, char delim);
    void print_lines();

};

#endif