/* Fichier: binaire.c
* permet d'afficher un entier en binaire
* auteur: Luc Anchling
* rajouter -lm pour l'exécution
*/

#include <stdio.h> // headers
#include <math.h>
#include <stdlib.h>


int main() {
    // Demande utilisateur pour l'entier à convertir en binaire
    printf("Quel entier voulez-vous afficher en format binaire ?\nVotre nombre entier : ");
    int entier;
    scanf("%d",&entier);
    
    int racine = floor(sqrt(entier))+1;
    // Pour déterminer le nombre de bits par la méthode des puissances de 2
    int nbbits;
    for (int c = 0;c<=racine;c++ ) {
        int mul2 = pow(2,c);
        if (entier<mul2) {     // 2^n > entier --> n = nbits
            nbbits = c;
            break;
        }
    }
    
    // Cas entier = 0 :
    if (entier==0) {
        printf("Nombre de Bits : %d\n",1);
        printf("%d\n",entier);
    }

    // Cas général
    else {
    // Création du tableau pour écrire le code binaire
    struct binaire {
        int n;
    } bits[nbbits];

    printf("Nombre de Bits : %d",nbbits);   // Affichage du nombre de bits

    // Partie pour le calcul du code binaire
    for (int cpt=nbbits-1;cpt>=0;cpt--) {
        // Par la méthode des divisdsions euclidiennes successives par 2 
        int quotient = entier/2;
        int reste = entier%2;
        entier = quotient;
        bits[cpt].n = reste;    // Remplissage d'un tableau pour gérer l'affichage du code binaire
    }

    // Permet l'affichage dans le bon sens
    printf("\n");
    for (int c=0;c<nbbits;c++) {
        printf("%d ",bits[c].n);
    }

    printf("\n");
    }
return 0;
}
