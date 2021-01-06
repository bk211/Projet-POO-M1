#include "libCardGame.hpp"

using namespace std;
class MyCard:public Carte{
private:
    std::string symbole;
    std::string description;
public:
    MyCard();
    MyCard(std::string symbole,std::string name, std::string description);
    ~MyCard(); 
    MyCard(const MyCard &cp);   
    virtual std::string toString() const;
};

MyCard::MyCard()
{
}

MyCard::MyCard(std::string symbole, std::string name, std::string description)
:symbole(symbole), description(description)
{
    setName(name);
}



MyCard::MyCard(const MyCard &cp){
    name = cp.name;
    symbole = cp.symbole;
    description = cp.description;
}

MyCard::~MyCard(){
}


std::string MyCard::toString() const{
    return "my card : "+name+", "+symbole+", "+description+"\n";
}

int removefunc(MyCard a, MyCard b){
    if(a.getName() == b.getName()){
        return true;
    }
    return false;
}



class MyGameModel: public GameModel<MyCard, Player>
{
private:
public:
    MyGameModel();
    ~MyGameModel();
    virtual MyCard createDataFromStrLine(vector<string> line);

};

MyGameModel::MyGameModel(/* args */)
{
}

MyGameModel::~MyGameModel()
{
}

MyCard MyGameModel::createDataFromStrLine(vector<string> line){
    
    /*
    cout<<"Dealing with line content: ";
    for (auto word : line){ std::cout<< word +", ";}
    cout<<std::endl;*/
    
    MyCard result = MyCard(line[1], line[2], line[3]);
    //cout<<"generated card: "<< result;
    return result;
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
    
    cout<<"=========================================="<<endl;
    //Parseur parseur = Parseur("configTest.txt", 4, true);
    Parseur parseur = Parseur("BataillesConfig32.txt", 4, true);
    parseur.print_lines();

    /*
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
    CollectionData<MyCard> deck{};
    cout<<"Size: "<<deck.size() <<endl;
    deck.addData(c1);
    deck.addData(c2);
    deck.addData(c3);
    
    cout<<"Size: "<<deck.size() <<endl;
    
    cout<<deck[0];
    cout<<"=========================================="<<endl;
    cout<<"before: "<< deck[1];
    deck[1].setName("deux bis");
    cout<<"after: "<<deck[1];
    cout<<"=========================================="<<endl;
    cout<<"removing c1: "<<deck.removeData(c1)<<endl;
    cout<<"removing c2: "<<deck.removeData(c2)<<endl;
    cout<<"removing c2 bis: "<<deck.removeDataByName("deux bis")<<endl;
    cout<<"removing c3: "<<deck.removeData(c3, removefunc)<<endl;
    cout<<"Size: "<<deck.size() <<endl;
    cout<<"=========================================="<<endl;
    */
    
    MyGameModel GM{};
    cout<<"init game return :" <<GM.initGameData(parseur.get_lignes())<<endl;
    
    cout<<"=========================================="<<endl;

    cout<<"contenue: \n"<<GM.getDataCollection().toString();
    
    cout<<"=========================================="<<endl;
    

    return 0;
}
