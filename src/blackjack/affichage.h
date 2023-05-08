/*!
* \file affichage.h
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date 02/01/2022
* \brief Ensemble des fonctions d'affichage du blackjack
* \remarks None
*/


#ifndef __AFFICHAGE_H__
#define __AFFICHAGE_H__

/*! Importation des librairies*/
#include "blackjack.h"

/*!
* \fn void affichageChaineAutoCompletion(char* chaine, int int_taille_chaine)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief affiche une chaine de caractère est complète avec des espaces
* \remarks None
* \param chaine chaine écrire
* \param int_taille_chaine taille de la chaine
*/
void affichageChaineAutoCompletion(char* chaine, int int_taille_chaine);


/*!
* \fn void affichageHaut()
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief affiche la partie supérieur du jeu
* \remarks None
*/
void affichageHaut();


/*!
* \fn void affichageCotes(int int_nombre_lignes)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief affiche les cotés du jeu
* \remarks None
* \param int_nombre_lignes 
*/
void affichageCotes(int int_nombre_lignes);


/*!
* \fn void affichageBas()
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief affiche la partie basse du jeu
* \remarks None
*/
void affichageBas();


/*!
* \fn void affichageAvantPartie(sJoueur* psJoueur_joueurs, int int_nombre_joueurs, int int_curseur)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief  affiche le menu de création de la partie avant le lancement du jeu
* \remarks None
* \param psJoueur_joueurs liste des joueurs
* \param int_nombre_joueurs nombre de joueurs
* \param int_curseur position du curseur dans la liste des choix du menu
*/
void affichageAvantPartie(sJoueur* psJoueur_joueurs, int int_nombre_joueurs, int int_curseur);


/*!
* \fn void affichageCarteVide(int int_decalage)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief affiche un emplacement de jeu vide
* \remarks None
* \param int_decalage decalage horizontal du curseur pour l'affichage
*/
void affichageCarteVide(int int_decalage);


/*!
* \fn void affichageCartes(sJoueur psJoueur_joueurs, int int_decalage)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief affiche la listes de cartes d'un joueur
* \remarks None
* \param psJoueur_joueurs joueur
* \param int_decalage decalage horizontal du curseur pour l'affichage
*/
void affichageCartes(sJoueur psJoueur_joueurs, int int_decalage);
/*!
* \fn void affichageCartesBanque(sJoueur psJoueur_joueurs)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief affiche les cartes de la banque
* \remarks None
* \param psJoueur_joueurs banque
*/
void affichageCartesBanque(sJoueur psJoueur_joueurs);


/*!
* \fn void affichageChoix(int int_choix, bool* pbool_option, char* pchar_pseudo)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief affiche les différents choix que peut faire le joueur durant la partie
* \remarks None
* \param int_choix position du curseur dans la liste des choix du menu
* \param pbool_option liste des choix que le joueur peux faire
* \param pchar_pseudo pseudo du joueur
*/
void affichageChoix(int int_choix, bool* pbool_option, char* pchar_pseudo);


/*!
* \fn void affichageResultat(sJoueur* psJoueur_joueurs, int int_nombre_joueurs)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief affiche le resultat de la partie de plus si le joueur est gagnant affiche le gain
* \remarks None
* \param psJoueur_joueurs liste des joueurs
* \param int_nombre_joueurs nombre de joueurs
*/
void affichageResultat(sJoueur* psJoueur_joueurs, int int_nombre_joueurs);


/*!
* \fn void affichagePartie(sJoueur* psJoueur_joueurs, int int_nombre_joueurs, int int_numero_joueur, int int_choix, bool* pbool_options, bool bool_resultat)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief affiche la partie lors du déroulement du jeu
* \remarks None
* \param psJoueur_joueurs liste des joueurs
* \param int_nombre_joueurs nombre de joueurs
* \param int_numero_joueur indice du joueur actuellement en train de jouer
* \param int_choix position du curseur dans la liste des choix du menu
* \param pbool_options liste des choix que le joueur peux faire
* \param bool_resultat vrai si la partie est fini sinon faux
*/
void affichagePartie(sJoueur* psJoueur_joueurs, int int_nombre_joueurs, int int_numero_joueur, int int_choix, bool* pbool_options, bool bool_resultat);


/*!
* \fn void affichageMiser(int int_decalage, char* pchar_pseudo, int int_mise)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  01/01/2022
* \brief affiche le menu pour permettre aux joueurs de rentrer leurs mises
* \remarks None
* \param int_decalage decalage horizontal du curseur pour l'affichage
* \param pchar_pseudo pseudo du joueur
* \param int_mise mise actuelle du joueur
*/
void affichageMiser(int int_decalage, char* pchar_pseudo, int int_mise);

#endif