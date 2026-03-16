#ifndef PROJET_H
#define PROJET_H

struct Noeud
{
    char data[255];
    struct Noeud *gauche;
    struct Noeud *droite;
};

struct Noeud *recherche(struct Noeud *n, char *ch);
struct Noeud *recherche2(struct Noeud *n, char *ch);
void supprComplet(struct Noeud *n);
struct Noeud *suppression(struct Noeud *n, char *ch);




//Manzo
struct Noeud *insertion(struct Noeud *n, char *ch);
struct Noeud *insertionEq(struct Noeud *n, char *ch);

#endif