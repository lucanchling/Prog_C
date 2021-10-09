/* Fichier: puissance.c
* permet de calculer la puissance a^b.
* auteur: Luc Anchling
*/

#include <stdio.h> // headers

int main() {
    int a,b;    // Partie où l'on demande à l'utilisateur de rentrer ses nombres
    printf("Entrez la valeur a : ");
    scanf("%d",&a);
    printf("Entrez la valeur b : ");
    scanf("%d",&b);
    int result = 1;
    for (int cpt = 1; cpt<=b;cpt++) {   // Boucle pour le calcul de la puissance
        result = result*a;  // Incrémentation de la valeur du résultat au fur et à mesure des multiplications
    }
    printf("a^b = %d\n",result);    // Affichage du résultat
    return 0;
}
