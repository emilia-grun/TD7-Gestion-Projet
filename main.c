#include <stdio.h>
#include <stdlib.h>
#include "projet.h"

struct Noeud
{
    char data[256];
    struct Noeud *gauche;
    struct Noeud *droite;
};
