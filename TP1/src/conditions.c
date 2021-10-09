/* Fichier: Conditions.c
* permet de déterminer les nombre divisibles ou non par certain nombres
* auteur: Luc Anchling
*/

#include <stdio.h> // headers

int main() {
    printf("Quelle condition voulez-vous exécuter ?\nLa condition (a,b ou c) : ");
    char sw;
    scanf("%c",&sw);
    switch (sw) {   // Utilisation d'un switch pour demander la question à exécuter à l'utilisateur
        // Partie condition A
        case 'a' : {
            int nb = 0;
            while(nb <= 1000) { // Boucle while pour tester tous les nbs jusqu'à 1000
                if ((nb%2==0) && (nb%15==0)) {  // Test de la condition pour chacun des nbs
                    printf("%d\n",nb);  // Affichage du nb s'il respecte la condition
                }
                nb++;   // Incrémentation du nb à tester
            }
            break;
        }
        case 'b' : {
        // Partie condition B
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
        // Partie condition C
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
