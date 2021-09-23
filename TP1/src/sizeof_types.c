/* Fichier: 
* permet d'afficher la taille des différents types de base (en octets).
* auteur: Luc Anchling
*/

#include <stdio.h> // headers

int main() {
printf("Size of char is :\n - for unsigned --> %ld octets\n - for signed --> %ld octets\n\n",sizeof(unsigned char),sizeof(signed char));
printf("Size of short is :\n - for unsigned --> %ld octets\n - for signed --> %ld octets\n\n",sizeof(unsigned short),sizeof(signed short));
printf("Size of int is :\n - for unsigned --> %ld octets\n - for signed --> %ld octets\n\n",sizeof(unsigned int),sizeof(signed int));
printf("Size of long int is :\n - for unsigned --> %ld octets\n - for signed --> %ld octets\n\n",sizeof(unsigned long int),sizeof(signed long int));
printf("Size of long long int is :\n - for unsigned --> %ld octets\n - for signed --> %ld octets\n\n",sizeof(unsigned long long int),sizeof(signed long long int));
printf("Size of float is %ld octets\n\n",sizeof(float));
printf("Size of double is %ld octets\n\n",sizeof(double));
printf("Size of long double is %ld octets\n",sizeof(long double));
return 0;
}
