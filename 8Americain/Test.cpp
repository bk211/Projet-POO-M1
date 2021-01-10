#include "Uno.hpp"


using namespace std;
int main(int argc, char const *argv[])
{
    UnoCard * carte = new UnoCard("un",1, "bleu", 1, "ceci est une description");
    cout<< carte->getCouleur();
    Carte * ptr = carte;
    UnoCard * ptr2 = carte;

    cout<< ((UnoCard*)ptr)->getCouleur();
    cout<< ptr2->getCouleur();

    CollectionCarte deck;
    deck.addData(carte);
    cout<<*deck[0];
    
    GameController gc{};
    vector<string> vec = {"dwadaw", "daw2", "dwadw ", "dawd"};
    std::cout<<gc.askCommandString(vec);


    return 0;
}
