/* Fichier: tableauptr.c
* Manipulation de tableaux en passant par les pointeurs
* auteur: Luc Anchling
*/

#include <stdio.h> // headers
#include <time.h>
#define RAND_MAX 1073741823ULL

int main() {
    // Demande utilisateur pour la taille des tableaux
    int size;
    printf("Taille du Tableau ?\nn = ");
    scanf("%d",&size);
    srand(time(NULL));
    // Partie création des tableaux
    int tabint[size];
    float tabfloat[size];
    printf("Int :\tFloat :\n");
    for (int c=0;c<size;c++) {
        tabint[c]=rand()%100;
        tabfloat[c]=((float)rand()/(float)(RAND_MAX))*100;
        printf("%d\t%f\n",tabint[c],tabfloat[c]);
    }
    printf("\nInt Modified:\tFloat Modified:\n");
    // Partie modification des tableaux en utilisant les pointeurs :
    for (int c = 0;c<size;c++) {
        if ((c%2)==0) { // Si l'indice est un multiple de 2
            *(tabint+c) = *(tabint+c)*3;
            *(tabfloat+c) = *(tabfloat+c)*3;  
        }
        printf("%d\t\t%f\n",tabint[c],tabfloat[c]);   // Affichage des tableaux modified
    }
return 0;
}
