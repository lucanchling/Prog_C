/* Fichier: chercherfichier.c
* permet de chercher une phrase dans un fichier
* auteur: Luc Anchling
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char search_file(char * nom_de_fichier,char * phrase){
    
    // Ouverture du fichier
    FILE* fichier;
    fichier = fopen(nom_de_fichier, "r");

        int iphrase=0;

    //  Lecture des chaines de caracteres
    int C;
    int cpt=0;
    int Ligne=0;

    while(1){
        C=fgetc(fichier);

        //Condition de fin: on a parcouru tout le fichier
        if(C==EOF){
            break;
        }

        //  Cas lettre en commun : on incrémente l'indice de phrase
        if(C==phrase[iphrase]){
            iphrase++;
        }
        
        //  Remise a 0 du mot recherché en cas d'erreur
        else{
            iphrase=0;
        }
        
        //  On a trouvé le mot
        if (iphrase==strlen(phrase)){
            cpt++;
            iphrase=0; //  Reinitialisation du mot recherché
        }

        //  Incrémentation de la ligne et affichage
        if (C=='\n'){
            Ligne++;

            // Partie  Affichage
            if (cpt!=0){
                printf("Mot : %s, Ligne %d, Ocurrence %d\n", phrase, Ligne, cpt);
                cpt=0;
            }
        }
    }

    // Fermeture fichier
    fclose(fichier);

}

// Test pour le fichier test.txt
int main(){
    char * nom_de_fichier = "test.txt";

    search_file(nom_de_fichier, "Bonjour");
    return 0;

}