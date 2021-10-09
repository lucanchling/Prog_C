/* Fichier: etudiant2.c
* permet de gérer le dossier de différents étudiants en utilisant struct.
* auteur: Luc Anchling
*/

#include <stdio.h> // headers
#include <stdlib.h>
#include <string.h>

int main() {
    int i,nbetudiant;

    // Demande utilisateur pour le nombre d'étudiants
    printf("Nombre d'étudiants : ");
    scanf("%d",&nbetudiant);
    
    // Création du tableau avec la fonction struct
    struct students {
    char nom[10];
    int noteA;
    } etudiants[nbetudiant];

    // Saisie des informations
    for (i=0;i<nbetudiant;i++) {
        printf("\nPour l'étudiant : %d\n",i+1);
        printf("Quel est son nom : ");
        scanf("%s",etudiants[i].nom);
        printf("Quelle est sa note dans le module A : ");
        scanf("%d",&etudiants[i].noteA);
    }

    // Affichage des informations
    printf("\n -- Affichage des infos --\n");
    for (i=0;i<nbetudiant;i++) {
        printf("\nPour l'étudiant : %d\n",i+1);
        printf("Son nom est : %s\n",etudiants[i].nom);
        printf("Sa note dans le module A est : %d\n",etudiants[i].noteA);
    }
}
