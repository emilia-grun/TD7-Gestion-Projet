#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "projet.h"

struct Noeud *insertion(struct Noeud *n, char *ch)
{
    srand(time(NULL));
    static int compteur = 0;
    static struct Noeud *nouveau;

    if (compteur == 0)
    {
        nouveau = malloc(sizeof(*nouveau));
        strcpy(nouveau->data, ch);
        nouveau->gauche = NULL;
        nouveau->droite = NULL;
    }

    if (n->gauche == NULL)
    {
        n->gauche = nouveau;
        compteur = 0;
        return n;
    }
    else if (n->droite == NULL)
    {
        n->droite = nouveau;
        compteur = 0;
        return n;
    }

    if (rand() % 2)
    {
        compteur++;
        return insertion(n->droite, ch);
    }
    else
    {
        compteur++;
        return insertion(n->gauche, ch);
    }
}

struct Noeud *insertionEq(struct Noeud *n, char *ch) {
    if (n == NULL) {
        struct Noeud *nouveau = malloc(sizeof(struct Noeud));
        if (nouveau == NULL) return NULL;
        strcpy(nouveau->data, ch);
        nouveau->gauche = NULL;
        nouveau->droite = NULL;
        return nouveau;
    }

    if (strcmp(ch, n->data) <= 0) {
        n->gauche = insertionEq(n->gauche, ch);
    } else {
        n->droite = insertionEq(n->droite, ch);
    }

    return n;
}