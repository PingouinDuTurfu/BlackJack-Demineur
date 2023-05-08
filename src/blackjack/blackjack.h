/*!
* \file blackjack.h
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date 01/01/2022
* \brief Ensemble des fonctions du jeu du blackjack
* \remarks None
*/


#ifndef __BLACKJACK_H__
#define __BLACKJACK_H__

/*!
* \def NOMBRE_COULEUR
* Description nombre de couleur que possède un jeu de carte
*/
#define NOMBRE_COULEUR 4
/*!
* \def NOMBRE_VALEUR
* Description nombre de cartes par couleur
*/
#define NOMBRE_VALEUR 13
/*!
* \def TAILLE_JEU
* Description nombre total de cartes dans un jeu
*/
#define TAILLE_JEU NOMBRE_COULEUR*NOMBRE_VALEUR
/*!
* \def TAILLE_PSEUDO
* Description nombre de caractère pour le pseudo d'un joueur
*/
#define TAILLE_PSEUDO 15
/*!
* \def TAILLE_JETON nombre de chiffre que peut prendre le montant de jeuton d'un joueur
* Description
*/
#define TAILLE_JETON 5
/*!
* \def TAILLE_MISE nombre de chiffre que peut prendre le montant misé par un joueur
* Description
*/
#define TAILLE_MISE 3

/*!
* \def NOMBRE_OPTION
* Description nombre d'option implémenter dans le jeu du blackjack
*/
#define NOMBRE_OPTION 1
/*!
* \def DOUBLER
* Description valeur associé à l'action de doubler sa mise
*/
#define DOUBLER 0

/*!
* \def AS
* Description valeur de l'as
*/
#define AS 1
/*!
* \def VALET
* Description valeur du valet
*/
#define VALET 11
/*!
* \def DAME
* Description valeur de la dame 
*/
#define DAME 12
/*!
* \def ROI
* Description valeur du roi
*/
#define ROI 13


typedef enum {
    true = 1,
    false = 0
} bool;

typedef enum {
    piques = 0,
    trefles = 1,
    carreaux = 2,
    coeurs = 3
} eCouleur;


typedef struct 
{
    int int_valeur;
    eCouleur eCouleur_couleur;
} sCarte;


typedef struct 
{
    char* pchar_pseudo;
    int int_jeton;
    int int_mise;
    int int_nombre_cartes;
    sCarte* psCarte_cartes;
    bool bool_assurer;
} sJoueur;


/*! Importation des librairies*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "main.h"
#include "saisie.h"
#include "affichage.h"


/*!
* \fn void fisherYates(sCarte* psCarte_cartes, int int_nombre_jeu_carte)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief mélange un jeu de carte seulon la méthode de Fisher Yates
* \remarks None
* \param psCarte_cartes liste des cartes
* \param int_nombre_jeu_carte nombre de jeu de cartes utlisé
*/
void fisherYates(sCarte* psCarte_cartes, int int_nombre_jeu_carte);


/*!
* \fn void initCartes(sCarte* psCarte_cartes, int int_nombre_jeu_carte)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief initialise les cartes
* \remarks None
* \param psCarte_cartes liste des cartes
* \param int_nombre_jeu_carte nombre de jeu de cartes utilisé
*/
void initCartes(sCarte* psCarte_cartes, int int_nombre_jeu_carte);


/*!
* \fn sCarte defilerJeu(sCarte* psCarte_cartes, int int_nombre_jeu_carte, int* pint_curseur_defilement)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief retourne la dernière carte de la liste des cartes
* \remarks None
* \param psCarte_cartes liste des cartes
* \param int_nombre_jeu_carte nombre de jeu de cartes utilisé
* \param pint_curseur_defilement position d'avance du défilement dans la liste des cartes
* \return dernière carte de la liste des cartes
*/
sCarte defilerJeu(sCarte* psCarte_cartes, int int_nombre_jeu_carte, int* pint_curseur_defilement);


/*!
* \fn void tirerCarte(sJoueur* sJoueur_joueurs, sCarte* psCarte_cartes, int int_nombre_jeu_carte, int* pint_curseur_defilement)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief donne une carte à un joueur
* \remarks None
* \param sJoueur_joueurs joueur
* \param psCarte_cartes liste des cartes
* \param int_nombre_jeu_carte nombre de jeu de cartes utilisé
* \param pint_curseur_defilement position d'avance du défilement dans la liste des cartes
*/
void tirerCarte(sJoueur* sJoueur_joueurs, sCarte* psCarte_cartes, int int_nombre_jeu_carte, int* pint_curseur_defilement);


/*!
* \fn int maxCarteJoueurs(sJoueur* psJoueur_joueurs, int int_nombre_joueurs)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief Retourne le nombre de cartes maximale que possède les joueurs
* \remarks None
* \param psJoueur_joueurs liste des joueurs
* \param int_nombre_joueurs nombre de joueurs
* \return nombre de cartes maximale
*/
int maxCarteJoueurs(sJoueur* psJoueur_joueurs, int int_nombre_joueurs);


/*!
* \fn char* saisiePseudoJoueur()
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief saisie du pseudo d'un joueur
* \remarks None
* \return pseudo
*/
char* saisiePseudoJoueur(void);


/*!
* \fn void creerNouveauJoueur(sJoueur** psJoueur_joueurs, int* int_nombre_joueurs, char* pchar_pseudo)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief creation d'un nouveau joueur et l'ajoute à la liste des joueurs actuelle
* \remarks None
* \param psJoueur_joueurs liste des joueurs
* \param int_nombre_joueurs nombre de joueur
* \param pchar_pseudo pseudo du nouveau joueur
*/
void creerNouveauJoueur(sJoueur** psJoueur_joueurs, int* int_nombre_joueurs, char* pchar_pseudo);


/*!
* \fn int recupererNumeroJoueur(sJoueur* psJoueur_joueurs, int int_nombre_joueurs)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief affiche un menu de selcetion d'un joueur et retourne sa position
* \remarks None
* \param psJoueur_joueurs liste des joueurs
* \param int_nombre_joueurs nombre de joueurs
* \return position du joueur dans la liste
*/
int recupererNumeroJoueur(sJoueur* psJoueur_joueurs, int int_nombre_joueurs);


/*!
* \fn void supprimerJoueur(sJoueur** psJoueur_joueurs, int* int_nombre_joueurs, int int_numero_joueur)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief supprime un joueur de la liste de joueurs actuelle
* \remarks None
* \param psJoueur_joueurs liste des joueurs
* \param int_nombre_joueurs nombre de joueur
* \param int_numero_joueur position dans la liste du joueur à supprimer
*/
void supprimerJoueur(sJoueur** psJoueur_joueurs, int* int_nombre_joueurs, int int_numero_joueur);


/*!
* \fn int valeurMain(sJoueur sJoueur_joueur)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief revoie la valeur de la main d'un joueur
* \remarks None
* \param sJoueur_joueur joueur
* \return valeur de la main
*/
int valeurMain(sJoueur sJoueur_joueur);


/*!
* \fn void avantPartie(sCarte* psCarte_cartes, int int_nombre_jeu_carte, sJoueur** psJoueur_joueurs, int* int_nombre_joueurs, int* pint_curseur_defilement)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief creation de la partie : ajout/suppression de joueur, distribution de deux cartes par joueurs et une pour la banque
* \remarks None
* \param psCarte_cartes listes des cartes
* \param int_nombre_jeu_carte nombre de jeu de cartes utlisé
* \param psJoueur_joueurs liste des joueurs
* \param int_nombre_joueurs nombre de joueurs
* \param pint_curseur_defilement position d'avance du défilement dans la liste des cartes
*/
void avantPartie(sCarte* psCarte_cartes, int int_nombre_jeu_carte, sJoueur** psJoueur_joueurs, int* int_nombre_joueurs, int* pint_curseur_defilement);


/*!
* \fn void jouerBlackjack(sCarte* psCarte_cartes, int int_nombre_jeu_carte, sJoueur** psJoueur_joueurs, int int_nombre_joueurs, int* pint_curseur_defilement, int int_numero_joueur)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief permet à un joueur de joueur son tour : tirer/rester/doubler
* \remarks None
* \param psCarte_cartes listes des cartes
* \param int_nombre_jeu_carte nombre de jeu de cartes utlisé
* \param psJoueur_joueurs liste des joueurs
* \param int_nombre_joueurs nombre de joueurs
* \param pint_curseur_defilement position d'avance du défilement dans la liste des cartes
* \param int_numero_joueur numero du joueur actuellement en train de jouer
*/
void jouerBlackjack(sCarte* psCarte_cartes, int int_nombre_jeu_carte, sJoueur** psJoueur_joueurs, int int_nombre_joueurs, int* pint_curseur_defilement, int int_numero_joueur);


/*!
* \fn void miserBlackjack( sJoueur** psJoueur_joueurs, int int_nombre_joueurs, int int_numero_joueur)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief permet à un joueur de miser
* \remarks None
* \param psJoueur_joueurs liste des joueurs
* \param int_nombre_joueurs nombre de joueurs
* \param int_numero_joueur numero du joueur actuellement en train de miser
*/
void miserBlackjack(sJoueur** psJoueur_joueurs, int int_nombre_joueurs, int int_numero_joueur);


/*!
* \fn void partie(sCarte* psCarte_cartes, int int_nombre_jeu_carte, sJoueur** psJoueur_joueurs, int int_nombre_joueurs, int* pint_curseur_defilement)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief déroulement de la partie pour chaque joueurs puis tirage de la banque
* \remarks None
* \param psCarte_cartes listes des cartes
* \param int_nombre_jeu_carte nombre de jeu de cartes utlisé
* \param psJoueur_joueurs liste des joueurs
* \param int_nombre_joueurs nombre de joueurs
* \param pint_curseur_defilement position d'avance du défilement dans la liste des cartes
*/
void partie(sCarte* psCarte_cartes, int int_nombre_jeu_carte, sJoueur** psJoueur_joueurs, int int_nombre_joueurs, int* pint_curseur_defilement);


/*!
* \fn void blackjack(void)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief lancement du jeu du blackjack
* \remarks None
*/
void blackjack(void);

#endif