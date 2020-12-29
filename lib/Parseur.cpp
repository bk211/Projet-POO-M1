#include "../libCardGame.hpp"

Parseur::Parseur(std::string filename, const int nb_column, const bool strict)
    : filename(filename), nb_column(nb_column), strict_reading(strict)
{
    //debug
    std::cout<< "filename = <"<< filename<<">\n";
    std::ifstream ifs(filename);
    if(!ifs.good()){
        throw std::invalid_argument("No such file <" + filename+">");
    }

    std::string buffer;
    while(std::getline(ifs, buffer)){
        if(buffer.size() == 0) continue;
        std::vector<std::string> vec;
        //std::cout<<"buffer ="<<buffer<<" size = "<<buffer.size()<<std::endl;
        vec = split(buffer, delim);
        //debug
        //for (auto s : vec){std::cout<<s<<", ";}
        //std::cout <<std::endl;
        lignes.push_back(vec);
    }
    ifs.close();
}

std::vector<std::string> Parseur::split(std::string s, char delim) {
    std::string line;
    std::vector<std::string> vec;
    std::stringstream ss(s);
    while(std::getline(ss, line, delim)) {
        vec.push_back(line);
    }
    return vec;
}

void Parseur::print_lines() const{
    for (auto ligne: lignes){
        for (auto word : ligne){
            std::cout<<word<<", ";
        }
        std::cout<<std::endl;
    }
}


std::vector<std::vector<std::string>> Parseur::get_lignes(){
    return lignes;
}

Parseur::~Parseur(){}
