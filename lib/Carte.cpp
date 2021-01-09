#include "../libCardGame.hpp"
Carte::Carte():name(""), status(0), value(0){
}

Carte::Carte(std::string _name, int _status, int _value):name(_name), status(_status), value(_value){
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


int Carte::operator==(std::string second){
    if(name == second){
        return 1;
    }
    return 0;
}

void Carte::addAttribut(std::string att){
    attributs.push_back(att);
}

std::string Carte::getAttribut(int pos){
    return attributs.at(pos);
}

int Carte::getStatus(){
    return status;
}
void Carte::setStatus(int val){
    status = val;
}

int Carte::getValue(){
    return value;
}

void Carte::setValue(int val){
    value = val;
}