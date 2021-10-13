/* Fichier: 4_2_main.c
* permet de manipuler des fichiers en écriture et en lecture
* auteur: Luc Anchling
*/

#include <stdio.h>
#include <stddef.h>
#include "fichier.h"

int main() {
    char nom_de_fichier[10];
    printf("Quel fichier voulez-vous ouvrir ?\n");
    scanf("%s",nom_de_fichier);
    printf("Dans le fichier, il y a actuellement :\n");
    lire_fichier(nom_de_fichier);
    char message[10];
    printf("Que voulez-vous ajouter dedans :\n");
    scanf("%s",message);
    ecrire_dans_fichier(nom_de_fichier,message);
    printf("Après ajout de votre message, dans le fichier, il y a actuellement :\n");
    lire_fichier(nom_de_fichier);
    return 0;
}
