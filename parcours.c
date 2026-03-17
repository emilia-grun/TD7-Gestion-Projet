
#include <stdio.h>  // Pour printf() et scanf()
#include <string.h> // Pour strcmp()
#include <stdlib.h> // Pour malloc() et free()
#include <math.h>   // Pour fmin() et fmax()
#include <time.h>   // Pour initialiser le générateur aléatoire
#include "projet.h" 

void parcoursPre(struct Noeud *n)
{ // Q7 : Parcours préfixe
    if (n == NULL)
        return;

    printf("%s\n", n->data);
    parcoursPre(n->gauche);
    parcoursPre(n->droite);
}

void parcoursInf(struct Noeud *n)
{ // Q8 : Parcours infixe
    if (n == NULL)
        return;

    parcoursInf(n->gauche);
    printf("%s\n", n->data);
    parcoursInf(n->droite);
}

void parcoursSuf(struct Noeud *n)
{ // Q9 : Parcours suffixe
    if (n == NULL)
        return;

    parcoursSuf(n->gauche);
    parcoursSuf(n->droite);
    printf("%s\n", n->data);
}