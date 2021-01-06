#include "../libCardGame.hpp"
Carte::Carte():name("") {
}

Carte::~Carte(){
}

const std::ostream& operator<<(std::ostream& out, const Carte& carte){
    out<< carte.toString();
    return out;
}

std::string Carte::toString() const{
    std::string result = "Carte Name : ";
    if(!name.empty()){
        result += name;
    }
    return result;
}

std::string Carte::getName()const{
    return name;
}

void Carte::setName(std::string str){
    name = str;
}

int Carte::operator==(Carte second){
    if(name == second.name){
        return 1;
    }
    return 0;
}