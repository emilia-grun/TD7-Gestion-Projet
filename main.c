#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"

int main(int argc, char **argv)
{
    // Déclaration variables
    int action = 0, action_affichage = 0;
    char buffer[256];
    struct Noeud *racine = NULL;

    // Déclaration de la racine de l'arbre
    printf("Bonjour, bienvenue sur le gestionnaire d'arbre binaire.\n");
    printf("Entrez la valeur de la racine : ");
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        buffer[strcspn(buffer, "\n")] = 0;
        racine = malloc(sizeof(struct Noeud));
        strcpy(racine->data, buffer);
        racine->gauche = NULL;
        racine->droite = NULL;
    }

    // Boucle du menu d'actions
    while (action != -1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Ajouter un element\n2. Supprimer un element\n3. Taille de l'arbre\n");
        printf("4. Hauteur de l'arbre\n5. Afficher l'arbre\n6. Valeur minimale et maximale\n-1. Quitter\n> ");

        if (scanf("%d%*c", &action) != 1)
            break;

        switch (action)
        {
        case 1: // Ajout
            printf("Chaine a ajouter : ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            racine = insertionEq(racine, buffer);
            break;
        case 2: // Suppression
            printf("Chaine a supprimer : ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            racine = suppression(racine, buffer);
            break;
        case 3: // Taille
            printf("Nombre d'éléments : %d\n", taille(racine));
            break;
        case 4: // Hauteur
            printf("Hauteur de l'arbre : %d\n", hauteur(racine));
            break;
        case 5: // Affichage
            printf("-- Affichage --\n1. Ordre préfixe\n2. Ordre infixe\n3. Ordre suffixe\n> ");
            scanf("%d%*c", &action_affichage);
            switch (action_affichage)
            {
            case 1:
                parcoursPre(racine);
                break;
            case 2:
                parcoursInf(racine);
                break;
            case 3:
                parcoursSuf(racine);
                break;
            default:
                printf("Option d'affichage invalide.");
                continue;
            }
            break;
        case 6: // Valeur min et max
            printf("La chaîne minimale de l'arbre est : %s\n", minimum(racine));
            printf("La chaîne maximale de l'arbre est : %s\n", maximum(racine));
            break;
        case -1: // Arrêt
            printf("Au revoir !\n");
            break;
        default:
            printf("Option invalide.\n");
        }
    }
    return 0;
}