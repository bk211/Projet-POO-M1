#include "batailles.hpp"


using namespace std;
int main(int argc, char const *argv[])
{

    MyGameModel* gm = new MyGameModel();
    Batailles jeu =Batailles();
    jeu.start();
    
    return 0;
}
