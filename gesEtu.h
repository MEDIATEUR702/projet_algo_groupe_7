#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <stdio.h>

/* Structure imposée */
typedef struct {
    int matricule;
    char nom[30];
    char prenom[30];
    char date_naissance[11]; // jj/mm/aaaa
    char sexe[10];
    char departement[30];
    char filiere[30];
    char region[30];
} Etudiant;

/* Prototypes des fonctions */
void enregistrerEtudiant(Etudiant etudiants[], int index);
void afficherEtudiants(Etudiant etudiants[], int n);
int calculerAge(Etudiant e);
void modifierEtudiant(Etudiant *e);
void empty_buffer(void);

#endif


