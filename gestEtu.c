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


