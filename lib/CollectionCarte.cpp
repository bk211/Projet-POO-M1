#include "../libCardGame.hpp"

CollectionCarte::~CollectionCarte()
{
    data.clear();
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

Carte * CollectionCarte::draw()
{
    Carte *result = data.back();
    data.pop_back();
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

std::string CollectionCarte::toString() const
{
    std::string result{};
    for (Carte *obj : data)
    {
        result += obj->toString();
    }
    return result;
}

bool CollectionCarte::isEmpty() const
{
    return data.size() != 0;
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
    std::srand(std::time(0));
    int size = data.size();
    int pick;
    Carte *tmp = nullptr;
    for (int i = 0; i < size; i++)
    {
        pick = std::rand() % size;
        *tmp = *data.at(i);
        *data.at(i) = *data.at(pick);
        *data.at(pick) = *tmp;
    }
}