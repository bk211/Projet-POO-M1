#include "libCardGame.hpp"

using namespace std;
class MyCard:public Carte{
private:
public:
    MyCard();
    ~MyCard();    
    virtual std::string toString() const;
};

MyCard::MyCard(/* args */)
{
}

MyCard::~MyCard()
{
}


std::string MyCard::toString() const{
    return "my card";
}

int main(int argc, char const *argv[])
{
    /*`
    try{
        Parseur badparseur = Parseur("doesNotExist.txt", 4);
    }catch(std::invalid_argument&){
        std::cout<<"Test: Invoke Parseur with bad filename"<<std::endl;
    }
    */

    Parseur parseur = Parseur("configTest.txt", 4, true);
    parseur.print_lines();
    MyCard c1{};
    cout<< c1.toString();
    cout<< c1;

    CollectionCarte deck1{};
    cout<<deck1.size();
    deck1.addCarte(c1);
    deck1.addCarte(c1);
    deck1.addCarte(c1);
    cout<<deck1.size();

    MyCard c2{};
    MyCard c3{};
    c1.setName("un");
    c2.setName("deux");
    c3.setName("un");
    cout << c1;
    cout<<" c1 vs c2 : " << (c1 == c2) <<endl;
    cout<<" c1 vs c3 : " << (c1 == c3) <<endl;
    
    return 0;
}
