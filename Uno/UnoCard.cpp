#include "Uno.hpp"

UnoCard::UnoCard(std::string name,int type,std::string couleur) : Carte(name),type(type),couleur(couleur){

}

UnoCard::~UnoCard()
{
}

std::string UnoCard::getCouleur(){
    return couleur;
}

int UnoCard::getType(){
    return type;
}

std::string UnoCard::toString()const{
    std::string result = "Carte Uno : ";
    result += name +" ,";
    result += type+", ";
    result += couleur +" ,";
    return result;
}
