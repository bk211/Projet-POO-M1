#include "../libCardGame.hpp"

PlayerManager::PlayerManager() : currentPlayer(0), direction(1), step(1) {}

PlayerManager::~PlayerManager(){
    for (Player * p : players)
    {
        delete p;
    }
    players.clear();
}

Player * PlayerManager::getCurrentPlayer()
{
    return players[currentPlayer];
}

Player * PlayerManager::getLastPlayer()
{
    return players[lastPlayer];
}

Player * PlayerManager::getPlayer(int pos)
{
    return players[pos];
}

void PlayerManager::swapDirection()
{
    direction = (direction == 1) ? -1 : 1;
}

void PlayerManager:: setStep(unsigned int s)
{
    step = s;
}

//
void PlayerManager::rotateToNext()
{
    lastPlayer = currentPlayer;
    int next = currentPlayer;
    int size = players.size();
    while (step > 0)
    {
        next += direction;
        if (next >= size)
        {
            next %= size;
        }
        else if (next < 0)
        {
            next = size - next;
        }

        if(players[next]->status == 1){
          step--;
        }
    }
    step = 1;
    currentPlayer = next;
}

void PlayerManager::addPlayer(Player *p)
{   
    players.push_back(p);
}

int PlayerManager::nbPlayers(){
    return players.size();
}