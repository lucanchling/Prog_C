/* Fichier: boucles.c
* permet d'afficher un triangle rectangle de la forme :
    *              
    * *               
    * # *              
    * # # *              
    * * * * *
* auteur: Luc Anchling
*/

// Il faut "décommenter" la boucle pour pouvoir la tester 

#include <stdio.h> // headers



// Partie boucle avec des for
int main() {
int cpt = 10;

for(int a = 1; a <= cpt; a++){  // Première boucle (décalage vertical)
    printf("*");    // Ligne extérieur gauche
    for( int b = 1;b<a;b++) {   // Seconde boucle (décalage horizontal)
        printf(" ");    // Gestion de l'affichage (espacement horizontal)
        if ((a > 2) && (a<cpt) && (b<a-1)) {    // Condition pour remplir le centre avec des #      
            printf("#");
}
        else {  // Pour remplir l'extérieur avec des *
            printf("*");
        }
}
    printf("\n");   // Gedstion de l'affichage (espacement vertical)
}
return 0;
}


/*
// Partie boucle avec des while
int main() {
int cpt = 10;
int a = 1;
while(a <= cpt){  // Première boucle (décalage vertical)
    printf("*");    // Ligne extérieur gauche
    int b = 1;
    while(b < a) {   // Seconde boucle (décalage horizontal)
        printf(" ");    // Gestion de l'affichage (espacement horizontal)
        if ((a > 2) && (a<cpt) && (b<a-1)) {    // Condition pour remplir le centre avec des #      
            printf("#");
}
        else {  // Pour remplir l'extérieur avec des *
            printf("*");
        }
        b++;    // Incrémentation du compteur horizontal
}
    a++;    // Incrémentation du compteur vertical
    printf("\n");   // Gedstion de l'affichage (espacement vertical)
}
return 0;
}

*/
