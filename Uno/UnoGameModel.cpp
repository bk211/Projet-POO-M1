#include "Uno.hpp"

UnoGameModel::UnoGameModel():currentPenalty(0)
{

}

UnoGameModel::~UnoGameModel()
{
    delete data;
}


void UnoGameModel::pushDataFromStrLine(std::vector<std::string> line)
{
    /*
    std::cout << "Dealing with line content: ";
    for (auto word : line) std::cout << word + ", ";
    std::cout << std::endl;
    */

    int nombre = std::stoi(line[0]);
    int value = std::stoi(line[2]);
    int type = std::stoi(line[3]);
    auto description = line[5];
    for (int i = 0; i < nombre; i++)
    {
        int nbCouleur = std::stoi(line[4]);
        for (int i = 0; i < nbCouleur; i++)
        {
            auto couleur = line[6 + i];
            UnoCard *result = new UnoCard(line[1], type, couleur, value, description);

            //decommenter ici pour voir les cartes;
            //std::cout << *result;
            //std::cout << "\n";

            data->addData(result);
        }
    }    
}

void UnoGameModel::startGame(){//debut de la partie, distribuer les cartes
    data->shuffle(); // melanger les cartes;
    std::cout<<"--------------------------start game ----------------------------\n";
    int nbCarte = 7;
    for (Player *player : playerManager->players)
    {
        for (int i = 0; i < nbCarte; i++){ 
            player->getHand()->addData(data->draw());
        }
    }
    //tirer une carte et poser sur la table;
    // si la carte est une carte speciale, continuer jusqu'a trouver une carte numerique
    while (table->isEmpty() ||dynamic_cast<UnoCard*>(table->last())->getType() == 1){
        table->addData(data->draw());
    }
}

void UnoGameModel::initPlayers()
{
    int nbPlayer = -1;
    while (nbPlayer<1 || nbPlayer >5){
        nbPlayer = std::stoi(gameController->askUser("Combien de joueur humain vous etes?"));
    }

    for (int i = 0; i < nbPlayer; i++){
        std::string playerName = gameController->askUser("Quelle est votre nom?");      
        Player *p = new Player{playerName, 1};
        playerManager->addPlayer(p);
        gameView->afficher("Le joueur "+ p->getName() + " a rejoins la partie");
    }


    int nbPlayerAI = -1;
    while (nbPlayerAI <0 || nbPlayerAI > 2){
        nbPlayerAI = std::stoi(gameController->askUser("Combien de joueur IA vous en voulez?"));
    }
    for (int i = 0; i < nbPlayerAI; i++){
        std::string playerName = "joueur IA " + std::to_string(i);      
        Player *p = new Player{playerName, 1};
        p->setClassId(1);
        playerManager->addPlayer(p);
        gameView->afficher("Le joueur "+ p->getName() + " a rejoins la partie");
    }

    if(nbPlayerAI + nbPlayer <2){
        gameView->afficher("Il n'y a pas assez de joueur, des IA vont être rajouté");
        while ((nbPlayerAI + nbPlayer)<2){
            std::string playerName = "joueur IA " + std::to_string(nbPlayerAI++);      
            Player *p = new Player{playerName, 1};
            p->setClassId(1);
            playerManager->addPlayer(p);
            gameView->afficher("Le joueur "+ p->getName() + " a rejoins la partie");
            
        }
        
    }

}

bool UnoGameModel::isGameOver()
{ // verifie les conditions de fin de jeu

    for (size_t i = 0; i < playerManager->players.size(); i++){
        if(playerManager->players.at(i)->getHand()->size() == 0){
            currentWinnerId = i;
            return true;
        }
    }
    return false;
}

void UnoGameModel::applyPenalty(){
    if (currentPenalty ==0){
        return;
    }

    for (int i = 0; i < currentPenalty; i++){
        playerManager->getCurrentPlayer()->getHand()->addData(data->draw());
    }
    currentPenalty = 0;
}

void UnoGameModel::countScore(){
    Player * winner = playerManager->getPlayer(currentWinnerId);
    winner->setScore(winner->getScore() + 50);
}

void UnoGameModel::reFill(){
    Carte * last = table->draw();// met de cote la dernier carte de la table
    while (!table->isEmpty()){ // push le tas de carte de la table dans le deck 
        data->addData(table->draw());
    }
    table->addData(last); // remettre en haut la dernier carte sur la table
    data->shuffle();// shuffle le deck de pioche
}


void  UnoGameModel::reset(){
    for (Player * p : playerManager->players){
        p->getHand()->clear();
    }

    currentPenalty = 0;
    //vide la table et le deck de pioche
    table->clear();
    data->clear();
}


void UnoGameModel::CelebrateVictory(){
    gameView->afficher("La partie est terminee, le joueur gagnat est: ");
    gameView->afficher(playerManager->getPlayer(currentWinnerId)->getName());
    gameView->afficher("Il remporte 50 points!!!");
}