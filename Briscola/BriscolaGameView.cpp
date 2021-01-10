#include "Briscola.hpp"

BriscolaGameView::BriscolaGameView(/* args */)
{
}

BriscolaGameView::~BriscolaGameView()
{
}

void BriscolaGameView::afficherPlayersCollection(CollectionCarte * deck){
    std::cout<<"\nVoici votre main:"<<std::endl;
    for (int i = 0; i < deck->size(); i++){
        std::cout<<dynamic_cast<Carte*> (deck->at(i))->toString();
        std::cout<<std::endl;
    }
    
    
}
