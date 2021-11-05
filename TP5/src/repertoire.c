/* Fichier: repertoire.c
* permet de parcourir le dossier et d'afficher les noms des fichiers
* auteur: Luc Anchling
*/

#include<stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include"repertoire.h"

void lire_dossier(char *rep) {
	DIR *dp;
	dp = opendir(rep);
	if (dp==NULL) {
		return;
	}

	struct dirent *dirp;
	
	while(1) {
		dirp = readdir(dp);
		if (dirp==NULL){
			break;	
		}
		printf("%s\n", dirp-> d_name);
	}
//(*dirp).d_name == dirp -> d_name



}

void lire_dossier_recursif(char * Dossier){

    DIR* rep = NULL;
    struct dirent* file_rode = NULL; // Déclaration d'un pointeur vers la structure dirent. 
    rep = opendir(Dossier);
    char New_Folder[100];

    if (rep == NULL){	//Cas NULL
        printf("Dossier non trouvé");
        return;
    }
    else{ 
        while((file_rode = readdir(rep))!=NULL){//Parcours du dossier
            
            if((strcmp(file_rode->d_name,"."))&&(strcmp(file_rode->d_name,".."))){//Elimination des cas . et ..
                
                if(file_rode->d_type==DT_DIR){

                    //	Affichage Dossier
                    printf("\n----------");
                    printf("Dossier : %s\n", file_rode->d_name);

                    //	Creation de la nouvelle addresse du dossier
                    strcpy(New_Folder, File_Name);
                    strcat(New_Folder, "/"); 
                    strcat(New_Folder, file_rode->d_name); 

                    //	Recursivité --> on relance la fonction
                    lire_dossier_recursif(New_Folder);
                }
                else{
                    //	Partie Affichage
                    printf("Addresse : %s --> Fichier : %s\n", File_Name, file_rode->d_name);
                }
            }
        }
        printf("\n");
    }
    return;
}

void lire_dossier_iteratif(char * Dossier){
    
    DIR* rep = NULL;
    struct dirent* file_rode = NULL; // Déclaration d'un pointeur vers la structure dirent. 
    rep = opendir(Dossier);

    if (rep == NULL){//Cas NULL
        printf("Dossier non trouvé\n");
        return;
    }

    //Initialisation variables
    DIR* Liste[100]; //Liste de DIR*
    char New_Folder[100];
    char AddrDoss[100][100];//Liste ou on stocke les addresse
    int k=0; //Profondeur des sous dossier (0=dossier de base, 1 = sous dossier, 2 sous-sous dossier)
    strcpy(AddrDoss[k], Dossier);

    //Initialisation de la liste des opendir
    int i;
    for (i=0;i<100;i++){//Initialisation a NULL
        Liste[i]=NULL;
    }
    Liste[0]=rep;
    
    
    for (i=0;i<100;i++){   

        while(1){
            
            if ((file_rode = readdir(Liste[k]))==NULL){
                break;
            }
            
            if((strcmp(file_rode->d_name,"."))&&(strcmp(file_rode->d_name,".."))){//Elimination des cas . et ..
                
                if(file_rode->d_type==DT_DIR){ //Si c'est un dossier, on ajoute a la position k                
                    
                    //Affichage Dossier
                    printf("\n----------");
                    printf("Dossier : %s\n", file_rode->d_name);
                    
                    //Creation de la nouvelle addresse du dossier                    
                    strcpy(New_Folder, AddrDoss[k]);
                    strcat(New_Folder, "/"); 
                    strcat(New_Folder, file_rode->d_name);
                    
                    //On passe dans le sous dossier
                    k++;
                    strcpy(AddrDoss[k], New_Folder);
                    Liste[k] = opendir(New_Folder);
                
                }
                else{
                    //Affichage Fichier
                    printf("Addresse : %s --> Fichier : %s\n",AddrDoss[k] ,file_rode->d_name);
                }
            }            
        }
        k--;//On remonte vers le dossier pere
        
        //On empeche le cas k<0
        if(k<0){
            k=0;
        }
        else{
            printf("\n");
        }       
        
    }
    return;

}


int main(){
	char rep[100];
	printf("Dans quel répertoire\n");
	scanf("%s", rep);
	lire_dossier_iteratif(rep);


	return 0;
}
