#include <stdio.h>
#include "projet.h"

// Affiche l'arbre avec un parcours préfixe
void parcoursPre(struct Noeud *n)
{
    if (n == NULL)
        return;

    printf("%s\n", n->data);
    parcoursPre(n->gauche);
    parcoursPre(n->droite);
}

// Affiche l'arbre avec un parcours infixe
void parcoursInf(struct Noeud *n)
{
    if (n == NULL)
        return;

    parcoursInf(n->gauche);
    printf("%s\n", n->data);
    parcoursInf(n->droite);
}

// Affiche l'arbre avec un parcours suffixe
void parcoursSuf(struct Noeud *n)
{
    if (n == NULL)
        return;

    parcoursSuf(n->gauche);
    parcoursSuf(n->droite);
    printf("%s\n", n->data);
}