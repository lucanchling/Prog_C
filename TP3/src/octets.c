/* Fichier: octects.c
* Lecture Octects par Octets 
* auteur: Luc Anchling
*/

#include <stdio.h> // headers

int main() {
    
    // Partie Attribution pointeur & Valeurs
        // Déclaration des différentes variables avec leurs adresses

    // Variable short :
    short my_short_var = -12;
    char *my_short_addr = &my_short_var;

    // Variable int :
    int my_int_var = 12;
    char *my_int_addr = &my_int_var;

    // Variable long int :
    long int my_long_int_var = 1234553;
    char *my_long_int_addr = &my_long_int_var;

    // Variable float :
    float my_float_var = 3.14;
    char *my_float_addr = &my_float_var;

    // Variable double :
    double my_double_var = 3.14E-12;
    char *my_double_addr = &my_double_var;

    // Variable long double :
    long double my_long_double_var = 3.14E-22;
    char *my_long_double_addr = &my_long_double_var;

    // Partie Affichage 
    
    
return 0;
}
