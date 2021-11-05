/* Fichier: liste.c
* permet d'insérer une couleur dans une liste à l'aide d'un pointeur
* auteur: Luc Anchling
*/

#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include "liste.h"

int main(){

    //Initialisation des variables
    int size=10; 
    srand(time(NULL));

    //Initialisation des couleurs a la structure
    struct couleur Couleurs[size];
    
    //Creation des couleurs (entier aleatoire entre 0 et 255) via la structure
    int i;
    for(i=0;i<size;i++){
        Couleurs[i].rouge = rand()%256;
        Couleurs[i].vert = rand()%256;
        Couleurs[i].bleu = rand()%256;
        Couleurs[i].alpha = rand()%256;           
    }

    //Initialisation de la liste des couleurs (first et last)
    struct liste_couleur liste_couleur;
    liste_couleur.first.next = &liste_couleur.last;
    liste_couleur.last.prev = &liste_couleur.first;
    liste_couleur.first.prev = NULL;
    liste_couleur.last.next = NULL;

    
    //Ajout des couleurs a la liste chainée par la fonction insertion
    int j;
    for(j=0;j<size;j++){
        insertion(&Couleurs[j], &liste_couleur);
    }

    //Affichage par la fonction parcours
    parcours (&liste_couleur);

    return 0;

}

//Fonction insertion couleur dans la liste chainée
void insertion (struct couleur *new, struct liste_couleur * liste_couleur){

    //Creation de la liaision next de nouvelle couleur : nouvelle couleur -> Couleur suivante (1)
    new -> next = liste_couleur -> first.next;
    //Creation de la liaision prev de nouvelle couleur : Couleur précedente (first) <- nouvelle couleur
    new -> prev = &liste_couleur -> first;
    //Modification de la liaision prev de couleur suivante (1) : nouvelle couleur <- couleur suivante (1)
    liste_couleur -> first.next -> prev = new;
    //Modification de la liaision next de couleur precédente (first) :  couleur precédente (first) -> nouvelle couleur
    liste_couleur -> first.next = new;

}


//Fonction parcours et affichage de la liste chainée
void parcours (struct liste_couleur *liste_couleur){

    //Initialisation de la premiere couleur
    struct couleur * Coul = liste_couleur->first.next;

    while (Coul != &liste_couleur->last){
        //Affichage
        printf("%d, %d, %d, %d\n", Coul->rouge, Coul->vert, Coul->bleu, Coul->alpha);
        //Element suivant
        Coul = Coul ->next;
    }

}