#include "gesEtu.h"

int main()
{
    int n, i;

    printf("Entrez le nombre d'etudiants : ");
    scanf("%d", &n);

    Etudiant etudiants[n];

    for (i = 0; i < n; i++)
    {
        enregistrerEtudiant(etudiants, i);
         afficherEtudiants(etudiants, n);
    }

   

    return 0;
}

