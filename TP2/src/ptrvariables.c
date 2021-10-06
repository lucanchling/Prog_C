/* Fichier: ptrvariables.c
* Affiche des variables à partir de leur adresse en utilisant les pointeurs 
* auteur: Luc Anchling
*/

#include <stdio.h> // headers

int main() {
    // Déclaration des différentes variables avec leurs adresses
    
    // Variable char :
    char my_char_var = 'a';
    char *my_char_addr = &my_char_var;

    // Variable short :
    short my_short_var = -12;
    short *my_short_addr = &my_short_var;

    // Variable int :
    int my_int_var = 12;
    int *my_int_addr = &my_int_var;

    // Variable long int :
    long int my_long_int_var = 1234553;
    long int *my_long_int_addr = &my_long_int_var;

    // Variable long long int :
    long long int my_llong_int_var = 1123345678910;
    long long int *my_llong_int_addr = &my_llong_int_var;

    // Variable float :
    float my_float_var = 3.14;
    float *my_float_addr = &my_float_var;

    // Variable double :
    double my_double_var = 3.14E-12;
    double *my_double_addr = &my_double_var;

    // Variable long double :
    long double my_long_double_var = 3.14E-22;
    long double *my_long_double_addr = &my_long_double_var;

    // Partie Affichage en utilisant les pointeurs :
    printf("Pour la variable de type char : \n");
    printf("addr : %p\tvalue : %c\taddr : \n", my_char_addr,*my_char_addr);
    printf("Pour la variable de type short : \n");
    printf("addr : %p\tvalue : %hd\n", my_short_addr,*my_short_addr);
    printf("Pour la variable de type int : \n");
    printf("addr : %p\tvalue : %d\n", my_int_addr,*my_int_addr);
    printf("Pour la variable de type long int : \n");
    printf("addr : %p\tvalue : %ld\n", my_long_int_addr,*my_long_int_addr);
    printf("Pour la variable de type long long int : \n");
    printf("addr: %p\tvalue : %lld\n", my_llong_int_addr,*my_llong_int_addr);
    printf("Pour la variable de type float : \n");
    printf("addr : %p\tvalue : %f\n", my_float_addr,*my_float_addr);
    printf("Pour la variable de type double : \n");
    printf("addr : %p\tvalue : %g\n", my_double_addr,*my_double_addr);
    printf("Pour la variable de type long double : \n");
    printf("addr : %p\tvalue : %Lg\n", my_long_double_addr,*my_long_double_addr);
return 0;
}
