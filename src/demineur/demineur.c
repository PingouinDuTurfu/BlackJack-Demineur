#include "demineur.h"

void initGrille(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_bombe) {
    
    int int_bombe_increment; // Nombre de bombe

    /* Initialisation */
    int_bombe_increment = 1;
    
    ppCaseGrille_grille[2][0].bool_bombe = true;

    while(int_bombe_increment < int_bombe) {

        /* Ajout d'une bombe aléatoirement dans la grille */
        int int_x;
        int int_y;

        int_x = rand()%int_taille_grille_x;
        int_y = rand()%int_taille_grille_y;

        if(ppCaseGrille_grille[int_x][int_y].bool_bombe == false) {
            ppCaseGrille_grille[int_x][int_y].bool_bombe = true;
            int_bombe_increment++;
        }
    }
}


void afficherGrille(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_curseur_x, int int_curseur_y) {
       
    /* Vider l'affichage */
    system ("clear");

    /* Affichage de l'en-tête */
    printf("\n");
    printf("\n");
    printf("     /$$$$$$$                          /$$                                        \n");
    printf("    | $$__  $$                        |__/                                        \n");
    printf("    | $$  \\ $$  /$$$$$$  /$$$$$$/$$$$  /$$ /$$$$$$$   /$$$$$$  /$$   /$$  /$$$$$$ \n");
    printf("    | $$  | $$ /$$__  $$| $$_  $$_  $$| $$| $$__  $$ /$$__  $$| $$  | $$ /$$__  $$\n");
    printf("    | $$  | $$| $$$$$$$$| $$ \\ $$ \\ $$| $$| $$  \\ $$| $$$$$$$$| $$  | $$| $$  \\/_/\n");
    printf("    | $$  | $$| $$_____/| $$ | $$ | $$| $$| $$  | $$| $$_____/| $$  | $$| $$      \n");
    printf("    | $$$$$$$/|  $$$$$$$| $$ | $$ | $$| $$| $$  | $$|  $$$$$$$|  $$$$$$/| $$      \n");
    printf("    |/______/  \\/______/|/_/ |/_/ |/_/|/_/|/_/  |_/ \\/______/ \\/_____/ |/_/       \n");
    printf("\n");
    printf("\n");
    
    /* Affichage de la grille */
    printf("   ┌");
    for(int i=0; i<int_taille_grille_x-1; i++){
            printf("───┬");
    }
    printf("───┐\n");

       
    for(int i=0; i<int_taille_grille_x; i++){

        printf("   ");

        for(int j=0; j<int_taille_grille_y; j++) {
            
            if(ppCaseGrille_grille[i][j].bool_vu == false) {

                if(ppCaseGrille_grille[i][j].bool_drapeau == true) {
                            
                    if(i == int_curseur_x && j == int_curseur_y) {
                        printf("│" B_GREEN YEL " F " RESET);
                    } else {
                        printf("│" YEL " F " RESET);
                    }

                } else {

                    if(i == int_curseur_x && j == int_curseur_y) {
                        printf("│" B_GREEN " · " RESET);
                    } else {
                        printf("│ · ");
                    }
                }

            } else {
                if(ppCaseGrille_grille[i][j].bool_bombe == true) {
                    
                    if(i == int_curseur_x && j == int_curseur_y) {
                        printf("│ " B_GREEN RED "X" RESET " ");
                    } else {
                        printf("│ X ");
                    }
                    
                } else {

                    if(ppCaseGrille_grille[i][j].int_valeur != 0) {

                        if(i == int_curseur_x && j == int_curseur_y) {
                            printf("│ " B_GREEN "%d" RESET " ", ppCaseGrille_grille[i][j].int_valeur);
                        } else {
                            printf("│ %d ", ppCaseGrille_grille[i][j].int_valeur);
                        }

                    } else {
                        
                        if(i == int_curseur_x && j == int_curseur_y) {
                            printf("│" B_GREEN "   " RESET);
                        } else {
                            printf("│   ");
                        }
                    
                    } 
                }
            }
        }
        printf("│\n");

        if(i != int_taille_grille_x-1) {
            printf("   ├");
            for(int j=0; j<int_taille_grille_y-1; j++) {
                printf("───┼");
            }
            printf("───┤\n");
        } else {
            printf("   └");
            for(int j=0; j<int_taille_grille_y-1; j++) {
                printf("───┴");
            }
            printf("───┘\n");
        }
    }
}

int afficherNombreBombe(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_i, int int_j) {
    
    int int_nombre_bombe; // Nombre de bombe

    /* Initialisation */
    int_nombre_bombe = 0;

    for(int i=-1; i<2; i++) {
        for(int j=-1; j<2; j++) {
            if( int_i+i >= 0 && int_i+i < int_taille_grille_x && int_j+j >= 0 && int_j+j < int_taille_grille_y && ppCaseGrille_grille[int_i+i][int_j+j].bool_bombe == true) {
               /* Il y a une bombe environnante, donc incrementation du nombre de bombe */
               int_nombre_bombe++;
            }
        }
    }

    return (int_nombre_bombe);
}


void reveler(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_x, int int_y) {
    
    int int_tmp; // Nombre de bombe environnante temporaire
    
    /* Initialisation */
    int_tmp = afficherNombreBombe(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, int_x, int_y);

    if(int_tmp == 0) {

        for(int i=-1; i<2; i++) {
            for(int j=-1; j<2; j++) {
                if( int_x+i >= 0 && int_x+i < int_taille_grille_x && int_y+j >= 0 && int_y+j < int_taille_grille_y && ppCaseGrille_grille[int_x+i][int_y+j].bool_vu == false) {
                    
                    int_tmp = afficherNombreBombe(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, int_x+i, int_y+j);
                
                    if(ppCaseGrille_grille[int_x+i][int_y+j].bool_bombe == false && ppCaseGrille_grille[int_x+i][int_y+j].bool_drapeau == false) {
                        
                        ppCaseGrille_grille[int_x+i][int_y+j].bool_vu = true;
                        ppCaseGrille_grille[int_x+i][int_y+j].int_valeur = int_tmp;

                        if( int_tmp == 0) {
                            /* Revelation des cases environnantes */
                            reveler(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, int_x+i, int_y+j);
                        }
                    }
                }
            }
        }
    } else {
        /* Revelation de la case */
        ppCaseGrille_grille[int_x][int_y].bool_vu = true;
        ppCaseGrille_grille[int_x][int_y].int_valeur = int_tmp;
    }
}

int partieFini(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_bombe) {
    
    int int_nombre_bombe; // Nombre de case sans bombe

    /* Initialisation */
    int_nombre_bombe = 0;
    
    int i;
    int j;

    i = 0;

    while(i<int_taille_grille_x && int_nombre_bombe != -1) {
        
        j = 0;

        while(j<int_taille_grille_y && int_nombre_bombe != -1) {

            if(ppCaseGrille_grille[i][j].bool_vu == true) {
                /* Incrementation */
                int_nombre_bombe++;

                if(ppCaseGrille_grille[i][j].bool_bombe == true) {
                    /* le joueur a perdu */
                    int_nombre_bombe = -1;               
                }
            }

            j++;
        }
        
        i++;
    }

    if(int_nombre_bombe == -1) {
        return (PERDU);
    }

    if(int_nombre_bombe == int_taille_grille_x*int_taille_grille_y - int_bombe) {
        /* Le joueur a gagné */
        return (VICTOIRE);
    }

    return 0;
}

int jouerDemineur(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int int_x, int int_y) {
    
    /* Vérification si la case à déjà été vu */
    if(ppCaseGrille_grille[int_x][int_y].bool_vu == true) {
        return (DEJA_VU);
    }

    /* Vérification si la case est une bombe */
    if(ppCaseGrille_grille[int_x][int_y].bool_bombe == true) {
        ppCaseGrille_grille[int_x][int_y].bool_vu = true;
        return (BOMBE);
    }

    /* Révéler la case */
    reveler(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, int_x, int_y);
    return (0);
}

void saisie(CaseGrille** ppCaseGrille_grille, int int_taille_grille_x, int int_taille_grille_y, int* pint_x, int* pint_y) {
    
    int int_touche; // Caractère saisie
    
    do {
        /* Lecture d'une touche */
        int_touche = lireTouche();

        /* Deplacement dans la grille en fonction de la touche saisie */
        if(int_touche == HAUT && *pint_x-1 >= 0) {
            *pint_x -= 1;
            afficherGrille(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, *pint_x, *pint_y);
        }

        if(int_touche == BAS && *pint_x+1 < int_taille_grille_x) {
            *pint_x += 1;
            afficherGrille(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, *pint_x, *pint_y);
        }

        if(int_touche == GAUCHE && *pint_y-1 >= 0) {
            *pint_y -= 1;
            afficherGrille(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, *pint_x, *pint_y);
        }

        if(int_touche == DROITE && *pint_y+1 < int_taille_grille_y) {
            *pint_y +=1;
            afficherGrille(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, *pint_x, *pint_y);    
        }

        /* Test sur la touche 'F' */ 
        if(int_touche == 102 && ppCaseGrille_grille[*pint_x][*pint_y].bool_vu == false) {
            /* Affichage d'un drapeau dans la grille */
            if(ppCaseGrille_grille[*pint_x][*pint_y].bool_drapeau == false) {
                ppCaseGrille_grille[*pint_x][*pint_y].bool_drapeau = true;
            } else {
                ppCaseGrille_grille[*pint_x][*pint_y].bool_drapeau = false;
            }
            afficherGrille(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, *pint_x, *pint_y);
        }

    } while (int_touche != 10);
}

void demineur(void) {

    int int_taille_grille_x; // Taille de la grille en x
    int int_taille_grille_y; // taille de la grille en y

    int int_nombre_bombe; // Nombre de bombe dans la grille

    /* Initialisation */
    int_taille_grille_x=10;
    int_taille_grille_y=10;
    int_nombre_bombe = 10;

    CaseGrille** ppCaseGrille_grille; // Grille de jeu du démineur

    /* Allocation */
    ppCaseGrille_grille = calloc(int_taille_grille_x, sizeof(CaseGrille*));

    /* Vérification allocation */
    if(ppCaseGrille_grille == NULL) {
        printf("Erreur allocation mémoire\n");
        exit(ERREUR_ALLOCATION_MEMOIRE);
    }

    for(int i=0; i<int_taille_grille_y; i++) {
        ppCaseGrille_grille[i] = calloc(int_taille_grille_y, sizeof(CaseGrille));

        /* Vérification allocation */
        if(ppCaseGrille_grille[i] == NULL) {
            printf("Erreur allocation mémoire\n");
            exit(ERREUR_ALLOCATION_MEMOIRE);
        }
    }

    int int_curseur_x; // Position de la case actuelle du joueur en x
    int int_curseur_y; // Position de la case actuelle du joueur en y

    /* Initialisation */
    int_curseur_x = 0; 
    int_curseur_y = 0;

    initGrille(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, int_nombre_bombe);

    /* Affichage de la grille */
    afficherGrille(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, 0, 0);

    int int_jouer_valeur; // Valeur de retour pour le tour du joueur
    int int_partie_fini_valeur; // Valeur de retour pour savoir si la partie est finie
 
    do {
        do {   
            /* Sélection de la case */  
            saisie(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, &int_curseur_x, &int_curseur_y);

            /* Tour du joueur */
            int_jouer_valeur = jouerDemineur(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, int_curseur_x, int_curseur_y);

        } while (int_jouer_valeur == DEJA_VU);

        /* Affichage de la partie */
        afficherGrille(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, int_curseur_x, int_curseur_y);

        /* Test si la partie est finie */
        int_partie_fini_valeur = partieFini(ppCaseGrille_grille, int_taille_grille_x, int_taille_grille_y, int_nombre_bombe);
    } while (int_partie_fini_valeur != PERDU && int_partie_fini_valeur !=VICTOIRE);

    /* Affichage du resultat */
    if(int_partie_fini_valeur == PERDU) {
        printf("Tu as perdu\n");
    } else {
        printf("Tu as gagné\n");
    }

    /* Libération de la mémoire */
    for(int i=0; i<int_taille_grille_x; i++) {
        free(ppCaseGrille_grille[i]);
    }
    free(ppCaseGrille_grille);
}
