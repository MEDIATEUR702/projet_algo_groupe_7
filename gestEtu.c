#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "gestEtu.h"

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

//Fonction pour comparer(Tri alphabétique) le nom de 02 étudiants
int comparerParNom(const void *a, const void *b){
    const Etudiant *e1 = a;
    const Etudiant *e2 = b;
    return strcmp(e1->nom, e2->nom);
}

//Fonction pour comparer(Tri alphabétique) la filière de 02 étudiants
int comparerParFiliere(const void *a, const void *b){
    const Etudiant *e1 = a;
    const Etudiant *e2 = b;
    return strcmp(e1->filiere, e2->filiere);
}

void trierParNom(Etudiant etudiants[], int n){

    //Tri par nom uniquement
    qsort(etudiants, n, sizeof(Etudiant), comparerParNom);

    //Affichage des noms par ordre alphabétique
    printf("Affichage par ordre alphabétique\n");
    printf("+-----+-----------+-------------------------------------+------------+-------------------+\n");
    printf("|  N° | MATRICULE |           NOM ET PRENOM(S)          |    SEXE    | DATE DE NAISSANCE |\n");
    printf("+-----+-----------+-------------------------------------+------------+-------------------+\n");
    
    for(int i = 0; i < n; i++){

        //Assemblage pour former le nom complet i.e nom + prénom
        char nom_complet[60];
        snprintf(nom_complet, sizeof(nom_complet), "%s %s", etudiants[i].nom, etudiants[i].prenom);
        
        //Affichage formaté
        printf("| %3d | %-9d | %-35s | %-10s | %-17s |\n",i+1, etudiants[i].matricule, nom_complet, etudiants[i].sexe, etudiants[i].date_naissance);
    }
    printf("+-----+-----------+-------------------------------------+------------+-------------------+\n");
}
