/*
 * SPDX-FileCopyrightText: 2020 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "serveur.h"

/* renvoyer un message (*data) au client (client_socket_fd)
 */
int renvoie_message(int client_socket_fd, char *data) {
  int data_size = write (client_socket_fd, (void *) data, strlen(data));
      
  if (data_size < 0) {
    perror("erreur ecriture");
    return(EXIT_FAILURE);
  }
}

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int recois_envoie_message(int socketfd) {
  struct sockaddr_in client_addr;
  char data[1024];

  int client_addr_len = sizeof(client_addr);
 
  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *) &client_addr, &client_addr_len);
  if (client_socket_fd < 0 ) {
    perror("accept");
    return(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // lecture de données envoyées par un client
  int data_size = read (client_socket_fd, (void *) data, sizeof(data));
      
  if (data_size < 0) {
    perror("erreur lecture");
    return(EXIT_FAILURE);
  }
  
  /*
   * extraire le code des données envoyées par le client. 
   * Les données envoyées par le client peuvent commencer par le mot "message :" ou un autre mot.
   */
  printf ("Message recu: %s\n", data);
  char code[10];
  sscanf(data, "%s:", code);


 

  //Si le message commence par le mot: 'message:' 
  if (strcmp(code, "message:") == 0) {
    // Demande utilisateur pour saisir un message
    char message[100];  // Initialisation
    memset(data, 0, sizeof(data));  // Réinitialisation de data
    printf("Votre message (max 1000 caracteres): ");  // Affichage du message
    fgets(message, 1024, stdin);  // Saisie du message
    strcat(data, message);  // Concaténation du message avec data
    renvoie_message(client_socket_fd, data);  // Envois du résultat
  }

  if (strcmp(code, "calcule:") == 0) { 
    float result;// Initialisation
    result = recois_numeros_calcule(data,0);  //calcul de result par la fonction recois_numeros_calcule
    sprintf(data, "%f", result);  //conversion de result en string et concaténation de "calcule recu: " avec result
    renvoie_message(client_socket_fd,data);  //Envois du résultat

  }
  if (strcmp(code, "calcule2:") == 0) {
      char * chaine3 = malloc(300 * sizeof(char));
      chaine3 = fctnEtudiant();
      renvoie_message(client_socket_fd,chaine3);  //Envois du résultat
  }


  //fermer le socket 
  close(socketfd);
}

float recois_numeros_calcule(char * data, int id){
  
  //Initialisation des variables
  char op; 
  float num1;
  float num2; 

  //Recupération des valeurs
  if(id==1){  //Cas Etudiant
    sscanf(data,"%s %f %f",&op,&num1,&num2); // sscanf recupere les valeurs selon leur type
  }
  else{ // Cas calcule
    sscanf(data,"%*s %s %f %f",&op,&num1,&num2); // sscanf recupere les valeurs selon leur type
  }
  

  // Utilisation de switch
  switch(op){
    case '+':
      return (num1+num2);
    case '-':
      return(num1-num2);
    case '*':
      return(num1*num2);
    case '/':
      return(num1/num2);
    case '%':
      return((int)num1%(int)num2); // Convertion necessaire en int
    case '&':
      return((int)num1&(int)num2); // Convertion necessaire en int
    case '|':
      return((int)num1|(int)num2); //Convertion necessaire en int
    case '~':
      return(~(int)num1); //Convertion necessaire en int
  }
  return 0; //Cas erreur
}

char* fctnEtudiant(){

  //Initialisation des variables
  char* nom_de_fichier;
  FILE* fichier;
  char FichNotes[25][50]={
  "../etudiant/1/note1.txt","../etudiant/1/note2.txt","../etudiant/1/note3.txt","../etudiant/1/note4.txt","../etudiant/1/note5.txt",
  "../etudiant/2/note1.txt","../etudiant/2/note2.txt","../etudiant/2/note3.txt","../etudiant/2/note4.txt","../etudiant/2/note5.txt",
  "../etudiant/3/note1.txt","../etudiant/3/note2.txt","../etudiant/3/note3.txt","../etudiant/3/note4.txt","../etudiant/3/note5.txt",
  "../etudiant/4/note1.txt","../etudiant/4/note2.txt","../etudiant/4/note3.txt","../etudiant/4/note4.txt","../etudiant/4/note5.txt",
  "../etudiant/5/note1.txt","../etudiant/5/note2.txt","../etudiant/5/note3.txt","../etudiant/5/note4.txt","../etudiant/5/note5.txt"};
  int ListeNotes[5][5];
  int i;
  int j;
  char chaine[10];
  char chaine2[10];
  

  //Etape 1 : On récupere les notes que l'on stocke dans ListeNotes
  for(i=0;i<5;i++){
    for(j=0;j<5;j++){

      //On choisi le fichier a ouvrir
      nom_de_fichier = FichNotes[(i*5+j)];
      
      //Ouverture du fichier
      fichier = fopen(nom_de_fichier, "r");
      
      //Cas probleme d'ouverture de fichier
      if (fichier==NULL){
        printf("Erreur de fichier");
        return 0;
      }
      
      //Lecture des notes et incrementation dans la liste ListeNotes
      fgets(chaine, 10, fichier);
      ListeNotes[i][j]=atoi(chaine);
      
      //Fermeture du fichier
      fclose(fichier);
      
    }
  }


  //Etape 2 : Calcul de la somme des notes des etudiants
  
  int ListeNotesT[5][5];
  memcpy(ListeNotesT, ListeNotes, sizeof ListeNotesT);//Copie de la matrice des notes dans une autre matrice

  //On calcule etudiant par etudiant les notes pour faire la somme
  for(i=0;i<5;i++){
    
    for(j=0;j<4;j++){
      
      //Concatenation et mise en forme du calcul a effectuer
      sprintf(chaine2, "+ %d %d", ListeNotesT[i][j],ListeNotesT[i][j+1]);
      //Calcul
      ListeNotesT[i][j+1]=recois_numeros_calcule(chaine2,1);
      
    }
  }
  


  //Etape 3 : Calcul des moyennes par matiere
  
  int ListeNotesT2[5][5];
  memcpy(ListeNotesT2, ListeNotes, sizeof ListeNotesT2);//Copie de la matrice des notes dans une autre matrice
  
  //On calcule matiere par matiere les notes pour faire la moyenne
  for(j=0;j<5;j++){
  
    for(i=0;i<4;i++){
      
      //Concatenation et mise en forme du calcul a effectuer
      sprintf(chaine2, "+ %d %d", ListeNotesT2[i][j],ListeNotesT2[i+1][j]);
      //Calcul de la somme des notes d'une matiere
      ListeNotesT2[i+1][j]=recois_numeros_calcule(chaine2,1);
    }
    //Division pour faire la moyenne
    sprintf(chaine2, "/ %d %d", ListeNotesT2[4][j],5); //Concatenation
    ListeNotesT2[4][j]=recois_numeros_calcule(chaine2,1); //Calcul
  }

  //Concatenation et renvoie du resultat
  char * chaine3 = malloc(300 * sizeof(char));
  sprintf(chaine3, "Etudiant 1 : %d\nEtudiant 2 : %d\nEtudiant 3 : %d\nEtudiant 4 : %d\nEtudiant 5 : %d\n\nMoyenne 1 : %d\nMoyenne 2 : %d\nMoyenne 3 : %d\nMoyenne 4 : %d\nMoyenne 5: %d\n", ListeNotesT[0][4],ListeNotesT[1][4],ListeNotesT[2][4],ListeNotesT[3][4],ListeNotesT[4][4],ListeNotesT2[4][0],ListeNotesT2[4][1],ListeNotesT2[4][2],ListeNotesT2[4][3],ListeNotesT2[4][4]);
  return chaine3;
}





int main (){
  
  int socketfd;
  int bind_status;
  int client_addr_len;

  struct sockaddr_in server_addr, client_addr;

  /*
  * Creation d'une socket
  */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socketfd < 0 ) {
    perror("Unable to open a socket");
    return -1;
  }

  int option = 1;
  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Relier l'adresse à la socket
  bind_status = bind(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if (bind_status < 0 ) {
    perror("bind");
    return(EXIT_FAILURE);
  }

  // Écouter les messages envoyés par le client
  listen(socketfd, 10);

  //Lire et répondre au client
  
  recois_envoie_message(socketfd);
  
  
}