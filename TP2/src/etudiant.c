/* Fichier: etudiant.c
* permet de gérer le dossier de différents étudiants.
* auteur: Luc Anchling
*/

#include <stdio.h> // headers
#include <stdlib.h>
#include <string.h>

#define nbmax 50


int main() {
    // Création du tableau 
    char etudiant[5][5][nbmax] = {
        {"Nom1","Prenom1","ad1","noteA1","noteB1"},
        {"Nom2","Prenom2","ad2","noteA2","noteB2"},
        {"Nom3","Prenom3","ad3","noteA3","noteB3"},
        {"Nom4","Prenom4","ad4","noteA4","noteB4"},
        {"Nom5","Prenom5","ad5","noteA5","noteB5"}
    };
    // demande utilisateur pour avoir une info
    int numetudiant,numinfo;
    printf("Pour quel étudiant ? : ");
    scanf("%d",&numetudiant);
    printf("1 --> Nom\n2 --> Prenom\n3 --> Adresse\n4 --> Note Module A\n5 --> Note Module B\n");
    printf("Quelle info voulez-vous avoir ? : ");
    scanf("%d",&numinfo);
    printf("%s\n",etudiant[numetudiant-1][numinfo-1]);    
    return 0;
}
