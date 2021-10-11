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
    
    // Partie pour déterminer si elle est présente ou non
    printf("\nQuelle valeur souhaitez-vous chercher ?\nValue = ");
    scanf("%d",&value);
    for (int c=0;c<size;c++) {
        if (value==tableau[c]) {    // Si elle est présente on change la valeur du str à afficher
            sortie = "Entier Présent";
        }
    }
    printf("%s\n",sortie);
return 0;
}
