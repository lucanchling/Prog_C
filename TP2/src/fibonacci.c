/* Fichier: fibonacci.c
* permet d'écrire la suite de Fibonacci
* auteur: Luc Anchling
*/

#include <stdio.h> // headers
#include <math.h>

int main() {
    // Initialisation des premiers termes
    int u0,u1,n;    
    u0=1;u1=1;
    // Demande utilisateur --> nb de termes
    printf("Entrez le nombre de termes de la suite : ");
    scanf("%d",&n);
    // Affichage des premiers termes
    printf("%d\t",u0);
    printf("%d\t",u0);
    // Partie gestion de la suite de Fibonacci
    long long int un,unplus1,unplus2;
    un=u0;unplus1=u1;
    // Calcul des différents termes de la suite
    for (int cpt=0; cpt<n-2; cpt++) {
        unplus2 = un+unplus1;
        un=unplus1;
        unplus1=unplus2;
        printf("%lli\n",unplus2);
    }
    return 0;
}
