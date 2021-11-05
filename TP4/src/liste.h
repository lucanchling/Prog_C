/* Fichier: liste.h
* permet d'insérer une couleur dans une liste à l'aide d'un pointeur
* auteur: Luc Anchling
*/

struct couleur{
    int rouge;
    int vert;
    int bleu;
    int alpha;
    struct couleur *next;
    struct couleur *prev;  
};

struct liste_couleur{
    struct couleur first;
    struct couleur last;
};

void insertion (struct couleur *, struct liste_couleur *);
void parcours (struct liste_couleur *);