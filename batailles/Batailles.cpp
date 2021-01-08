#include "batailles.hpp"

MyGameModel::MyGameModel()
{
}

MyGameModel::~MyGameModel()
{
}

void MyGameModel::startGame(){
    
    data->shuffle();
    while (!data->isEmpty()){//tant que le deck n'est pas vide
        //tirer une carte, la donner au joueur qui joue, puis passer au joueur suivant
        //std::cout<<"current player is : "<<playerManager->currentPlayer<<std::endl;
        playerManager->getCurrentPlayer()->getHand().addData(data->draw());
        playerManager->rotateToNext();   
        //std::cout<<"next player is : "<<playerManager->currentPlayer<<std::endl;
    }
}

void MyGameModel::countScore(){

}


void MyGameModel::pushDataFromStrLine(std::vector<std::string> line){
    
    //cout<<"Dealing with line content: ";
    //for (auto word : line){ std::cout<< word +", ";}
    //cout<<std::endl;
    
    // Creer ici votre class de carte
    for (int i = 0; i < stoi(line[0]); i++){
        Carte * result = new Carte(line[1]);
        result->addAttribut(line[2]);
        result->addAttribut(line[3]);
        data->addData(result);
    }
}

void MyGameModel::initPlayers(){
    Player* p1 = new Player{"joueur 1",1};
    Player* p2 = new Player{"joueur 2",1};
    playerManager->addPlayer(p1);
    playerManager->addPlayer(p2);
}

bool MyGameModel::isGameOver(){ // verifie les conditions de fin de jeu
    for (Player * p : playerManager->players){
        if(p->getHand().size() == 0) 
            return true;
    }
    
}


Batailles::Batailles(): parseur(Parseur("BataillesConfig32.txt", 4)){
    //parseur.print_lines();
    gameModel.data = new CollectionCarte();
    gameModel.initGameData(parseur.get_lignes());
    gameModel.playerManager = new PlayerManager();
    gameModel.initPlayers();
    std::cout<<gameModel.playerManager->getCurrentPlayer()->toString();

}

Batailles::~Batailles()
{
}

void Batailles::start(){
    gameModel.startGame();// distribuer les cartes au joueurs
    //decommenter pour voir la distribution
    /*
    std::cout<<gameModel.playerManager->getPlayer(0)->getHand().toString();
    std::cout<<"===========================\n";
    std::cout<<gameModel.playerManager->getPlayer(1)->getHand().toString();
    */
    bool bataille = false;
    while(!gameModel.isGameOver()){

        std::vector<Carte *> stack;
        
        Player * lastPlayer = nullptr;

        for (Player* player: gameModel.playerManager->players){
            std::cout<<"\nRound of player : " << player->getName()<<std::endl;
            gameView.afficher("Player has draw :"); // affichage a faire
            if(player->getHand().isEmpty()){
                continue;
            }
            Carte * out = player->getHand().draw();
            gameView.afficher(out->toString()); // affichage a faire

            if (stack.empty() || bataille){
            // si la pile est vide ou il y a eu "bataille" dans le round predecedent
                stack.push_back(out);
                bataille = false;
                lastPlayer = player;
            }else{
                std::cout<<"\ncomparaison en cours ...\n";
                int diff = compare(stack.back(), out);
                std::cout<< "result of diff : "<<diff <<std::endl;
                if(diff == 0){// bataille
                    std::cout<<"Batailles !!"<<std::endl;
                    bataille = true;
                    stack.push_back(out);
                }else if(diff >0){ // le joueur gagne
                    bataille = false; 
                    gameModel.TakeStack(stack, player);
                    lastPlayer = player;
                }else{ // diff < 0
                    bataille = false;
                    gameModel.TakeStack(stack, lastPlayer);
                    lastPlayer = player;
                }

            }
            
            
            
            //std::string userInput = gameController.getUserInput(); // verifier si l'entree est valide
            //std::getchar(); //faire une pause
            gameModel.playerManager->rotateToNext();
        }
        
    }

    std::cout<<"GAME OVER\n";
    
}

/* compare 2 cartes:
    -> negatif si first < second
    -> positif si first >= second
*/
int compare(Carte * first, Carte * second){

    std::map<std::string, int> order;
    order["2"] = 2;
    order["4"] = 4;
    order["5"] = 5;
    order["6"] = 6;
    order["7"] = 7;
    order["8"] = 8;
    order["9"] = 9;
    order["10"] = 10;
    order["V"] = 11;
    order["D"] = 12;
    order["R"] = 13;
    order["A"] = 14;

    //std::cout<<"premier :" <<first->getName()<< "\t deuxieme " <<second->getName();
    //std::cout<<" result = " << order[first->getName()] - order[second->getName()];
    return order[first->getName()] - order[second->getName()];

}


void MyGameModel::TakeStack(std::vector<Carte *>& stack, Player * player){

}