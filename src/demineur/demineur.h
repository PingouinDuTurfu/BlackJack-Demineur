/*!
* \file demineur.h
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date 02/01/2022
* \brief Ensemble des fonctions du jeu du demineur
* \remarks None
*/


#ifndef __DEMINEUR_H__
#define __DEMINEUR_H__

/*! Importation des librairies*/
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "saisie.h"

/*!
* \def DEJA_VU
* Description case deja retourné
*/
#define DEJA_VU 1
/*!
* \def BOMBE
* Description case avec une bombe
*/
#define BOMBE 2
/*!
* \def PERDU le joueur a perdu
* Description
*/
#define PERDU 3
/*!
* \def VICTOIRE le joueur a gagné
* Description
*/
#define VICTOIRE 4

typedef enum {
    true = 1,
    false = 0
} bool;

typedef struct 
{
    int int_valeur;
    bool bool_bombe;
    bool bool_vu;
    bool bool_drapeau;
} CaseGrille;

/*!
* \fn void initGrille(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_bombe)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  02/01/2022
* \brief Initialise une grille de demineur
* \remarks None
* \param ppCaseGrille_grille grille
* \param int_taille_grille_x taille de grille en x
* \param int_taille_grille_y taille de grille en y
* \param int_bombe nombre de bombe de la grille
*/
void initGrille(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_bombe);


/*!
* \fn void afficherGrille(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_curseur_x, int int_curseur_y)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  02/01/2022
* \brief affiche la grille de demineur
* \remarks None
* \param ppCaseGrille_grille grille
* \param int_taille_grille_x taille de grille en x
* \param int_taille_grille_y taille de grille en y
* \param int_curseur_x case sur laquelle ce trouve le joueur en x
* \param int_curseur_y case sur laquelle ce trouve le joueur en y
*/
void afficherGrille(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_curseur_x, int int_curseur_y);


/*!
* \fn int afficherNombreBombe(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_i, int int_j)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  02/01/2022
* \brief affiche le nombre de bombe environnante
* \remarks None
* \param ppCaseGrille_grille grille
* \param int_taille_grille_x taille de grille en x
* \param int_taille_grille_y taille de grille en y
* \param int_i position de la case en x
* \param int_j position de la case en y
* \return 
*/
int afficherNombreBombe(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_i, int int_j);


/*!
* \fn void reveler(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_x, int int_y)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  02/01/2022
* \brief revele les cases environnante
* \remarks None
* \param ppCaseGrille_grille grille
* \param int_taille_grille_x taille de grille en x
* \param int_taille_grille_y taille de grille en y
* \param int_x position de la case en x
* \param int_y position de la case en y
*/
void reveler(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_x, int int_y);


/*!
* \fn int partieFini(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_bombe)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  02/01/2022
* \brief permet de savoir si la partie est terminé
* \remarks None
* \param ppCaseGrille_grille grille
* \param int_taille_grille_x taille de grille en x
* \param int_taille_grille_y taille de grille en y
* \param int_bombe nombre de bombe dans la grille
* \return 
*/
int partieFini(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_bombe);


/*!
* \fn int jouer(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_x, int int_y)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  02/01/2022
* \brief jouer une case de la grille
* \remarks None
* \param ppCaseGrille_grille grille
* \param int_taille_grille_x taille de grille en x
* \param int_taille_grille_y taille de grille en y
* \param int_x position de la case en x
* \param int_y position de la case en y
* \return 
*/
int jouer(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_x, int int_y);


/*!
* \fn void saisie(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int* pint_x, int* pint_y)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  02/01/2022
* \brief electiionner une case de la grille
* \remarks None
* \param ppCaseGrille_grille grille
* \param int_taille_grille_x taille de grille en x
* \param int_taille_grille_y taille de grille en y
* \param pint_x position de la case en x
* \param pint_y position de la case en y
*/
void saisie(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int* pint_x, int* pint_y);


/*!
* \fn void demineur(void)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  02/01/2022
* \brief execution du jeu
* \remarks None
*/
void demineur(void);

#endif