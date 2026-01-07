#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "gesEtu.h"

void enregistrerEtudiant(Etudiant etudiants[], int index)
{
    printf("\n--- Enregistrement de l'etudiant %d ---\n", index + 1);

    printf("Matricule : ");
    scanf("%d", &etudiants[index].matricule);

    printf("Nom : ");
    scanf("%s", etudiants[index].nom);

    printf("Prenom : ");
    scanf("%s", etudiants[index].prenom);

    printf("Date de naissance (jj/mm/aaaa) : ");
    scanf("%s", etudiants[index].date_naissance);

    printf("Sexe : ");
    scanf("%s", etudiants[index].sexe);

    printf("Departement : ");
    scanf("%s", etudiants[index].departement);

    printf("Filiere : ");
    scanf("%s", etudiants[index].filiere);

    printf("Region : ");
    scanf("%s", etudiants[index].region);
}

void afficherEtudiants(Etudiant etudiants[], int n)
{
    int i;

    if (n == 0)
    {
        printf("\nAucun etudiant a afficher.\n");
        return;
    }

    printf("\n======= LISTE DES ETUDIANTS =======\n");

    for (i = 0; i < n; i++)
    {
        printf("\nEtudiant %d\n", i + 1);
        printf("Matricule       : %d\n", etudiants[i].matricule);
        printf("Nom             : %s\n", etudiants[i].nom);
        printf("Prenom          : %s\n", etudiants[i].prenom);
        printf("Date naissance  : %s\n", etudiants[i].date_naissance);
        printf("Sexe            : %s\n", etudiants[i].sexe);
        printf("Departement     : %s\n", etudiants[i].departement);
        printf("Filiere         : %s\n", etudiants[i].filiere);
        printf("Region          : %s\n", etudiants[i].region);
    }
}


int calculerAge(Etudiant e) {
    int jour_naiss, mois_naiss, annee_naiss;
    
    // Extraction sécurisée des données de la chaîne "jj/mm/aaaa"
    if (sscanf(e.date_naissance, "%d/%d/%d", &jour_naiss, &mois_naiss, &annee_naiss) != 3) {
        return -1; // Erreur de format
    }

    // Récupération de la date système
    time_t t = time(NULL);
    struct tm *now = localtime(&t);

    int annee_actuelle = now->tm_year + 1900; 

    int age = annee_actuelle - annee_naiss;

    return age;
}


//Nettoyage du buffer
void empty_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void modifierEtudiant(Etudiant *e) {
    int choix;
    char temp[100];

    do {
        //On affiche d'abords les informations sur l'étudiant
        printf("\n--- MODIFICATION DES INFORMATIONS L'ETUDIANT [%d] ---\n", e->matricule);
        printf("1. Nom : (%s)\n", e->nom);
        printf("2. Prenom : (%s)\n", e->prenom);
        printf("3. Date de naissance : (%s)\n", e->date_naissance);
        printf("4. Sexe : (%s)\n", e->sexe);
        printf("5. Filiere : (%s)\n", e->filiere);
        printf("6. Region : (%s)\n", e->region);
        printf("0. Terminer les modifications\n");
        printf("Choix : ");
        
        if (scanf("%d", &choix) != 1) {
            empty_buffer();
            choix = -1;
        }
        empty_buffer(); // Nettoyer après le scanf

        switch (choix) {
            case 1:
                printf("Nouveau nom : ");
                fgets(e->nom, sizeof(e->nom), stdin);
                break;
            case 2:
                printf("Nouveau prenom : ");
                fgets(e->prenom, sizeof(e->prenom), stdin);
                break;
            case 3: {
                int j, m, a;
                bool valide = false;
                do {
                    printf("Nouvelle date (jj/mm/aaaa) : ");
                    //On vérifie que l'utilisateur entre la date sous le format jj/mm/aaaa
                    if (scanf("%d/%d/%d", &j, &m, &a) == 3) {
                        //On formate la date de naissance au format jj/mm/aaaa
                        sprintf(e->date_naissance, "%02d/%02d/%04d", j, m, a);
                        valide = true;
                    } else {
                        printf("Format de Date invalide !\n");
                    }
                    empty_buffer();
                } while (!valide);
                break;
            }
            case 4:
                printf("Nouveau sexe (Masculin/Feminin) : ");
                fgets(e->sexe, sizeof(e->sexe), stdin);
                break;
            case 5:
                printf("Nouvelle filiere : ");
                fgets(e->filiere, sizeof(e->filiere), stdin);
                break;
            case 6:
                printf("Nouvelle region : ");
                fgets(e->region, sizeof(e->region), stdin);
                break;
            case 0:
                printf("Modifications enregistrees.\n");
                break;
            default:
                printf("Option invalide.\n");
        }
    } while (choix != 0);
}
