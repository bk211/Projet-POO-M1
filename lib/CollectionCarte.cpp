#include "../libCardGame.hpp"

CollectionCarte::CollectionCarte(/* args */)
{
}

CollectionCarte::~CollectionCarte()
{
}

void CollectionCarte::addCarte(Carte c){
    data.push_back(c);
}

int CollectionCarte::removeCarte(Carte c1){
    if(data.size() == 0){
        return -1;
    }
    for (size_t i = 0; i < data.size(); i++){
        if(data.at(i) == c1){
            data.erase(data.begin()+i);
            return 1;
        }
    }
    
    
    return 0;
}

int CollectionCarte::removeCarte(Carte c, int (*compareFunction)(Carte first, Carte second)){
    return -1;
    
}

int CollectionCarte::size()const{
    return data.size();
}
