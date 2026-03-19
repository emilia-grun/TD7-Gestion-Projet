#ifndef PROJET_H
#define PROJET_H

// Emilia
struct Noeud
{
    char data[255];
    struct Noeud *gauche;
    struct Noeud *droite;
};

int taille(struct Noeud *n);
int hauteur(struct Noeud *n);

// Negar
struct Noeud *recherche(struct Noeud *n, char *ch);
struct Noeud *recherche2(struct Noeud *n, char *ch);
void supprComplet(struct Noeud *n);
struct Noeud *suppression(struct Noeud *n, char *ch);

// Lucresse
char *minCh(char *c1, char *c2);
char *minimum(struct Noeud *n);
char *maxCh(char *c1, char *c2);
char *maximum(struct Noeud *n);

// Manzo
struct Noeud *insertion(struct Noeud *n, char *ch);
struct Noeud *insertionEq(struct Noeud *n, char *ch);

// Hadi
void parcoursPre(struct Noeud *n);
void parcoursInf(struct Noeud *n);
void parcoursSuf(struct Noeud *n);

#endif