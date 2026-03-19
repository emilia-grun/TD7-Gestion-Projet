#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "projet.h"

// Renvoie la chaîne de caractères la plus petite dans l'ordre alphabétique avec prise en compte de NULL
char *minCh(char *c1, char *c2)
{
    if (c2 == NULL)
        return c1;
    else if (c1 == NULL || strcmp(c1, c2) > 0)
        return c2;

    return c1;
    // Si les deux chaînes sont identiques, alors c1 sera renvoyé par défaut
}

// Renvoie la chaîne la plus petite de l'arbre
char *minimum(struct Noeud *n)
{
    if (n == NULL)
        return NULL;
    return minCh(n->data, minCh(minimum(n->gauche), minimum(n->droite)));
}

// Renvoie la chaîne de caractères la plus grande dans l'ordre alphabétique avec prise en compte de NULL
char *maxCh(char *c1, char *c2)
{
    if (c2 == NULL)
        return c1;
    else if (c1 == NULL || strcmp(c1, c2) < 0)
        return c2;

    return c1;
    // Si les deux chaînes sont identiques, alors c1 sera renvoyé par défaut
}

// Renvoie la chaîne la plus grande de l'arbre
char *maximum(struct Noeud *n)
{
    if (n == NULL)
        return NULL;
    return maxCh(n->data, maxCh(maximum(n->gauche), maximum(n->droite)));
}

// Renvoie le nombre d'éléments de l'arbre
int taille(struct Noeud *n)
{
    if (n == NULL)
        return 0;
    return 1 + taille(n->gauche) + taille(n->droite);
}

// Renvoie la profondeur de l'arbre
int hauteur(struct Noeud *n)
{
    int somme = 0;
    if (n == NULL)
        return 0;

    if (n->gauche != NULL || n->droite != NULL)
    {
        somme += 1;
    }

    return somme + hauteur(n->gauche) + hauteur(n->droite);
}