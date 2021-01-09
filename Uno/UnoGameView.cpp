#include "Uno.hpp"

UnoGameView::UnoGameView(/* args */)
{
}

UnoGameView::~UnoGameView()
{
}

void UnoGameView::afficherPlayersCollection(CollectionCarte& deck){
    std::cout<<"\nVoici votre main:"<<std::endl;
    for (int i = 0; i < deck.size(); i++){
        std::cout<<dynamic_cast<UnoCard*> (deck[i])->toStringLess();
    }
    
    
}
