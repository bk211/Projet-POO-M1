#include "Uno.hpp"

UnoCard::UnoCard(std::string name,int type,std::string couleur, int value, std::string description) 
: Carte(name, 0, value),type(type),couleur(couleur), description(description){
}

UnoCard::~UnoCard()
{
}

std::string UnoCard::getCouleur(){
    return couleur;
}

std::string UnoCard::getDescription(){
    return description;
}

int UnoCard::getType(){
    return type;
}



std::string UnoCard::toString()const{
    std::string result = "Carte Uno : ";
    result += name +", ";
    result += "type=[" +std::to_string(type)+"] ";
    result += "couleur=["+couleur +"] ";
    result += "value=["+std::to_string(value) +"] ";
    result += "description=["+description +"] ";
    return result;
}
