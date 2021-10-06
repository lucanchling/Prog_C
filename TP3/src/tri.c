/* Fichier: grand_petit.c
* permet de trier un tableau
* auteur: Luc Anchling
*/

#include <stdio.h> // headers
#include <stdlib.h>  
#include <time.h>

int main() {
    // Partie création de tableau
    int size;
    printf("Taille du Tableau ?\nn = ");
    scanf("%d",&size);
    srand(time(NULL));
    int tab[size];
    printf("Tableau non trié :\n");
    for (int c=0;c<size;c++) {
        tab[c]=rand()%100;
        printf("%d\t",tab[c]);

    }
    printf("\n\n");

    // Partie tri du tableau
    int j;
    for (int i=0;i<size;i++) {
        for (j = 0;j<size-1;j++) {
            int value1 = tab[j];
            int value2 = tab[j+1];
            if (value1>value2) {
                tab[j]=value2;
                tab[j+1]=value1;
            }
        }
    }

    // Affichage du tableau trié
    for (int c=0;c<size;c++) {
        printf("%d\t",tab[c]);
    }
    printf("\n");
    return 0;
}
