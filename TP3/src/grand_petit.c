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
    int min = 99;
    int max = 0;
    printf("Taille du Tableau ?\nn = ");
    scanf("%d",&size);
    srand(time(NULL));
    int tableau[size];
    for (int c=0;c<size;c++) {
        tableau[c]=rand()%100;
        printf("%d\t",tableau[c]);

        // Pour le max
        if (tableau[c]>max) {
            max = tableau[c];
        }

        // Pour le min
        if (tableau[c]<min) {
            min = tableau[c];
        } 
    }
    printf("\n");
    printf("Max : %d\tMin : %d",max,min);
    printf("\n");
return 0;
}
