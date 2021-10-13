/* Fichier: chercher_bis.c
* Pemret de générer différents codes couleurs au sein d'un tableau
* auteur: Luc Anchling
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int i=0;
    int booleen=1;  // Variable test égalité phrase
    char catchphrase[200];

    //creation du tableau de phrases
    char *tableau[10] = {"La vie c'est quand même vachement dure\n","T'es mauvais Jack\n","C'est la piquette Jack\n","20 - 0 t'es maauuuuuvvvaiiis Jack\n","What time is it ?\n","II'S GAME TIME\n","Steph from the parking line !!!!\n","BAAANNNNNKKKKSSSSS\n","C'est trop calme, j'aime pas trop beaucoup ça\n","J'préfère quand c'est un peu trop plus moins calme\n"};
    //on demande à l'utilisateur la phrase qu'il cherche
    printf("Quelle phrase cherchez-vous?\n");
    fgets(catchphrase,sizeof(catchphrase),stdin);
    
    //definition des pointeurs
    char *tab_addr = 0;
    char *phrase_addr = &catchphrase[0];
    // Boucle pour faire le test avec l'ensemble des phrases
    for (i=0;i<10;i++){
        tab_addr=tableau[i];
        booleen=1;
        phrase_addr = &catchphrase[0];
        
        while ((*tab_addr!=0) && (*phrase_addr!=0)){
            // Deux lettres différentes --> phrase !=
            if(*tab_addr!=*phrase_addr){  
                booleen=0;
            }
            // Incrémentation pointeurs
            tab_addr++;
            phrase_addr++;
            
        }
        // Deux longueurs de phrases != --> phrase !=
        if ((*tab_addr!=0) || (*phrase_addr!=0)){
            booleen=0;
        }
        // Les meme phrases --> on arrête le programme !
        if (booleen==1){ 
            printf("La phrase est dans la liste\n");
            return (0);
        }
    }
    // le programme n'a pas été arrêté --> phrases !=
    printf("La phrase n'est pas dans la liste\n");
}