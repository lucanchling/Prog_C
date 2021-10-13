/* Fichier: couleur_compteurs.c
* Pemret de générer différents codes couleurs au sein d'un tableau
* auteur: Luc Anchling
*/

#include <stdio.h> // headers

// Création du tableau
struct couleur {
    char red;
    char blue;
    char green;
    char alpha;
} color[10];

int main() {
    // Partie pour remplir le tableau des couleurs
    

    for (int i = 1;i<=10;i++) {
        printf("%d\t%d\t%d\t%d\t",color[i].red,color[i].blue,color[i].green,color[i].alpha);
    }

    return 0;
}
