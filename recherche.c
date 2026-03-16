#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"

struct Noeud *recherche(struct Noeud *n, char *ch) {
    if (n == NULL) return NULL;
    int cmp = strcmp(ch, n->data);
    if (cmp == 0) return n;
    return recherche(cmp < 0 ? n->gauche : n->droite, ch);
}

struct Noeud *recherche2(struct Noeud *n, char *ch) {
    if (n == NULL) return NULL;
    if ((n->gauche != NULL && strcmp(n->gauche->data, ch) == 0) ||
        (n->droite != NULL && strcmp(n->droite->data, ch) == 0))
        return n;

    if (strcmp(ch, n->data) < 0)
        return recherche2(n->gauche, ch);
    else
        return recherche2(n->droite, ch);
}

void supprComplet(struct Noeud *n) {
    struct Noeud *cible;
    if (n->gauche != NULL) {
        strcpy(n->data, n->gauche->data);
        cible = n->gauche;
        n->gauche = NULL;
    } else {
        strcpy(n->data, n->droite->data);
        cible = n->droite;
        n->droite = NULL;
    }
    free(cible);
}

struct Noeud *suppression(struct Noeud *n, char *ch) {
    struct Noeud *suppr = recherche(n, ch);
    if (suppr == NULL) return n; // Pas trouvé

    // Si la racine est la cible
    if (suppr == n) {
        if (n->gauche == NULL && n->droite == NULL) {
            free(n); return NULL;
        }
        // Pour la racine, on simule un parent ou on traite différemment
        // Ici on délègue à supprComplet si elle a des enfants
        supprComplet(n);
        return n;
    }

    struct Noeud *parent = recherche2(n, ch);
    int est_a_gauche = (parent->gauche == suppr);

    // Cas 1 : Feuille
    if (suppr->gauche == NULL && suppr->droite == NULL) {
        if (est_a_gauche) parent->gauche = NULL;
        else parent->droite = NULL;
        free(suppr);
    } 
    // Cas 2 : Noeud complet (2 enfants)
    else if (suppr->gauche != NULL && suppr->droite != NULL) {
        supprComplet(suppr);
    }
    // Cas 3 : Un seul enfant
    else {
        struct Noeud *enfant = (suppr->gauche != NULL) ? suppr->gauche : suppr->droite;
        if (est_a_gauche) parent->gauche = enfant;
        else parent->droite = enfant;
        free(suppr);
    }
    
    return n;
}
