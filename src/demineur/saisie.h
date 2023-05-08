/*!
* \file saisie.h
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date 02/01/2022
* \brief Lecture d'une touche
* \remarks None
*/


#ifndef __SAISIE_H__
#define __SAISIE_H__

/*! Importation des librairies*/
#include <printf.h>
#include <stdio.h>

#include "saisieNonBuffer.h"

/*!
* \def HAUT
* Description touche directionnelle haute
*/
#define HAUT -10
/*!
* \def BAS
* Description touche directionnelle basse
*/
#define BAS -11
/*!
* \def GAUCHE touche directionnelle gauche
* Description
*/
#define GAUCHE -12
/*!
* \def DROITE touche directionnelle droite
* Description
*/
#define DROITE -13

/*!
* \fn int lireTouche(void)
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date  02/01/2022
* \brief li une touche
* \remarks None
* \return valeur de la touche
*/
int lireTouche(void);

#endif