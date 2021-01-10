# Projet-POO-M1
Il s'agit d'un projet de bibliothèque de développement de jeu de carte  
Il est parfaitement exploitable pour des jeux de carte avec un deck classique ou des jeux non atypique comme le Uno 


# Environnement
La bibliothèque compile sous Linux(Manjaro) et Windows(10)
Si vous êtes sous windows, beurk, j'y peux rien pour vous

# Commandes du Makefile 
***make library*** -> vérifie et compile si nécessaire notre bibiothèque, elle porte le nom de ***libCardGame.a***  

***$make clean*** -> supprime toutes les fichiers binaires géneré par la compilation  
Si vous rencontrez des problèmes de compilation lié aux binaires ***Keep calm and make clean***  

***$make migrate*** -> mise à jour des headers dans les sous-répertoires
e.g: vous avez modifié la bibiothèque, pour que les sous-répertoire enregistrés prennent en comptent le nouveau .a qui été géneré, vous devez faire cette commande  

# Sous-répertoires de jeux  
Pour tous ces jeux cités en dessous, il existe un Makefile associé voici donc quelques commandes utiles   
***$make run*** -> lance l'exécutable "exec", si l'exécutable n'est pas à jouer, il le met à jour  

***$make exec*** -> compile l'exécutable "exec", si l'exécutable n'est pas à jouer, il le met à jour

***$make clean*** -> supprime toutes les fichiers binaires géneré par la compilation  
Si vous rencontrez des problèmes de compilation lié aux binaires ***Keep calm and make clean***  

***$make update_lib*** -> mise à jour si nécessaire de la bibliothéque

Si vous avez un problème de compilation qui fait 300 lignes, ne paniquez pas  
faites plutôt ->***make clean && make update_lib && make exec***  

## Batailles
Célebre jeux de Batailles qui se joue à 1 contre 1

## Uno 
Célebre jeux de société qui se joue à plusieurs  

## 8Américan
Célebre jeux de société qui se joue à plusieurs  

## Briscola
Célebre jeux de carte Italien
