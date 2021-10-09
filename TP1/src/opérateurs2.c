/* Fichier: opérateurs2.c
* permet d'appréhender les différents opérateurs avec deux variables
* auteur: Luc Anchling
*/

#include <stdio.h> // headers

int main() {
    int num1 = 5;
    int num2 = 10;
    char op = '*';
    switch (op) {   // Switch pour demander à l'utilisateur quel oppération à effectuer
        case '+':printf("num1+num2%d\n",num1+num2);
        case '-':printf("num1-num2=%d\n",num1-num2);
        case '*':printf("num1*num2=%d\n",num1*num2);
        case '/':printf("num1/num2=%d\n",num1/num2);
        case '%':printf("num1%%num2=%d\n",num1%num2);
        case '&':printf("num1&num2=%d\n",num1&num2);
        case '|':printf("num1|num2=%d\n",num1|num2);
        case '~':printf("num1~num2=%d\n",~(num1));
    }
return 0;
}
