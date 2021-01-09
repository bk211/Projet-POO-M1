#include "Uno.hpp"

UnoCard::UnoCard(std::string name,int type,std::string couleur, int value, std::string description) 
: Carte(name, 0, value),type(type),couleur(couleur), description(description), hasChangedColor(false){
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

std::string UnoCard::toStringLess()const{
    std::string result;
    std::cout<<"Carte: " + name + "\t";
    std::cout<<"Valeur: " + std::to_string(value) + "\t";
    std::cout<<"Couleur: " + couleur+ "\t";
    std::cout<<"Description: " + description +"\n";
    return result;
}

void UnoCard::changeColor(std::string _couleur){
    if(hasChangedColor){
        return;
    }else{
        if(name == "Joker"){ // si la carte est un Joker et qu'elle a jamais change de couleur
            hasChangedColor = true;
            couleur = _couleur;
        }
    }

}

