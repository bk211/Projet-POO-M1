#include "../libCardGame.hpp"

std::string Player::getName()const{
    return name;
}

void Player::setName(std::string str){
    name = str;
}
