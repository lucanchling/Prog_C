/* Fichier: Conditions.c
* permet de déterminer les nombre divisibles ou non par certain nombres
* auteur: Luc Anchling
*/

#include <stdio.h> // headers

int main() {
char sw = 'c';
switch (sw) {
    case 'a' : {
        int nb = 0;
        while(nb <= 1000) {
            if ((nb%2==0) && (nb%15==0)) {
                printf("%d\n",nb);
            }
            nb++;
        }
        break;
    }
    case 'b' : {
        int nb = 0;
        while(nb <= 1000) {
            if ((nb%103==0) || (nb%107==0)) {
                printf("%d\n",nb);
            }
            nb++;
        }
        break;
    }
    case 'c' : {
        int nb = 0;
        while(nb <= 1000) {
            if ((nb%7==0) || (nb%5==0)) {
                if (nb%3!=0) {
                printf("%d\n",nb);
            }}
            nb++;
        }
        break;
}}
return 0;
}
