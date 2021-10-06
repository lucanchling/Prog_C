/* Fichier: chercher.c
* permet de savoir si un entier est présent dans un tableau
* auteur: Luc Anchling
*/

#include <stdio.h> // headers
#include <stdlib.h>  
#include <time.h>

int main() {
    // Partie Création du tableau
    int size,value;
    char *sortie = "Entier non Présent";
    printf("Taille du Tableau ?\nn = ");
    scanf("%d",&size);
    srand(time(NULL));
    int tableau[size];
    for (int c=0;c<size;c++) {
        tableau[c]=rand()%100;
        printf("%d\t",tableau[c]);
    }
    printf("\nQuelle valeur souhaitez-vous chercher ?\nValue = ");
    scanf("%d",&value);
    for (int c=0;c<size;c++) {
        if (value==tableau[c]) {
            sortie = "Entier Présent";
        }
    }
    printf("%s\n",sortie);
return 0;
}
