/* Fichier: bits.c
* permet de vérifier si certain bits sont à 1 ou pas sur un entier d.
* auteur: Luc Anchling
*/

#include <stdio.h> // headers
#include <math.h>

int main() {
    int d;    // Partie où l'on demande à l'utilisateur de rentrer la valeur de d
    printf("Entrez la valeur d : ");
    scanf("%d",&d);
    int r4,r20; // définitions des 2^n pour vérification des bits
    r4 = d/pow(2,3);    // Pour le bit 4
    r20 = d/pow(2,19);  // Pour le bit 20
    r4 = r4 & 1;    // Pour vérifier si il est à un ou pas
    r20 = r20 & 1;  // idem
    printf("Vérification : %d\n",r4&r20);   // Vérification global voulue par l'exo
    return 0;
}
