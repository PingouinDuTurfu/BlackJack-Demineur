#include "blackjack.h"


void fisherYates(sCarte* psCarte_cartes, int int_nombre_jeu_carte) {

    sCarte sCarte_tmp;  // Carte temporaire
    int i;
    int j;

    /* Mélange des cartes */
    for (i = int_nombre_jeu_carte*TAILLE_JEU - 1; i > 0; i--) {
        j = rand() % (i + 1);
        sCarte_tmp = psCarte_cartes[j];
        psCarte_cartes[j] = psCarte_cartes[i];
        psCarte_cartes[i] = sCarte_tmp;
    }
}



void initCartes(sCarte* psCarte_cartes, int int_nombre_jeu_carte) {
    
    for(int i=0; i<int_nombre_jeu_carte*NOMBRE_COULEUR; i++) {
        for (int j=0; j<NOMBRE_VALEUR; j++) {
            /* Initialisation de la valeur */
            psCarte_cartes[i*NOMBRE_VALEUR+j].int_valeur = j+1;
            /* Initialisation de la couleur */
            psCarte_cartes[i*NOMBRE_VALEUR+j].eCouleur_couleur = i/int_nombre_jeu_carte;
        }
    }
}

sCarte defilerJeu(sCarte* psCarte_cartes, int int_nombre_jeu_carte, int* pint_curseur_defilement) {
    
    sCarte sCarte_carte; // Carte

    /* Si il reste des cartes dans le jeu alors renvoyé une carte */
    if(*pint_curseur_defilement < int_nombre_jeu_carte*TAILLE_JEU) {
        sCarte_carte = psCarte_cartes[*pint_curseur_defilement];
        /* Incrément du l'indice dans le jeu de carte */
        *pint_curseur_defilement += 1;
    }

    /* Renvoie de la carte */
    return(sCarte_carte);
}

void tirerCarte(sJoueur* sJoueur_joueurs, sCarte* psCarte_cartes, int int_nombre_jeu_carte, int* pint_curseur_defilement) {
    /* Increment du nombre de carte du joueur */
    sJoueur_joueurs->int_nombre_cartes += 1;
    /* Reallocation de la taille du jeu de carte du joueur */
    sJoueur_joueurs->psCarte_cartes = realloc(sJoueur_joueurs->psCarte_cartes, sJoueur_joueurs->int_nombre_cartes*sizeof(sCarte));
    
    if(sJoueur_joueurs->psCarte_cartes == NULL) {
        printf("Erreur allocation mémoire\n");
        exit(ERREUR_ALLOCATION_MEMOIRE);
    }
    
    /* Ajout de la nouvelle carte dans le jeu du joueur */
    sJoueur_joueurs->psCarte_cartes[sJoueur_joueurs->int_nombre_cartes-1] = defilerJeu(psCarte_cartes, int_nombre_jeu_carte, pint_curseur_defilement);
}


int maxCarteJoueurs(sJoueur* psJoueur_joueurs, int int_nombre_joueurs) {
    
    int int_max; // Valeur max de carte trouvé

    int_max = 0;
    
    /* Test pour tous les joueurs */
    for(int i=0; i<int_nombre_joueurs; i++) {
        if (psJoueur_joueurs[i].int_nombre_cartes > int_max) {
            int_max = psJoueur_joueurs[i].int_nombre_cartes;
        }
    }

    /* Renvoie de la valeur max */
    return(int_max);
}


char* saisiePseudoJoueur(void) {
        
    char* pchar_pseudo; // pseudo

    int int_curseur; // Index de position du caractère actuel
    /* Initialisation */
    int_curseur = 0;

    int int_touche; // Caractère saisie

    /* Allocation */
    pchar_pseudo = malloc(TAILLE_PSEUDO*sizeof(char));
    
    /* Verification de l'allocation */
    if(pchar_pseudo == NULL) {
        printf("Erreur allocation mémoire\n");
        exit(ERREUR_ALLOCATION_MEMOIRE);
    }

    /* Affichage du menu de saisie du pseudo */
    do {
        affichageHaut();

        printf("   ¦ │                               Entrez votre pseudo :                              ¦ │\n");
        printf("   ¦ │                                                                                  ¦ │\n");

        printf("   ¦ │                                  ");

        for(int i=0; i<TAILLE_PSEUDO-1; i++) {
            if( i < int_curseur) {
                printf("%c", pchar_pseudo[i]);
            } else {
                printf("ˍ");
            }
        }

        printf("                                  ¦ │\n");

        /* Affichage partie basse */
        affichageBas();

        /* Lecture d'un cararctère */
        int_touche = lireTouche();

        /* Test sur le caractère */
        if(tolower(int_touche) >= 'a' && tolower(int_touche) <= 'z' && int_curseur < TAILLE_PSEUDO-1) {
            pchar_pseudo[int_curseur] = int_touche;
            int_curseur++;
        }

        if(int_touche == 127 && int_curseur >=0) {
            int_curseur--;
            pchar_pseudo[int_curseur] = '\0';
        }

    } while (int_touche != 10 || int_curseur == 0);

    /* Ajout du caractère fin de chaine */
    pchar_pseudo[int_curseur] = '\0';

    return pchar_pseudo;
}

void creerNouveauJoueur(sJoueur** psJoueur_joueurs, int* int_nombre_joueurs, char* pchar_pseudo) {
    
    /* Increment du nombre de joueur */
    *int_nombre_joueurs += 1;
    
    /* Reallocation de la mémoire sur la liste des joueurs */
    (*psJoueur_joueurs) = realloc((*psJoueur_joueurs) , (*int_nombre_joueurs) * sizeof(sJoueur));

    /* Vérification de l'allocation */
    if(psJoueur_joueurs == NULL) {
        printf("Erreur allocation mémoire\n");
        exit(ERREUR_ALLOCATION_MEMOIRE);
    }
    
    /* Allocation pour le pseudo */
    (*psJoueur_joueurs)[*int_nombre_joueurs-1].pchar_pseudo = calloc(TAILLE_PSEUDO, sizeof(char));
    
    /* Vérification de l'allocation */
    if((*psJoueur_joueurs)[*int_nombre_joueurs-1].pchar_pseudo == NULL) {
        printf("Erreur allocation mémoire\n");
        exit(ERREUR_ALLOCATION_MEMOIRE);
    }

    /* Copy du pseudo dans la structure */
    strcpy((*psJoueur_joueurs)[*int_nombre_joueurs-1].pchar_pseudo, pchar_pseudo);
    
    /* Liberation */
    free(pchar_pseudo);

    /* Initialisation du reste de la structure */
    (*psJoueur_joueurs)[(*int_nombre_joueurs)-1].int_jeton = 300;
    (*psJoueur_joueurs)[(*int_nombre_joueurs)-1].int_mise = 0;
    (*psJoueur_joueurs)[(*int_nombre_joueurs)-1].int_nombre_cartes = 0;
    (*psJoueur_joueurs)[(*int_nombre_joueurs)-1].psCarte_cartes = malloc (0*sizeof(sCarte));

    if((*psJoueur_joueurs)[(*int_nombre_joueurs)-1].psCarte_cartes == NULL) {
        printf("Erreur allocation mémoire\n");
        exit(ERREUR_ALLOCATION_MEMOIRE);
    }

    (*psJoueur_joueurs)[(*int_nombre_joueurs)-1].bool_assurer = false;
}

int recupererNumeroJoueur(sJoueur* psJoueur_joueurs, int int_nombre_joueurs) {
    
    int int_curseur; // Index de position du caractère actuel
    int int_touche; // Caractère saisie
    
    /* Initialisation */
    int_curseur = 0;


    do{
        /* Affichage de l'en-tête */
        affichageHaut();

        /* Affichage du menu de suppression */
        printf("   ¦ │                                                                                  ¦ │\n");
        printf("   ¦ │                           Choisir le joueur à supprimer :                        ¦ │\n");
        printf("   ¦ │                                                                                  ¦ │\n");
        for(int i=0; i<int_nombre_joueurs; i++) {
            if(int_curseur == i) {
                printf("   ¦ │                               [*] ");
            } else {
                printf("   ¦ │                               [ ] ");
            }
            affichageChaineAutoCompletion(psJoueur_joueurs[i].pchar_pseudo, TAILLE_PSEUDO);
            printf("                                ¦ │\n");
        }
        printf("   ¦ │                                                                                  ¦ │\n");
        
        /* Affichage partie basse */
        affichageBas();

        /* Lecture d'une touche */
        int_touche = lireTouche();

        /* Test sur le caractère lu */
        if(int_touche == HAUT && int_curseur > 0) {
            int_curseur--;
        } 

        if(int_touche == BAS && int_curseur < int_nombre_joueurs-1) {
            int_curseur++;
        }
    } while(int_touche != 10);

    return (int_curseur);
}

void supprimerJoueur(sJoueur** psJoueur_joueurs, int* int_nombre_joueurs, int int_numero_joueur) {


    /* Décalage de tous les indices après le joueur sélectionné */
    for(int i=int_numero_joueur; i<(*int_nombre_joueurs)-1; i++) {
        (*psJoueur_joueurs)[i] = (*psJoueur_joueurs)[i+1];
    }
    
    /* Décrémentation du nombre de joueur */
    *int_nombre_joueurs -= 1;
    /* Réallocation de la mémoire */
    (*psJoueur_joueurs) = realloc((*psJoueur_joueurs) , (*int_nombre_joueurs) * sizeof(sJoueur));

    /* Vérification de l'allocation */
    if(psJoueur_joueurs == NULL) {
        printf("Erreur allocation mémoire\n");
        exit(ERREUR_ALLOCATION_MEMOIRE);
    }
}

int valeurMain(sJoueur sJoueur_joueur) {
    
    int int_result; // Valeur de la main
    int int_nombre_as; // Nombre d'as dans la main

    /* Initialisation */
    int_result = 0;
    int_nombre_as = 0;

    /* Ajout de la valeur de chaque carte */
    for(int i=0; i<sJoueur_joueur.int_nombre_cartes; i++) {
        switch (sJoueur_joueur.psCarte_cartes[i].int_valeur)
        {
        case AS:
            int_result += 1;
            int_nombre_as++;
            break;
        
        case VALET:
            int_result += 10;
            break;
        
        case DAME:
            int_result += 10;
            break;
        
        case ROI:
            int_result += 10;
            break;

        default:
            int_result += sJoueur_joueur.psCarte_cartes[i].int_valeur;
        }
    }

    /* Pour les as, test pour la valeur 11 */
    for(int i=0; i<int_nombre_as; i++) {
        if(int_result + 10 <= 21) {
            int_result += 10;
        } 
    }

    return(int_result);
}

void avantPartie(sCarte* psCarte_cartes, int int_nombre_jeu_carte, sJoueur** psJoueur_joueurs, int* int_nombre_joueurs, int* pint_curseur_defilement) {

    int int_touche; // Caractère saisie
    int int_choix; // Position du curseur de choix dans le menu

    /* Initialisation */
    int_choix = 1;

    do {
        do {
            /* Affichage menu */
            affichageAvantPartie(*psJoueur_joueurs, *int_nombre_joueurs, int_choix);
            
            /* Lecture d'une touche */
            int_touche = lireTouche();
            
            /* Test sur le caractère lu */
            switch (int_touche)
            {
            case GAUCHE:
                if(int_choix > 1) {
                    int_choix--;
                }
                break;
            
            case DROITE:
                if(int_choix < 3) {
                    int_choix++;
                }
                break;
            

            default:
                break;
            }
        } while (int_touche != 10);

        if(int_choix == 1 && *int_nombre_joueurs <= 4) {
            /* Création d'un nouveau joueur */
            creerNouveauJoueur(psJoueur_joueurs, int_nombre_joueurs, saisiePseudoJoueur());
        } 


        if( int_choix == 2 && *int_nombre_joueurs > 0) {
            /* Suppression d'un joueur */
            supprimerJoueur(psJoueur_joueurs, int_nombre_joueurs, recupererNumeroJoueur(*psJoueur_joueurs, *int_nombre_joueurs));
        }

    } while (int_choix != 3);
    
    /* Trage de deux cartes pour chaque joueur */
    for(int i=0; i<*int_nombre_joueurs; i++) {
        tirerCarte(&(*psJoueur_joueurs)[i], psCarte_cartes, int_nombre_jeu_carte, pint_curseur_defilement);
        tirerCarte(&(*psJoueur_joueurs)[i], psCarte_cartes, int_nombre_jeu_carte, pint_curseur_defilement);
    }


    /* Ajout de la banque dans les joueurs*/
    char* pchar_banquePseudo;
    pchar_banquePseudo = malloc(TAILLE_PSEUDO*sizeof(char));

    if(pchar_banquePseudo == NULL) {
        printf("Erreur allocation mémoire\n");
        exit(ERREUR_ALLOCATION_MEMOIRE);
    }

    sprintf(pchar_banquePseudo, "banque");
    creerNouveauJoueur(psJoueur_joueurs, int_nombre_joueurs, pchar_banquePseudo);
    /* Tirage d'un carte pour la banque */
    tirerCarte(&(*psJoueur_joueurs)[*int_nombre_joueurs-1], psCarte_cartes, int_nombre_jeu_carte, pint_curseur_defilement);
}


void jouerBlackjack(sCarte* psCarte_cartes, int int_nombre_jeu_carte, sJoueur** psJoueur_joueurs, int int_nombre_joueurs, int* pint_curseur_defilement, int int_numero_joueur) {    
    
    int int_touche; // Caractère saisie
    int int_choix; // Position du curseur de choix dans le menu
    int int_choix_max; // Nombre de choix max

    bool* pbool_options; // Tableau de booléen pour chaque option

    /* Allocation */
    pbool_options = malloc(NOMBRE_OPTION*sizeof(bool));

    /* Vérification allocation */
    if(pbool_options == NULL) {
        printf("Erreur allocation mémoire\n");
        exit(ERREUR_ALLOCATION_MEMOIRE);
    }

    /* Initialisation */
    int_choix = 1;
    int_choix_max = 2;

    /* Test si le joueur à suffisament de jeuton pour doubler sa mise */
    if((*psJoueur_joueurs)[int_numero_joueur].int_mise <= (*psJoueur_joueurs)[int_numero_joueur].int_jeton && (*psJoueur_joueurs)[int_numero_joueur].int_nombre_cartes == 2) {
        pbool_options[DOUBLER] = true;
        int_choix_max++;
    } else {
        pbool_options[DOUBLER] = false;
    }


    do {
        do {
            /* Affichage de la partie */
            affichagePartie(*psJoueur_joueurs, int_nombre_joueurs, int_numero_joueur, int_choix, pbool_options, false);
            
            /* Lecture d'un touche */
            int_touche = lireTouche();
            
            /* Test sur le caractère lu */
            switch (int_touche)
            {
            case GAUCHE:
                if(int_choix > 1) {
                    int_choix--;
                }
                break;
            
            case DROITE:
                if(int_choix < int_choix_max) {
                    int_choix++;
                }
                break;
            

            default:
                break;
            }


        } while (int_touche != 10);

        /* Action en fonction du choix fait par le joueur */
        switch (int_choix)
        {
        case 1:
            /* Tirage d'une carte */
            tirerCarte(&(*psJoueur_joueurs)[int_numero_joueur], psCarte_cartes, int_nombre_jeu_carte, pint_curseur_defilement);
            break;

        case 3:
            /* Doubler la mise */
            (*psJoueur_joueurs)[int_numero_joueur].int_jeton -= (*psJoueur_joueurs)[int_numero_joueur].int_mise ; 
            (*psJoueur_joueurs)[int_numero_joueur].int_mise *= 2;
            
            /* Tirage d'une carte */
            tirerCarte(&(*psJoueur_joueurs)[int_numero_joueur], psCarte_cartes, int_nombre_jeu_carte, pint_curseur_defilement);

            pbool_options[DOUBLER] = false;

            int_choix_max--;
            int_choix = 1;
            break;

        default:
            break;
        }

    } while(int_choix != 2 && valeurMain((*psJoueur_joueurs)[int_numero_joueur]) < 21);

    /* Affichage si le joueur a brulé */
    if( valeurMain((*psJoueur_joueurs)[int_numero_joueur]) > 21) {
        int_choix = -1;
        affichagePartie(*psJoueur_joueurs, int_nombre_joueurs, int_numero_joueur, int_choix, pbool_options, false);
        int_touche = lireTouche();
    } else {
        affichagePartie(*psJoueur_joueurs, int_nombre_joueurs, int_numero_joueur, int_choix, pbool_options, false);
    }

    free(pbool_options);
}


void miserBlackjack( sJoueur** psJoueur_joueurs, int int_nombre_joueurs, int int_numero_joueur) {
    
    char* pchar_mise; // Chaine de la mise d'un joueur
    char* pchar_jeton; // Chaine des jeuton d'un joueur

    /* Allocation */
    pchar_mise = malloc((TAILLE_MISE + 1) * sizeof(char));
    pchar_jeton = malloc((TAILLE_JETON + 1) * sizeof(char));

    /* Ecriture dans les chaines */
    sprintf(pchar_mise, "%d",(*psJoueur_joueurs)[int_numero_joueur].int_mise);
    sprintf(pchar_jeton, "%d",(*psJoueur_joueurs)[int_numero_joueur].int_jeton);

    /* Affichage de l'en-tête */
    affichageHaut();

    /* Affichage côtés */
    for(int i=0; i<9; i++) {
        printf("   ¦ │                                                                                  ¦ │\n");
    }

    int int_decalage_verticale; // Décalage du curseur dans le terminal

    /* Initialisation */
    int_decalage_verticale = 10;

    /* Décalage */
    printf("\x1B[%dA", int_decalage_verticale);

    /*Affichage si il y a 4 joueurs */
    if(int_nombre_joueurs-1 >= 4) {
        affichageMiser(71, (*psJoueur_joueurs)[3].pchar_pseudo, (*psJoueur_joueurs)[3].int_mise);
    } else {
        affichageCarteVide(71);
    }

    printf("\x1B[%dA", int_decalage_verticale);

    /*Affichage si il y a 2 joueurs */
    if(int_nombre_joueurs-1 >= 2) {
        affichageMiser(56, (*psJoueur_joueurs)[1].pchar_pseudo, (*psJoueur_joueurs)[1].int_mise);
    } else {
        affichageCarteVide(56);
    }   

    printf("\x1B[%dA", int_decalage_verticale);
    
    /*Affichage si il y a 1 joueur */
    if(int_nombre_joueurs-1 >= 1) {
        affichageMiser(41, (*psJoueur_joueurs)[0].pchar_pseudo, (*psJoueur_joueurs)[0].int_mise);
    } else {
        affichageCarteVide(41);
    }

    printf("\x1B[%dA", int_decalage_verticale);
    
    /*Affichage si il y a 3 joueurs */
    if(int_nombre_joueurs-1 >= 3) {
        affichageMiser(26, (*psJoueur_joueurs)[2].pchar_pseudo, (*psJoueur_joueurs)[2].int_mise);
    } else {
        affichageCarteVide(26);
    }
    
    printf("\x1B[%dA", int_decalage_verticale);

    /*Affichage si il y a 4 joueurs */
    if(int_nombre_joueurs-1 == 5) {
        affichageMiser(11, (*psJoueur_joueurs)[4].pchar_pseudo, (*psJoueur_joueurs)[4].int_mise);
    } else {
        affichageCarteVide(11);
    }

    /* Affichage de la saisie de la mise */
    printf("   ¦ │                                                                                  ¦ │\n");
    printf("   ¦ │                                                                                  ¦ │\n");
    
    printf("\x1B[A\x1B[%dC", 45  - (int) (strlen((*psJoueur_joueurs)[int_numero_joueur].pchar_pseudo) -1 + strlen(" a vous de miser : ()") -1 + strlen(pchar_jeton) -1)/2);
    printf("\x1B[4m%s\x1B[m a vous de miser : (", (*psJoueur_joueurs)[int_numero_joueur].pchar_pseudo);
    affichageChaineAutoCompletion(pchar_jeton, TAILLE_JETON);
    printf(")\n");

    printf("   ¦ │                                        ");
    affichageChaineAutoCompletion(pchar_mise, TAILLE_MISE);
    printf("                                       ¦ │\n");
    printf("   ¦ │                                                                                  ¦ │\n");

    /* Affichage partie basse */
    affichageBas();

    int int_touche; // Saisie d'un caractère 

    do {
        /* Lecture d'une touche */
        int_touche = lireTouche();
        
        /* Test sur le caractère lu */
        if(int_touche <= '9' 
            && int_touche >= '0' 
            && (*psJoueur_joueurs)[int_numero_joueur].int_mise < 100 
            && (*psJoueur_joueurs)[int_numero_joueur].int_jeton >= (*psJoueur_joueurs)[int_numero_joueur].int_mise * 10 + (int_touche-'0'))
            {

            (*psJoueur_joueurs)[int_numero_joueur].int_mise = (*psJoueur_joueurs)[int_numero_joueur].int_mise * 10 + (int_touche-'0');
        }

        if(int_touche == 127) {
            (*psJoueur_joueurs)[int_numero_joueur].int_mise = (*psJoueur_joueurs)[int_numero_joueur].int_mise / 10;
        }

        /* Déclage vers le haut */
        printf("\x1B[5A");

        sprintf(pchar_mise, "%d",(*psJoueur_joueurs)[int_numero_joueur].int_mise);

        printf("   ¦ │                                       ");
        
        
        if((*psJoueur_joueurs)[int_numero_joueur].int_mise > 99) {
            printf("%s", pchar_mise);
        } else {
            if((*psJoueur_joueurs)[int_numero_joueur].int_mise > 9) {
                printf("%s ", pchar_mise);
            } else {
                printf(" %s ", pchar_mise);
            }
        }
    
        printf("                                        ¦ │\n");
        printf("   ¦ │                                                                                  ¦ │\n");

        /* Affichage partie basse */
        affichageBas();

    } while(int_touche != 10 || (*psJoueur_joueurs)[int_numero_joueur].int_mise == 0);

    (*psJoueur_joueurs)[int_numero_joueur].int_jeton -= (*psJoueur_joueurs)[int_numero_joueur].int_mise;

    /* Libération de la mémoire */
    free(pchar_mise);
    free(pchar_jeton);   
}

void partie(sCarte* psCarte_cartes, int int_nombre_jeu_carte, sJoueur** psJoueur_joueurs, int int_nombre_joueurs, int* pint_curseur_defilement) {
    
    switch (int_nombre_joueurs - 1)
    {
    case 1:
        /*partie si il y a 1 joueur */
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 0);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 0);
        break;
    
    case 2:
        /*partie si il y a 2 joueurs */
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 1);
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 0);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 1);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 0);
        break;

    case 3:
        /*partie si il y a 3 joueurs */
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 1);
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 0);
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 2);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 1);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 0);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 2);
        break;

    case 4:
        /*partie si il y a 4 joueurs */
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 3);
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 1);
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 0);
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 2);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 3);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 1);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 0);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 2);
        break;

    case 5:
        /*partie si il y a 5 joueurs */
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 3);
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 1);
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 0);
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 2);
        miserBlackjack(psJoueur_joueurs, int_nombre_joueurs, 4);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 3);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 1);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 0);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 2);
        jouerBlackjack(psCarte_cartes, int_nombre_jeu_carte, psJoueur_joueurs, int_nombre_joueurs, pint_curseur_defilement, 4);
        break;

    default:
        break;
    }

    /* Tirage des cartes par la banque */
    while( valeurMain((*psJoueur_joueurs)[int_nombre_joueurs-1]) < 17) {
        tirerCarte(&(*psJoueur_joueurs)[int_nombre_joueurs-1], psCarte_cartes, int_nombre_jeu_carte, pint_curseur_defilement);
    }
    affichagePartie(*psJoueur_joueurs, int_nombre_joueurs, int_nombre_joueurs-1, -2, NULL, true);
}

void blackjack(void) {

    int int_nombre_jeu_carte; // Nombre de jeu de cartes utilisé
    int int_curseur_defilement; // Curseur de postion de la carte dans le jeu de carte
    int int_nombre_joueurs; // Nombre de joueur

    sCarte* psCarte_cartes; // Cartes du jeu
    sJoueur* psJoueur_joueurs; // Liste des joueurs

    /* Initialisation */
    int_nombre_jeu_carte = 1;
    int_curseur_defilement = 0;
    int_nombre_joueurs = 0;

    /* Allocation du jeu de cartes */
    psCarte_cartes = malloc((int_nombre_jeu_carte*TAILLE_JEU) * sizeof(sCarte));

    /* Vérifaication allocation */
    if(psCarte_cartes == NULL) {
        printf("Erreur allocation mémoire\n");
        exit(ERREUR_ALLOCATION_MEMOIRE);
    }
    
    /* Allocation de la liste des joueurs */
    psJoueur_joueurs = malloc(0*sizeof(sJoueur));
    
    /* Vérifaication allocation */
    if(psJoueur_joueurs == NULL) {
        printf("Erreur allocation mémoire\n");
        exit(ERREUR_ALLOCATION_MEMOIRE);
    }

    /* Initialisation du jeu de cartes */
    initCartes(psCarte_cartes, int_nombre_jeu_carte);
    fisherYates(psCarte_cartes, int_nombre_jeu_carte);

    /* Creation de la partie */
    avantPartie(psCarte_cartes, int_nombre_jeu_carte, &psJoueur_joueurs, &int_nombre_joueurs, &int_curseur_defilement);

    /* Lancement de la partie */
    partie(psCarte_cartes, int_nombre_jeu_carte, &psJoueur_joueurs, int_nombre_joueurs, &int_curseur_defilement);


    /* Libération de la mémoire */
    for(int i=0; i< int_nombre_joueurs; i++) {
        free(psJoueur_joueurs[i].pchar_pseudo);
        free(psJoueur_joueurs[i].psCarte_cartes);
    }
    free(psJoueur_joueurs);
    free(psCarte_cartes);
}