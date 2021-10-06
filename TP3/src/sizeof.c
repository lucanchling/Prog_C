/* Fichier: sizeof.c
* permet d'afficher la taille des différents types de base (en octets).
* auteur: Luc Anchling
*/

#include <stdio.h> // headers

int main() {
    printf("%ld\n",sizeof(int));
    printf("%ld\n",sizeof(int*));
    printf("%ld\n",sizeof(int**));
    printf("%ld\n",sizeof(char*));
    printf("%ld\n",sizeof(char**));
    printf("%ld\n",sizeof(char***));
    printf("%ld\n",sizeof(float*));
    printf("%ld\n",sizeof(float**));
    printf("%ld\n",sizeof(float***));
return 0;
}
