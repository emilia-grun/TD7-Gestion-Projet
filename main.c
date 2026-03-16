#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "projet.h"

int main(int argc, char **argv) {
    int action = 0;
    char buffer[256];
    struct Noeud *racine = NULL;

    printf("Bonjour, bienvenue sur le gestionnaire d'arbre binaire.\n");
    printf("Entrez la valeur de la racine : ");
    if (fgets(buffer, sizeof(buffer), stdin)) {
        buffer[strcspn(buffer, "\n")] = 0;
        // Initialisation propre
        racine = malloc(sizeof(struct Noeud));
        strcpy(racine->data, buffer);
        racine->gauche = NULL;
        racine->droite = NULL;
    }

    while (action != -1) {
        printf("\n--- Menu ---\n");
        printf("1. Ajouter un element\n2. Supprimer un element\n3. Taille de l'arbre\n");
        printf("4. Hauteur de l'arbre\n5. Afficher (Infixe)\n-1. Quitter\n> ");
        
        if (scanf("%d%*c", &action) != 1) break;

        switch (action) {
            case 1:
                printf("Chaine a ajouter : ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                racine = insertionEq(racine, buffer);
                break;
            case 2:
                printf("Chaine a supprimer : ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                racine = suppression(racine, buffer);
                break;
            case 3:
                printf("Nombre d'éléments : %d\n", taille(racine));
                break;
            case 4:
                printf("Hauteur de l'arbre : %d\n", hauteur(racine));
                break;
            case 5:
                // à compléter
                break;
            case -1:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide.\n");
        }
    }
    return 0;
}