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

void lire_dossier_reccursif(char *rep) {
    
}

int main(){
	char rep[100];
	printf("Dans quel répertoire\n");
	scanf("%s", rep);
	lire_dossier(rep);


	return 0;
}
