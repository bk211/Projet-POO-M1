#include "Parseur.hpp"

int main(int argc, char const *argv[])
{
    try{
        Parseur badparseur = Parseur("doesNotExist.txt", 4);
    }catch(std::invalid_argument&){
        std::cout<<"Test: Invoke Parseur with bad filename"<<std::endl;
    }

    Parseur parseur = Parseur("configTest.txt", 4, true);
    parseur.print_lines();

    return 0;
}
