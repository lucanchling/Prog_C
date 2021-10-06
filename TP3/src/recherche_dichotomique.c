/* Fichier: recherche_dichotomique.c
* permet de savoir si un entier est présent dans un tableau par méthode dichotomique
* auteur: Luc Anchling
*/

#include <stdio.h> // headers
#include <stdlib.h>  
#include <time.h>
#include <math.h>

int main() {

    // Partie Création du tableau
    int size,value;
    printf("Taille du Tableau ?\nn = ");
    scanf("%d",&size);
    srand(time(NULL));
    int tab[size];
    for (int c=0;c<size;c++) {
        tab[c]=rand()%100;
        printf("%d\t",tab[c]);
    }

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
    
    // Demande utilisateur Valeur à chercher :
    printf("\nQuelle valeur souhaitez-vous chercher ?\nValue = ");
    scanf("%d",&value);

    // Recherche Dichotomique :
    int start = 0;
    int end = size;
    int mil;
    char *sortie = "Entier non Présent";
    while ((sortie!="Entier Présent") & (start<=end)) {
        mil = floor((end+start)/2);
        if (value==tab[mil]) {
            sortie = "Entier Présent";
        }
        else {
            if (value>tab[mil]) {
                start = mil + 1;
            }
            else {
                end = mil - 1;
            }
        }
    }
    printf("%s\n",sortie);
return 0;
}
