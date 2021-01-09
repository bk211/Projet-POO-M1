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
        UnoCard * carte = dynamic_cast<UnoCard*> (deck[i]);
        std::cout<<"Carte: " + carte->getName() + "\t";
        std::cout<<"Valeur: " + std::to_string(carte->getValue())+ "\t";
        std::cout<<"Couleur: " + carte->getCouleur()+ "\t";
        std::cout<<"Description: " + carte->getDescription()+ "\t";
        
        std::cout<<std::endl;
    }
    
    
}
