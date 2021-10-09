/* Fichier: chaine.c
* Permet de manipuler une chaine de caractère
* auteur: Luc Anchling
*/

#include <stdio.h> // headers


int main() {
    char chaine[] = "Salut";

    // Calcul de la taille de la chaine de caractère
    int size = sizeof(chaine);
    printf("la longueur est de : %d caractère(s)\n",size-1);
    
    // Copie de la chaine dans une autre chaine de caractère
    char chaine2[size];
    for (int cpt=0;cpt<=size;cpt++) {
        chaine2[cpt] = chaine[cpt];
    }
    printf("La copie de la chaine est : %s\n",chaine2);
    
    // Concaténation de deux chaines de caractères
    char c1[] = "Bonjour le monde";
    char c2[] = " Je suis Luc";
    char chaine3[sizeof(c1) + sizeof(c2) -1];   // Définition de la var pour concaténer les 2 chaines
    for (int cpt=0;cpt<sizeof(c1)+sizeof(c2);cpt++) {
        // Dans cette technique il faut absolument éviter le premier '\0' --> ce qui est permis ici !
        if (cpt<=sizeof(c1)) {  // Pour remplir la new var avec le first str
            chaine3[cpt] = c1[cpt];
            }
        if (cpt>sizeof(c1)-1) { // Pour remplir la new var avec le second str
            chaine3[cpt-1] = c2[cpt-sizeof(c1)];
        }
    }
    printf("La concaténation donne la chaine suivante : %s\n",chaine3);
    return 0;
}
