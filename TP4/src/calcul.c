/* Fichier: calcul.c
* permet de calculer le résultat d'une opération mathématique
* auteur: Luc Anchling
*/

#include "operator.h"
#include <stdio.h>

int main() {
    int a,b;
    char op;
    printf("a = ");
    scanf("%d",&a);
    printf("b = ");
    scanf("%d",&b);
    getchar(); 
    printf("opérateur = ");
    scanf("%c",&op);
    
    switch (op) {   // Switch pour demander à l'utilisateur quel oppération à effectuer
        case '+':{
            printf("a + b = %d\n",additionner(a,b));
            break;
            }
        case '-':{
            printf("a - b = %d\n",soustraire(a,b));
            break;
            }
        case '*':{
            printf("a x b = %d\n",multiplier(a,b));
            break;
            }
        case '/':{
            printf("a / b = %f\n",diviser(a,b));
            break;
            }
        case '%':{
            printf("a %% b = %d\n",modulo(a,b));
            break;
            }
    }
    return 0;
}