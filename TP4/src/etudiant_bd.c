/* Fichier: etudiant_bd.c
* permet de gérer le dossier de différents étudiants en utilisant struct.
* auteur: Luc Anchling
*/

#include <stdio.h> // headers
#include <stdlib.h>
#include <string.h>
#include "fichier.h"


// Création du tableau avec la fonction struct
struct students {
    char nom[20];
    char prenom[20];
    char adresse[50];
    char ville[25];
};

int main() {
    
    struct students etudiants[3];

    strcpy(etudiants[0].prenom,"Luc");
    strcpy(etudiants[0].nom,"ANCHLING");
    strcpy(etudiants[0].adresse,"12 avenue de Lyon");
    strcpy(etudiants[0].ville,"Villeurbanne");

    strcpy(etudiants[1].prenom,"Timothée");
    strcpy(etudiants[1].nom,"TEYSSIER");
    strcpy(etudiants[1].adresse,"11 Route de la déprime");
    strcpy(etudiants[1].ville,"Lyon");

    strcpy(etudiants[2].prenom,"Marie");
    strcpy(etudiants[2].nom,"ARNAUD");
    strcpy(etudiants[2].adresse,"20 Boulevard de la Joie");
    strcpy(etudiants[2].ville,"Lyon");

    char *nom_de_fichier = "etudiant.txt";
    for (int i = 0; i<3;i++) {
        char *message = etudiants[i].prenom;
        ecrire_dans_fichier(nom_de_fichier,message);
        ecrire_dans_fichier(nom_de_fichier,", ");
        message = etudiants[i].nom;
        ecrire_dans_fichier(nom_de_fichier,message);
        ecrire_dans_fichier(nom_de_fichier,", ");
        message = etudiants[i].adresse;
        ecrire_dans_fichier(nom_de_fichier,message);
        ecrire_dans_fichier(nom_de_fichier," ");
        message = etudiants[i].ville;
        ecrire_dans_fichier(nom_de_fichier,message);
        ecrire_dans_fichier(nom_de_fichier,"\n");
    }

    printf("Dans le fichier, il y a actuellement :\n");
    lire_fichier(nom_de_fichier);
}
