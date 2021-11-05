/* Fichier: fichier.c
* permet de manipuler des fichiers en écriture et en lecture
* Fonctionne avec le fichier main 4_2_main.c
* auteur: Luc Anchling
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


void lire_fichier(char *nom_de_fichier) {
    int fd = open(nom_de_fichier,O_RDONLY); // Pour ouvrir le fichier en lecture
    // COndition si le fichier n'existe pas
    if (fd == -1) {
        printf("ON A PAS PU OUVRIR LE FICHIER\n");
    }
    // Boucle pour lire l'intégralité du fichier
    while(1) {
        char c[50]; // Déclaration variable pour lire caractère par caractère
        int size = read(fd,c,1);    // Pour récupérer le caractère
        if (size<1) {   // Lorsque l'on est à la fin du fichier pour s'arreter de lire
            break;
        }
        printf("%s",c); // Affichage du caractère
    }
    printf("\n");
    close(fd);  // Pour fermer le fichier
}

void ecrire_dans_fichier(char *nom_de_fichier, char *message){
    int fd = open(nom_de_fichier, O_WRONLY|O_APPEND);   // Pour ouvrir le fichier en écriture en mode append (pour rajouter le message à la fin) 
    int size = write(fd, message,strlen(message));  // Ecriture dans le fichier du message
    close(fd);  // Fermeture du fichier
}