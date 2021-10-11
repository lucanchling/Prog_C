/* Fichier: grand_petit.c
* permet d'afficher le min et le max d'un tableau
* auteur: Luc Anchling
*/

#include <stdio.h> // headers
#include <stdlib.h>  
#include <time.h>

int main() {
    // Partie Création du tableau
    int size;
    printf("Taille du Tableau ?\nn = ");
    scanf("%d",&size);
    srand(time(NULL));
    int tableau[size];
    // Pour chercher les différentes valeurs
    int min = 99;   // Car la valeur max possible = 99
    int max = 0;    // de même pour le min = 0
    for (int c=0;c<size;c++) {
        tableau[c]=rand()%100;
        printf("%d\t",tableau[c]);

        // Pour le max
        if (tableau[c]>max) {
            max = tableau[c];   // à chaque fois qu'on trouve plus grand on change la valeur du max
        }

        // Pour le min
        if (tableau[c]<min) {
            min = tableau[c];   // idem pour le min
        } 
    }
    printf("\nMax : %d\tMin : %d\n",max,min);
return 0;
}
