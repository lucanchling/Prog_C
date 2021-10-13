/* Fichier: octets.c
* Lecture Octects par Octets 
* auteur: Luc Anchling
*/

#include <stdio.h> // headers

int main() {
    
    // Partie Attribution pointeur & Valeurs
        // Déclaration des différentes variables avec leurs adresses

    // Variable short :
    short my_short_var = 55;
    unsigned char *my_short_addr = (unsigned char*)&my_short_var;

    // Variable int :
    int my_int_var = 12;
    unsigned char *my_int_addr = (unsigned char*)&my_int_var;

    // Variable long int :
    long int my_long_int_var = 1234553;
    unsigned char *my_long_int_addr = (unsigned char*)&my_long_int_var;

    // Variable float :
    float my_float_var = 3.14;
    unsigned char *my_float_addr = (unsigned char*)&my_float_var;

    // Variable double :
    double my_double_var = 3.14E-12;
    unsigned char *my_double_addr = (unsigned char*)&my_double_var;

    // Variable long double :
    long double my_long_double_var = 3.14E-22;
    unsigned char *my_long_double_addr = (unsigned char*)&my_long_double_var;

    // Partie Affichage 
    printf("Pour la variable short :\n");
    for (int i = 0;i<sizeof(short);i++) {
        printf("%hhx ",*(my_short_addr+i)); // Affichage en hexa des différents octets en utilisant le pointeur
    }

    printf("\nPour la variable int :\n");
    for (int i = 0;i<sizeof(int);i++) {
        printf("%hhx ",*(my_int_addr+i));
    }

    printf("\nPour la variable long int :\n");
    for (int i = 0;i<sizeof(long int);i++) {
        printf("%hhx ",*(my_long_int_addr+i));
    }

    printf("\nPour la variable float :\n");
    for (int i = 0;i<sizeof(float);i++) {
        printf("%hhx ",*(my_float_addr+i));
    }

    printf("\nPour la variable double :\n");
    for (int i = 0;i<sizeof(double);i++) {
        printf("%hhx ",*(my_double_addr+i));
    }

    printf("\nPour la variable long double :\n");
    for (int i = 0;i<sizeof(long double);i++) {
        printf("%hhx ",*(my_long_double_addr+i));
    }
    printf("\n");
return 0;
}
