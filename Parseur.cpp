#include "Parseur.hpp"

//Parseur::Parseur(std::string filename, const int nb_column, const bool strict)
//    : filename(filename), nb_column(nb_column), strict_reading(strict)
Parseur::Parseur(std::string filename)
    : filename(filename)
{
    //debug
    std::cout<< "filename = <"<< filename<<">\n";
    std::ifstream ifs(filename);
    if(!ifs.good()){
        throw std::invalid_argument("No such file <" + filename+">");
    }

    std::string buffer;
    while(std::getline(ifs, buffer)){
        std::vector<std::string> vec;
        vec.push_back(buffer);
        std::cout<<"buffer ="<<buffer<<std::endl;
    }


    ifs.close();
}

Parseur::~Parseur(){}
