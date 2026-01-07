#include "gesEtu.h"

int main()
{
    Etudiant etudiants[100];   // tableau en mémoire
    int n = 0;                 // nombre d'etudiants enregistrés
    int choix;
    int i;

    do
    {
        printf("\n===== MENU GESTION DES ETUDIANTS =====\n");
        printf("1. Enregistrer les etudiants\n");
        printf("2. Afficher les etudiants\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                printf("\nCombien d'etudiants voulez-vous enregistrer ? ");
                scanf("%d", &n);

                for (i = 0; i < n; i++)
                {
                    enregistrerEtudiant(etudiants, i);
                }
                break;

            case 2:
                afficherEtudiants(etudiants, n);
                break;

            case 0:
                printf("Fin du programme.\n");
                break;

            default:
                printf("Choix invalide. Reessayez.\n");
        }

    } while (choix != 0);

    return 0;
}