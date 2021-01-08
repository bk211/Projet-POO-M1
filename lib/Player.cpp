#include "../libCardGame.hpp"

Player::Player(std::string _name, int _status, int _classId, int _score) 
: name(_name), status(_status), classId(_classId), score(_score){
}

Player::~Player(){

}

std::string Player::getName() const
{
    return name;
}

void Player::setName(std::string str)
{
    name = str;
}

CollectionCarte & Player::getHand()
{
    return hand;
}


const std::ostream& operator<<(std::ostream& out, const Player& p){
    out<< p.toString();
    return out;
}

std::string Player::toString() const{
    std::string result{};
    result += "Name: "+name;
    result += "\nStatus: "+ std::to_string(status);
    result += "\nClassId: "+ std::to_string(classId);
    result += "\nScore: "+ std::to_string(score);
    result += "\n";
    return result;
}


