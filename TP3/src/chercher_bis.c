/* Fichier: chercher_bis.c
* Pemret de générer différents codes couleurs au sein d'un tableau
* auteur: Luc Anchling
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int i=0;
    int verif=1;
    char phrase_test[200];

    //creation du tableau de phrases
    char *tableau[10] = {"La vie c'est quand même vachement dure\n","T'es mauvais Jack\n","C'est la piquette Jack\n","20 - 0 t'es maauuuuuvvvaiiis Jack\n","What time is it ?\n","II'S GAME TIME\n","Steph from the parking line !!!!\n","BAAANNNNNKKKKSSSSS\n","C'est trop calme, j'aime pas trop beaucoup ça\n","J'préfère quand c'est un peu trop plus moins calme\n"};
    //on demande à l'utilisateur la phrase qu'il cherche
    printf("Quelle phrase cherchez-vous?\n");
    fgets(phrase_test,sizeof(phrase_test),stdin);
    
    //definition des pointeurs
    char *ptrtableau = 0;
    char *ptrphrase = &phrase_test[0];
 
    for (i=0;i<10;i++){  //on parcourt toutes les phrases du tableau
        ptrtableau=tableau[i]; //on place le pointeur sur le premier caractere de la phrase
        verif=1;
        ptrphrase = &phrase_test[0];
        while ((*ptrtableau!=0) && (*ptrphrase!=0)){  //on parcourt les phrases jusqu'à ce que l'une soit finie
            if(*ptrtableau!=*ptrphrase){  //Si les deux lettres sont differentes
                verif=0; //les phrases sont differentes
            }
            ptrtableau++; //on passe à la lettre suivante
            ptrphrase++; //on passe à la lettre suivante
            
        }
        if ((*ptrtableau!=0) || (*ptrphrase!=0)){  //Si une des phrases se finit avant l'autre
            verif=0;  //les phrases sont differentes
        }
        if (verif==1){  //la phrase est identique a celle testee
            printf("La phrase est dans la liste\n");
            return (0);  //On arrete le programme si on a trouvé la phrase
        }
    }
    printf("La phrase n'est pas dans la liste\n");     //Le programme n'a pas été arrêté donc la phrase n'a pas été trouvée
    return(0);
}