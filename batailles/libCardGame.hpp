#ifndef HPP_GAMELIB
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

class CollectionCarte;
class PlayerManager;
class GameModel;
class GameView;
class GameController;


/*
    * Parseur -> classe qui permet de lire un fichier .txt et de le 'parser' en matrice de string (vecteur<vecteur<string>>)
*/
class Parseur{
private:
    std::string filename;
    int nb_column; 
    mutable std::vector<std::vector<std::string>> lignes;
    const bool strict_reading;
    char delim{','};

public:
    Parseur();
    Parseur(std::string filename, const int nb_column, const bool strict = true);
    virtual ~Parseur();
    virtual std::vector<std::string> split(const std::string s, const char delim);
    
    //affiche le contenue de lignes
    virtual void print_lines() const;
    virtual std::vector<std::vector<std::string>> get_lignes();
    virtual void setFilename(std::string fn);
    virtual void setNbColumn(int nb);
    virtual void parse();
};


/*
    * La classe fondamentale qui représente comme nom l'indique, une carte
    * elle peut être hérité afin d'utiliser le polymorphisme ave les autres classes
*/
class Carte
{
private:
protected:
    std::string name;
    std::vector<std::string> attributs;
    int status; //face caché ou autres choses
    int value; // valeur mis à defaut à 0 dans le constructeur de Carte, ça permet d'écrire plus facilement les fct de comparaison si besoin
    
public:
    virtual void setName(std::string str);
    virtual std::string getAttribut(int pos);
    virtual void addAttribut(std::string name);
    virtual int getStatus();
    virtual void setStatus(int val);
    virtual int getValue();
    virtual void setValue(int val);
    virtual ~Carte();
    virtual std::string toString() const;
    friend const std::ostream& operator<<(std::ostream& out, const Carte& mat);
    virtual std::string getName()const;
    // l'opérateur de base fait juste une comparaison sur l'attibut [name], si vous avez besoin d'une comparaison plus strict, héritez et implémenter la
    virtual int operator==(Carte second);
    virtual int operator==(std::string name);
    Carte();
    Carte(std::string name, int status =0, int value = 0);

};

/*
    * CollectionCarte-> est notre container de préference afin de stocker des cartes ou leurs classe fils
*/
class CollectionCarte
{
protected:
    std::vector<Carte *> data;

public:
    CollectionCarte(){};
    virtual ~CollectionCarte();
    virtual void addData(Carte *c);

    //supprime la carte qui correspond au critères et libére sa memoire
    virtual int deleteData(Carte* c);
    virtual int deleteDataByName(std::string name);
    virtual int deleteData(Carte *c, int (*compareFunction)(Carte* first, Carte* second));
    virtual int deleteData(int pos);
    
    //supprime la carte du vecteur data et la retourne en valeur de retour, la memoire n'est pas supprimé
    virtual Carte * draw();
    virtual Carte * draw(int pos);
    virtual Carte * drawRandom();

    virtual int size()const;
    virtual Carte * operator [](int pos)const;
    virtual Carte* at(int pos);
    virtual Carte* first();
    virtual Carte* last();
    virtual std::string toString()const;
    virtual bool isEmpty()const;
    //supprime l'intégralité du contenue du vecteur data et libére la mémoire associé
    virtual void clear();
    virtual void shuffle();
    virtual void insertData(Carte *c, int pos);
    virtual void insertFront(Carte *c);

};


/*
    * Player -> classe de base pour représenter un joueur,
    * Par défaut, il ne possède qu'une seule 'hand', si vous avez besoin que le joueur stock plus de collection de carte,
    * héritez et crée votre class fils
*/
class Player{
protected:
    std::string name;
    int status;
    int classId;
    int score;
    CollectionCarte * hand;

public:
    virtual ~Player();
    Player(std::string _name, int _status = 1, int _classId = 0, int _score =0 );
    virtual std::string getName()const;
    void setName(std::string str);
    void setStatus(int val);
    void setClassId(int val);
    void setScore(int val);
    int getStatus();
    int getClassId();
    int getScore();
    CollectionCarte* getHand();
    friend PlayerManager;
    std::string toString() const;
    friend const std::ostream& operator<<(std::ostream& out, const Player& p);

};


/*
    * PlayerManager -> classe container pour stocker et gérer les classes Player
    * il permet notamment de garder l'indice du joueur qui est entrain de jouer, l'indice du joueur précedent
    * le passage au prochain joueur, changement de sens de jeu
    * 
*/
class PlayerManager{
protected:
public:
    PlayerManager();
    virtual ~PlayerManager();
    std::vector<Player *> players;
    // indice du joueur dans le vecteur players qui joue actuellement
    int currentPlayer;
    // indice du joueur dans le vecteur players qui jouais précedent
    int lastPlayer;
    // la direction de jeu [1]-> croissant [-1] -> décrossaint
    int direction;
    int step;
    virtual Player* getCurrentPlayer();
    virtual Player* getPlayer(int pos);
    virtual Player* getLastPlayer();   
    // change le sens de jeu  
    virtual  void swapDirection();
    
    // change le nombre de saut à effectuer au prochain rotation de joueur, par defaut il faut [1], 
    // e.g pour faire sauter le tour du prochain joueur, vous pouvez faire setStep(2)
    // le changement n'est valide pour une seule utilisation, après ce saut, il reviens à la valeur de défaut qui est 1
    virtual void setStep(unsigned int s);

    // pass au joueur suivant qui doit jouer, et change les valeurs currentPlayer lastPlayer avec la bonne valeur 
    virtual void rotateToNext();
    virtual void addPlayer(Player *p);
    virtual int nbPlayers();
    friend GameModel;
};


/**
 * Interface Composante Model du MVC 
 * vous devrez implémenter la méthode pushDataFromStrLine pour l'utiliser
**/
class GameModel{
protected:
    CollectionCarte * data;
    PlayerManager * playerManager;
    GameView * gameView;
    GameController * gameController;
    
public:
    GameModel();

    /**
     * Instancie les données avec avec la matrice de string
     * @param configData : la matrice de string à utiliser, prévilégiez notre classe Parseur et faite [paseurs.get_lignes()]
     * la méthode a besoin que pushDataFromStrLine soit instancié afin d'être utilisable
    */
    virtual int initGameData(std::vector<std::vector<std::string>> configData);
    virtual CollectionCarte* getDataCollection();
    virtual PlayerManager* getPlayerManager();

    /**
     * Lis un vecteur de string, crée les données de cartes associé et le met dans data
     * @param line : cela correspond à un ligne de la matrice lue
    */
    virtual void pushDataFromStrLine(std::vector<std::string> line) = 0;

    /**
     * initialise les joueurs 
    */
    virtual void initPlayers();
    /**
     * lance le jeu 
    */
    virtual void startGame();
    virtual void countScore();
    virtual bool isGameOver();

    /**
     * attacher à notre modèle les composantes associé
    */
    virtual void attach(GameView * gv);
    virtual void attach(GameController * gc);
    
};


/**
 * La classe Controller du modèle MVC
 * il est utilisable en tant que telle
*/
class GameController
{
private:
public:
    GameController();
    virtual ~GameController();
    /**
     * demande une entrée au joueur, ici, cela correspond à une entrée dans le terminal
     * @return la chaine de charactère que viens d'entrer l'utilisateur
    */
    virtual std::string getUserInput();
    /**
     * version plus évolué de getUserInput(), elle affiche une question dans le terminale et demande la réponse de l'utilisateur
     * @param question : la question qui doit être posé au joueur
     * @return la chaine de charactère que viens d'entrer l'utilisateur
     * ! warning, la question est affiché dans le terminal avec std::cout
     * dans l'idéal, il faudrait associer un gameView et l'afficher avec la méthode du gameView
    */
    virtual std::string askUser(std::string question);

    /**
     * Affiche une liste de choix possible et demande à l'utilisateur d'en choisir un
     * @param commandString : vecteur qui contient les string de choix à afficher
     * @return : le choix choisit par l'utilisateur, si c'est la première string du vecteur elle retourneras alors 0 par exemple
     * ! warning, les choix sont affichés dans le terminal avec std::cout
     * dans l'idéal, il faudrait associer un gameView et l'afficher avec la méthode du gameView
    */
    virtual int askCommandString(std::vector<std::string> commandStrings);

};


/**
 * la classe View du modèle MVC
 * elle est peu developpé car c'est plus à au developpeur de décider comment il souhaite afficher les données
*/
class GameView
{
protected:
public:
    /** affiche une message
     * @msg le message à afficher
     * ! warning , la méthode initiale utilise std::cout et l'affiche au terminal
     * si vous avez besoin d'une affichage plus complex, faudra alors implémenter votre propre classe
    */
    virtual void afficher(std::string msg); 
    GameView();
    virtual ~GameView();
};


/**
 * Patron de pour la classe Command, qui correspond à un pattern Command 
*/
class Command{
protected:
    GameModel * gameModel;
    GameController * gameController;
    GameView * gameView;
public:
    Command(GameModel * gm = nullptr, GameController * gc = nullptr, GameView * gv = nullptr);
    virtual ~Command();
    virtual void run();
};


#endif
