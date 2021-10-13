/* Fichier: chercher.c
* permet de savoir si un entier est présent dans un tableau
* auteur: Luc Anchling
*/

#include<stdio.h>
#include<time.h>
#include <stdlib.h>

int main() {
    
    //Initialisation des variables
    int Taille=20; //taille minimale = 6)
    int tableau[Taille][4];
    int *PTR = &tableau[0][0];
    srand(time(NULL));
    
    //Creation et affichage des termes du tableau (entier aleatoire entre 0 et 255)
    printf("tableau couleur : \n");
    int i,j;
    for(i=0;i<Taille-5;i++){
        for (j=0;j<4;j++){
            *PTR=rand()%256;
            printf("0x%x ",*PTR);
            PTR++;
        }
        printf("\n");
    }

    //On ajoute les 5 derniers termes du tableau manuellement pour s'assurer qu'il y a des couleurs identiques
    for(i=0;i<5;i++){
        for (j=0;j<4;j++){
            *PTR=255;
            printf("0x%x ",*PTR);
            PTR++;
        }
        printf("\n");
    }


    //Creation du tableau final
    int tableau2[Taille][5];

    //Initialisation de la 1ere valeur du tableau2 = On met la 1ere couleur dans la tableau2
    tableau2[0][0]=tableau[0][0];
    tableau2[0][1]=tableau[0][1];
    tableau2[0][2]=tableau[0][2];
    tableau2[0][3]=tableau[0][3];
    tableau2[0][4]=1;
    
    //Initialisation de variables
    int Val1,Val2,Val3,Val4;
    int cpt=1; //Taille des lignes du tableau2
    int modif=0; //bouleen qui passe a 1 si on a fini de traiter une couleur

    //Initialisation des valeurs suivantes
    for(i=1;i<Taille;i++){
        
        //Initialisation des variables tampon
        Val1=tableau[i][0];
        Val2=tableau[i][1];
        Val3=tableau[i][2];
        Val4=tableau[i][3];

        for(j=0;j<cpt;j++){//On parcours les couleurs du tableau final

            if((Val1==tableau2[j][0])&(Val2==tableau2[j][1])&(Val3==tableau2[j][2])&(Val4==tableau2[j][3])){
                //Condition : la couleur existe deja
                tableau2[j][4]++;
                modif=1;
                break;
            }
        }

        if (modif==0){
            //Condition : la couleur n'existe pas encore
            tableau2[cpt][0]=Val1;
            tableau2[cpt][1]=Val2;
            tableau2[cpt][2]=Val3;
            tableau2[cpt][3]=Val4;
            tableau2[cpt][4]=1;
            cpt++;  
        }
        modif=0;    
    }

    //Affichage
    printf("Tableau final : \n");
    for(i=0;i<cpt;i++){
        printf("0x%x  0x%x  0x%x  0x%x  %d\n", tableau2[i][0],tableau2[i][1],tableau2[i][2],tableau2[i][3],tableau2[i][4]);
    }

    return 0;
}
 