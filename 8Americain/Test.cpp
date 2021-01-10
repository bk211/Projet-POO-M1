#include "Huit.hpp"


using namespace std;
int main(int argc, char const *argv[])
{

    Player * p1 = new Player("un",1,0,0);
    Player * p2 = new Player("deux",1,0,0);
    PlayerManager * pm = new PlayerManager();
    pm->addPlayer(p1);
    pm->addPlayer(p2);
    pm->addPlayer(p1);
    pm->addPlayer(p2);
    cout<<pm->nbPlayers();

    //pm->rotateToNext();
    pm->swapDirection();
    
    for (size_t i = 0; i < 10; i++)
    {
        pm->rotateToNext();
    }
   pm->swapDirection();
    
    for (size_t i = 0; i < 10; i++)
    {
        pm->rotateToNext();
    }
   pm->swapDirection();
    
    for (size_t i = 0; i < 10; i++)
    {
        pm->rotateToNext();
    }

    pm->rotateToNext();
    
    return 0;
}
