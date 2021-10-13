/* Fichier: fichier.c
* permet de manipuler des fichiers en écriture et en lecture
* auteur: Luc Anchling
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void lire_fichier(char *nom_de_fichier) {
    int fd = open(nom_de_fichier,O_RDONLY);
    if (fd == -1) {
        printf("ON A PAS PU OUVRIR LE FICHIER\n");
    }
    while(1) {
        char c[10];
        int size = (int) read(fd,c,1);
        if (size<1) {
            break;
        }
        printf("%s",c);
    }
    printf("\n");
    close(fd);
}

void ecrire_dans_fichier(char *nom_de_fichier, char *message){
    int fd = open(nom_de_fichier, O_WRONLY|O_APPEND);
    int size = write(fd, message,sizeof(message));
    close(fd);
}