#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "projet.h"

char *minCh(char *c1, char *c2)
{ // Le minimum de 2 chaînes avec prise en compte de NULL
    if (c2 == NULL)
        return c1;
    else if (c1 == NULL || strcmp(c1, c2) > 0)
        return c2;

    return c1;
    // Si les deux chaînes sont identiques, alors c1 sera renvoyé par défaut
}

char *minimum(struct Noeud *n)
{ // Q4 : Recherche la valeur minimale de l'arbre
    if (n == NULL)
        return NULL;
    return minCh(n->data, minCh(minimum(n->gauche), minimum(n->droite)));
}


char *maxCh(char *c1, char *c2)
{ // Le maximum de 2 chaînes avec prise en compte de NULL
    if (c2 == NULL)
        return c1;
    else if (c1 == NULL || strcmp(c1, c2) < 0)
        return c2;

    return c1;
    // Si les deux chaînes sont identiques, alors c1 sera renvoyé par défaut
}

char *maximum(struct Noeud *n)
{ // Recherche la valeur maximale de l'arbre
    if (n == NULL)
        return NULL;
    return maxCh(n->data, maxCh(maximum(n->gauche), maximum(n->droite)));
}

int taille(struct Noeud *n)
{
    if (n == NULL)
        return 0;
    return 1 + taille(n->gauche) + taille(n->droite);
}