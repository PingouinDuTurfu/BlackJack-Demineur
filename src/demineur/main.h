/*!
* \file main.h
* \author Ollivier Rémy <ollivierre@eisti.eu>
* \version 0.1
* \date 02/01/2022
* \brief Jeu du demineur
* \remarks None
*/

#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "saisie.h"
#include "demineur.h"

/*!
* \def RED
* Description couleur rouge pour le printf
*/
#define RED   "\x1B[31m"
/*!
* \def GRN
* Description couleur vert pour le printf
*/
#define GRN   "\x1B[32m"
/*!
* \def YEL
* Description couleur jaune pour le printf
*/
#define YEL   "\x1B[33m"
/*!
* \def BLU
* Description couleur bleu pour le printf
*/
#define BLU   "\x1B[34m"
/*!
* \def MAG
* Description couleur magenta pour le printf
*/
#define MAG   "\x1B[35m"
/*!
* \def CYN
* Description couleur cyan pour le printf
*/
#define CYN   "\x1B[36m"
/*!
* \def WHT
* Description couleur blanche pour le printf
*/
#define WHT   "\x1B[37m"
/*!
* \def RESET
* Description couleur par défaut pour le printf
*/
#define RESET "\x1B[0m"

#define B_GREEN "\x1B[42m"

#define ERREUR_ALLOCATION_MEMOIRE -1


#endif