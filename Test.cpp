#include "libCardGame.hpp"

using namespace std;
class MyCard:public Carte{
private:
public:
    MyCard();
    ~MyCard(); 
    MyCard(const MyCard &cp);   
    virtual std::string toString() const;
};

MyCard::MyCard()
{
}

MyCard::MyCard(const MyCard &cp){
    name = cp.name;
}




MyCard::~MyCard(){
}


std::string MyCard::toString() const{
    return "my card :"+name+ "\n";
}

int removefunc(MyCard a, MyCard b){
    if(a.getName() == b.getName()){
        return true;
    }
    return false;
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
    /*
    cout<<"=========================================="<<endl;
    Parseur parseur = Parseur("configTest.txt", 4, true);
    parseur.print_lines();*/

    cout<<"=========================================="<<endl;
    MyCard c1{};
    MyCard c2 = MyCard();
    MyCard c3 = MyCard();
    
    cout<<"=========================================="<<endl;
    c1.setName("un");
    cout<< c1;
    c2.setName("deux");
    c3.setName("trois");
    
    cout<<"=========================================="<<endl;
    CollectionCarte<MyCard> deck{};
    cout<<"Size: "<<deck.size() <<endl;
    deck.addCarte(c1);
    deck.addCarte(c2);
    deck.addCarte(c3);
    
    cout<<"Size: "<<deck.size() <<endl;
    
    cout<<deck[0];
    cout<<"=========================================="<<endl;
    cout<<"before: "<< deck[1];
    deck[1].setName("deux bis");
    cout<<"after: "<<deck[1];
    cout<<"=========================================="<<endl;
    cout<<"removing c1: "<<deck.removeCarte(c1)<<endl;
    cout<<"removing c2: "<<deck.removeCarte(c2)<<endl;
    cout<<"removing c3: "<<deck.removeCarte(c3, removefunc)<<endl;
    cout<<"Size: "<<deck.size() <<endl;
    

    cout<<"=========================================="<<endl;

    
    
    return 0;
}
