#include "Huit.hpp"

HuitCard::HuitCard(std::string name,int type,std::string couleur, int value, std::string description) 
: Carte(name, 0, value),type(type),couleur(couleur), description(description), hasChangedColor(false){
}

HuitCard::~HuitCard()
{
}

std::string HuitCard::getCouleur(){
    return couleur;
}

std::string HuitCard::getDescription(){
    return description;
}

int HuitCard::getType(){
    return type;
}

std::string HuitCard::toString()const{
    std::string result = "Carte Uno : ";
    result += name +", ";
    result += "type=[" +std::to_string(type)+"] ";
    result += "couleur=["+couleur +"] ";
    result += "value=["+std::to_string(value) +"] ";
    result += "description=["+description +"] ";
    return result;
}

std::string HuitCard::toStringLess()const{
    std::string result;
    std::cout<<"Carte: " + name + "\t";
    std::cout<<"Valeur: " + std::to_string(value) + "\t";
    std::cout<<"Couleur: " + couleur+ "\t";
    std::cout<<"Description: " + description +"\n";
    return result;
}

void HuitCard::changeColor(std::string _couleur){
    if(hasChangedColor){
        return;
    }else{
        if(name == "Joker" || name == "+4"){ // si la carte est un Joker/+4 et qu'elle a jamais change de couleur
            hasChangedColor = true;
            couleur = _couleur;
        }
    }

}

