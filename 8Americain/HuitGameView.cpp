#include "Huit.hpp"

HuitGameView::HuitGameView(/* args */)
{
}

HuitGameView::~HuitGameView()
{
}

void HuitGameView::afficherPlayersCollection(CollectionCarte * deck){
    std::cout<<"\nVoici votre main:"<<std::endl;
    for (int i = 0; i < deck->size(); i++){
        std::cout<<dynamic_cast<HuitCard*> (deck->at(i))->toStringLess();
    }
    
    
}
