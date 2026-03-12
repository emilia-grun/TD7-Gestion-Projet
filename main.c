#include <stdio.h>
#include <stdlib.h>

struct Noeud
{
    char data[255];
    struct Noeud *gauche;
    struct Noeud *droite;
};