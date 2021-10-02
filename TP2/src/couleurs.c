/* Fichier: couleur.c
* Pemret de générer différents codes couleurs au sein d'un tableau
* auteur: Luc Anchling
*/

#include <stdio.h> // headers


int main() {
    printf("Combien de couleurs voulez-vous ?\nNombre de couleurs : ");
    int nbcouleurs;
    scanf("%d",&nbcouleurs);
    
    // Création du tableau
    struct couleur {
        char red[5];
        char blue[5];
        char green[5];
        char alpha[5];
    } coul[nbcouleurs];

    // Partie pour remplir le tableau des couleurs
    for (int c=1;c<=nbcouleurs;c++) {
        printf("Pour la couleur n°%d :\n",c);
        printf("Valeur pour le rouge (Notation Hexa : 0x__): ");
        scanf("\n%s",coul[c].red);
        printf("Valeur pour le vert (Notation Hexa : 0x__): ");
        scanf("\n%s",coul[c].green);
        printf("Valeur pour le bleu (Notation Hexa : 0x__): ");
        scanf("\n%s",coul[c].blue);
        printf("Valeur pour l'alpha (Notation Hexa : 0x__): ");
        scanf("\n%s",coul[c].alpha);
    }

    // Partie pour l'affichage du tableau des couleurs
    for (int c=1;c<=nbcouleurs;c++) {
        printf("Pour la couleur n°%d :\n",c);
        printf("(r : %s, ",coul[c].red);
        printf("g : %s, ",coul[c].green);
        printf("b : %s, ",coul[c].blue);
        printf("a : %s)",coul[c].alpha);
        printf("\n");
    }

    return 0;
}
