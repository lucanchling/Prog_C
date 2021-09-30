/* Fichier: variables.c
* permet d'afficher les différents types de variables
* auteur: Luc Anchling
*/

#include <stdio.h> // headers

int main() {
char my_char_var = 'a';
unsigned char my_uchar_var = 234;
short my_short_var = -12;
unsigned short my_ushort_var = 65535;
int my_int_var = 12;
unsigned int my_uint_var = 3456;
long my_long_var = -1234553L;
unsigned long my_ulong_var = 234556UL;
long long my_llong_var = 1123345LL;
unsigned long long my_ullong_var = 1234567ULL;
float my_float_var = 3.14;
double my_double_var = 3.14E-12;
long double my_long_double_var = 3.14E-22;
printf("%c\n",my_char_var);
printf("%hhu\n",my_uchar_var);
printf("%hd\n",my_short_var);
printf("%hu\n",my_ushort_var);
printf("%d\n",my_int_var);
printf("%u\n",my_uint_var);
printf("%ld\n",my_long_var);
printf("%lu\n",my_ulong_var);
printf("%lld\n",my_llong_var);
printf("%llu\n",my_ullong_var);
printf("%f\n",my_float_var);
printf("%g\n",my_double_var);
printf("%Lg\n",my_long_double_var);
return 0;
}
