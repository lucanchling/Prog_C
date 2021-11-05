/* Fichier: factorielle.c
* permet de calculer la factorielle d'un entier
* auteur: Luc Anchling
*/

#include <stdio.h>

int factorielle (int num) {
  if (num == 0) {
    return 1;
  }
  else {
    return (num * factorielle (num-1));
  }
}

// Pour lancer la fonction factorielle
int main() {
    int a;
    printf("a = ");
    scanf("%d",&a);
    printf("!a = %d\n",factorielle(a));
    return 0;
}