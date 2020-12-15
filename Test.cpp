#include "Parseur.hpp"

int main(int argc, char const *argv[])
{
    try{
        Parseur parseur = Parseur("doesNotExist.txt");
    }catch(std::invalid_argument&){
        std::cout<<"Test: Invoke Parseur with bad filename"<<std::endl;
    }

    Parseur parseur = Parseur("configTest.txt");

    return 0;
}
