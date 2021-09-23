/* Fichier: cercle.c
* permet d'afficher le périmètre et l'aire d'un cercle à l'écran.
* auteur: Luc Anchling
*/

#include <stdio.h> // headers

int main() {
int rayon = 10 ; // Constante
float pi = 3.14 ; // Valeur de Pi
float perimetre = 2*pi*rayon ; // Calcul du périmètre
float aire = pi*rayon*rayon ;
printf("Ce cercle de rayon = %dcm possede :\n - une aire de %fcm\n - un perimetre de %fcm\n",rayon,aire,perimetre);
return 0;
}
