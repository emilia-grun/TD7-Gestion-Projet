#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"

struct Noeud *recherche(struct Noeud *n, char *ch) {
    if (n == NULL) return NULL;

    int cmp = strcmp(ch, n->data);

    if (cmp == 0) return n;
    else if (cmp < 0) return recherche(n->gauche, ch);
    else return recherche(n->droite, ch);
}

struct Noeud *recherche2(struct Noeud *n, char *ch) {
    while (n != NULL) {
        int cmp = strcmp(ch, n->data);

        if (cmp == 0) return n;
        else if (cmp < 0) n = n->gauche;
        else n = n->droite;
    }
    return NULL;
}

void supprComplet(struct Noeud *n) {
    if (n == NULL) return;

    supprComplet(n->gauche);
    supprComplet(n->droite);
    free(n);
}

struct Noeud *suppression(struct Noeud *n, char *ch) {
    if (n == NULL) return NULL;

    int cmp = strcmp(ch, n->data);

    if (cmp < 0) {
        n->gauche = suppression(n->gauche, ch);
    }
    else if (cmp > 0) {
        n->droite = suppression(n->droite, ch);
    }
    else {
        if (n->gauche == NULL && n->droite == NULL) {
            free(n);
            return NULL;
        }

        if (n->gauche == NULL) {
            struct Noeud *tmp = n->droite;
            free(n);
            return tmp;
        }

        if (n->droite == NULL) {
            struct Noeud *tmp = n->gauche;
            free(n);
            return tmp;
        }

        struct Noeud *min = n->droite;
        while (min->gauche != NULL)
            min = min->gauche;

        strcpy(n->data, min->data);
        n->droite = suppression(n->droite, min->data);
    }

    return n;
}
