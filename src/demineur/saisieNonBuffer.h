/*!
* \file saisieNonBuffer.h
* \author https://stackoverflow.com/questions/41383062/c-how-to-break-scanf-with-no-enter-and-no-string
* \version 0.1
* \date 02/01/2022
* \brief Lecture d'une touche non bufferisé
* \remarks Ce code ne m'appartient pas
*/

#ifndef __SAISIE_NON_BUFFER_H__
#define __SAISIE_NON_BUFFER_H__

/* Ce code ne m'appartient pas ! */

#include <termios.h>
#include <stdio.h>

void initTermios(int echo);
void resetTermios(void);
char getch_(int echo);
char getch(void);
char getche(void);

#endif