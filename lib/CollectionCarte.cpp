#include "../libCardGame.hpp"

CollectionCarte::~CollectionCarte()
{
    clear();
};

void CollectionCarte::addData(Carte *c)
{
    data.push_back(c);
}

int CollectionCarte::deleteData(Carte *c)
{
    if (data.size() == 0)
    {
        return 0;
    }
    for (size_t i = 0; i < data.size(); i++)
    {
        if (*data.at(i) == *c)
        {
            delete data.at(i);
            data.erase(data.begin() + i);
            return 1;
        }
    }
    return 0;
}

int CollectionCarte::deleteDataByName(std::string name)
{
    if (data.size() == 0)
    {
        return 0;
    }
    for (size_t i = 0; i < data.size(); i++)
    {
        if (*data.at(i) == name)
        {
            std::cout<<"match "  <<*data.at(i);
            delete data.at(i);
            data.erase(data.begin() + i);
            return 1;
        }
    }
    return 0;
}

int CollectionCarte::deleteData(Carte *c, int (*compareFunction)(Carte *first, Carte *second))
{
    if (data.size() == 0)
    {
        return 0;
    }

    for (size_t i = 0; i < data.size(); i++)
    {
        if (compareFunction(data.at(i), c))
        {
            delete data.at(i);
            data.erase(data.begin() + i);
            return 1;
        }
    }
    return 0;
}

int CollectionCarte::deleteData(int pos)
{
    if (data.size() == 0)
    {
        return 0;
    }
    
    if(pos> (int)data.size() || pos <0){
        return 0;
    }

    delete data.at(pos);
    data.erase(data.begin() + pos);
    return 1;
}

Carte * CollectionCarte::draw()
{
    Carte *result = data.back();
    data.pop_back();
    return result;
}


Carte * CollectionCarte::draw(int pos){
    Carte *result = data.at(pos);
    data.erase(data.begin() + pos);
    return result;

}
Carte * CollectionCarte::drawRandom(){
    std::srand(std::time(0));
    int pick = std::rand() % data.size();
    Carte *result = data.at(pick);
    data.erase(data.begin() + pick);
    return result;    
}

int CollectionCarte::size() const
{
    return data.size();
};

Carte* CollectionCarte::operator[](int pos) const
{
    return data.at(pos);
}

Carte* CollectionCarte::at(int pos)
{
    return data.at(pos);
}

Carte* CollectionCarte::first()
{
    if(data.empty()) return nullptr;
    return data.at(0);
}

Carte* CollectionCarte::last()
{
    if(data.empty()) return nullptr;
    return data.at(data.size()-1);
}

std::string CollectionCarte::toString() const
{
    std::string result{};
    for (Carte *obj : data)
    {
        result += obj->toString();
        result += "\n";
    }
    return result;
}

bool CollectionCarte::isEmpty() const
{
    return data.size() == 0;
}

void CollectionCarte::clear()
{
    for (auto c : data)
    {
        delete c;
    }
    data.clear();
}

void CollectionCarte::shuffle()
{
    //std::cout<<"shuffling"<<std::endl;
    std::srand(std::time(0));
    std::random_shuffle(data.begin(), data.end());
}



void CollectionCarte::insertData(Carte *c, int pos){
    data.insert(data.begin()+pos, c);    
}

void CollectionCarte::insertFront(Carte *c){
    data.insert(data.begin(), c); 
}

