#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <stdio.h>

/* Structure imposée */
typedef struct {
    char matricule[30];
    char nom[30];
    char prenom[30];
    char date_naissance[11]; 
    char sexe[10];
    char departement[30];
    char filiere[30];
    char region[30];
} Etudiant;

 typedef struct {
    int jour;
    int mois;
    int annee;
 } Date;

/* Prototypes des fonctions */
void enregistrerEtudiant(Etudiant etudiants[], int index);
void afficherEtudiants(Etudiant etudiants[], int n);
void trierParNom(Etudiant etudiants[], int n);
int comparerParFiliere(const void *a, const void *b);
int comparerParNom(const void *a, const void *b);

#endif


