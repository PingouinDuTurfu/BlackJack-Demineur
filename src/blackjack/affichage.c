#include "affichage.h"

void affichageChaineAutoCompletion(char* chaine, int int_taille_chaine) {
    
    int i; // curseur de position
    i = 0;
 

    /* le curseur est dans la chaine */
    while(i < strlen(chaine)) {
        printf("%c", chaine[i]);
        i++;
    }

    /* le curseur est hors de la chaine */
    for(int j=i; j<int_taille_chaine; j++) {
        printf(" ");
    }


}

void affichageHaut() {
    /* Effacement de l'écran */
    system("clear");

    /* Affichage de l'en-tête */
    printf("     ┌────────────────────────────────────────────────────────────────────────────────────┐\n");
    printf("    /│                                                                                   /│\n");
    printf("   ┌-│----------------------------------------------------------------------------------┐ │\n");
    printf("   ¦ │    /$$$$$$$  /$$                     /$$                               /$$       ¦ │\n");
    printf("   ¦ │   | $$__  $$| $$                    | $$                              | $$       ¦ │\n");
    printf("   ¦ │   | $$  \\ $$| $$  /$$$$$$   /$$$$$$$| $$   /$$ /$$  /$$$$$$   /$$$$$$$| $$   /$$ ¦ │\n");
    printf("   ¦ │   | $$$$$$$ | $$ |____  $$ /$$_____/| $$  /$$/|__/ |____  $$ /$$_____/| $$  /$$/ ¦ │\n");
    printf("   ¦ │   | $$__  $$| $$  /$$$$$$$| $$      | $$$$$$/  /$$  /$$$$$$$| $$      | $$$$$$/  ¦ │\n");
    printf("   ¦ │   | $$  \\ $$| $$ /$$__  $$| $$      | $$_  $$ | $$ /$$__  $$| $$      | $$_  $$  ¦ │\n");
    printf("   ¦ │   | $$$$$$$/| $$|  $$$$$$$|  $$$$$$$| $$ \\  $$| $$|  $$$$$$$|  $$$$$$$| $$ \\  $$ ¦ │\n");
    printf("   ¦ │   |/______/ |/_/ \\/______/ \\/______/|/_/  \\/_/| $$ \\/______/ \\/______/|/_/  \\/_/ ¦ │\n");
    printf("   ¦ │                                          /$$  | $$                               ¦ │\n");
    printf("   ¦ │                                         |  $$$$$$/                               ¦ │\n");
    printf("   ¦ │                                          \\/_____/                                ¦ │\n");
    printf("   ¦ │                                                                                  ¦ │\n");
    printf("   ¦ ├────────────────────────────────────────────────────────────────────────────────────┤\n");
    printf("   ¦/│                                                                                  ¦/│\n");
    printf("   ├-│----------------------------------------------------------------------------------┤ │\n");
    
}

void affichageCotes(int int_nombre_lignes) {
    /* Affichage des côtés */
    for(int i=0; i < 6 + 9 + (3* (int_nombre_lignes-1) +4); i++) {
        printf("   ¦ │                                                                                  ¦ │\n");
    }
    /* decalage du cuseur d'affichage vers le haut */
    printf("\x1B[%dA", 6 + 9 + (3* (int_nombre_lignes-1) +4));
}

void affichageBas() {

    /* affichage du bas */
    printf("   ¦ └────────────────────────────────────────────────────────────────────────────────────┘\n");
    printf("   ¦/                                                                                   ¦/\n");
    printf("   └------------------------------------------------------------------------------------┘ \n");
    
}

void affichageAvantPartie(sJoueur* psJoueur_joueurs, int int_nombre_joueurs, int int_curseur) {

    /* affichage du haut */
    affichageHaut();

    /* affichage de la liste des joueurs */
    printf("   ¦ │                                                                                  ¦ │\n");
    printf("   ¦ │                                 Liste des joueurs :                              ¦ │\n");
    printf("   ¦ │                                                                                  ¦ │\n");
    for(int i=0; i<int_nombre_joueurs; i++) {
        printf("   ¦ │                                 %d ", i+1);
        affichageChaineAutoCompletion(psJoueur_joueurs[i].pchar_pseudo, TAILLE_PSEUDO);
        printf("                                ¦ │\n");
    }
    printf("   ¦ │                                                                                  ¦ │\n");

    /* Affichage des propositions avec la position du curseur */
    switch (int_curseur)
    {
    case 1:
        printf("   ¦ │        [*] Ajouter un joueur     [ ] Supprimer un joueur     [ ] Commencer       ¦ │\n");
        break;
    
    case 2:
        printf("   ¦ │        [ ] Ajouter un joueur     [*] Supprimer un joueur     [ ] Commencer       ¦ │\n");
        break;

    case 3:
        printf("   ¦ │        [ ] Ajouter un joueur     [ ] Supprimer un joueur     [*] Commencer       ¦ │\n");
        break;

    default:
        printf("   ¦ │        [ ] Ajouter un joueur     [ ] Supprimer un joueur     [ ] Commencer       ¦ │\n");
        break;
    }
    printf("   ¦ │                                                                                  ¦ │\n");
    
    /* affichage du bas */
    affichageBas();
}

void affichageCarteVide(int int_decalage) {

    /* affichage de la chaine "vide" centré à partir du décalage */
    printf("\n");
    /* calcul de la position pour centrage */
    printf("\x1B[%dC", int_decalage-1 + (int) (12 - strlen("vide") - 1)/2);
    printf("\x1B[4mvide\x1B[m\n");
    printf("\n");

    /* affichage de la carte vide */
    printf("\x1B[%dC", int_decalage);
    printf("┌-------┐\n");
    printf("\x1B[%dC", int_decalage);
    printf("¦       ¦\n");
    printf("\x1B[%dC", int_decalage);
    printf("¦       ¦\n");
    printf("\x1B[%dC", int_decalage);
    printf("¦       ¦\n");
    printf("\x1B[%dC", int_decalage);
    printf("¦       ¦\n");
    printf("\x1B[%dC", int_decalage);
    printf("¦       ¦\n");
    printf("\x1B[%dC", int_decalage);
    printf("└-------┘\n");
}

void affichageCartes(sJoueur psJoueur_joueurs, int int_decalage) {
    
    char* pchar_mise; // Chaine de la mise d'un joueur
    char* pchar_jeton; // Chaine des jeuton d'un joueur

    /* Allocation */
    pchar_mise = malloc((TAILLE_MISE + 1) * sizeof(char));
    pchar_jeton = malloc((TAILLE_JETON + 1) * sizeof(char));

    /* Ecriture dans les chaines */
    sprintf(pchar_mise, "%d",psJoueur_joueurs.int_mise);
    sprintf(pchar_jeton, "%d",psJoueur_joueurs.int_jeton);

    /* Affichage du pseudo centré */
    printf("\n");
    printf("\x1B[%dC", int_decalage-1 + (int) (12 - strlen(psJoueur_joueurs.pchar_pseudo) - 1)/2);
    printf("\x1B[4m%s\x1B[m\n", psJoueur_joueurs.pchar_pseudo);

    printf("\x1B[%dC", int_decalage-1 + (int) (strlen("() ") -1 + strlen(pchar_jeton) -1 + strlen(pchar_mise) -1)/2); 
    printf("%s (%s)\n", pchar_mise, pchar_jeton);
    
    /* Affichage des cartes du joueur */
    for(int i=0; i<psJoueur_joueurs.int_nombre_cartes; i++) {
        
        /* decalage du cuseur d'affichage vers le haut */
        if(i != 0) {
            int_decalage += 2;
            printf("\x1B[4A");          
        }

        /* decalage du cuseur d'affichage vers la droite */
        printf("\x1B[%dC", int_decalage);


        printf("┌───────┐\n");
                
        /* decalage du cuseur d'affichage vers la droite */
        printf("\x1B[%dC", int_decalage); 
        

        switch (psJoueur_joueurs.psCarte_cartes[i].int_valeur)
        {
        case AS:
            printf("│A      │\n");
            break;

        case 10:
            printf("│10     │\n");
            break;
        
        case VALET:
            printf("│V      │\n");
            break;

        case DAME:
            printf("│Q      │\n");
            break;
        
        case ROI:
            printf("│K      │\n");
            break;
        
        default:
            printf("│%d      │\n", psJoueur_joueurs.psCarte_cartes[i].int_valeur);
        }

        /* decalage du cuseur d'affichage vers la droite */
        printf("\x1B[%dC", int_decalage);

        switch (psJoueur_joueurs.psCarte_cartes[i].eCouleur_couleur)
        {
            case piques:
                printf("│♠      │\n");
                break;

            case trefles:
                printf("│♣      │\n");
                break;

            case carreaux:
                printf("│♦      │\n");
                break;

            case coeurs:
                printf("│♥      │\n");
                break;
        }

        /* decalage du cuseur d'affichage vers la droite */
        printf("\x1B[%dC", int_decalage);

        printf("│       │\n");  

        /* decalage du cuseur d'affichage vers la droite */
        printf("\x1B[%dC", int_decalage);

        switch (psJoueur_joueurs.psCarte_cartes[i].eCouleur_couleur)
        {
            case piques:
                printf("│     ♠ │\n");
                break;

            case trefles:
                printf("│     ♣ │\n");
                break;

            case carreaux:
                printf("│     ♦ │\n");
                break;

            case coeurs:
                printf("│     ♥ │\n");
                break;
        }

        /* decalage du cuseur d'affichage vers la droite */
        printf("\x1B[%dC", int_decalage);

        switch (psJoueur_joueurs.psCarte_cartes[i].int_valeur)
        {
        case AS:
            printf("│      A│\n");
            break;

        case 10:
            printf("│     10│\n");
            break;
        
        case VALET:
            printf("│      V│\n");
            break;

        case DAME:
            printf("│      Q│\n");
            break;
        
        case ROI:
            printf("│      K│\n");
            break;
        
        default:
            printf("│      %d│\n", psJoueur_joueurs.psCarte_cartes[i].int_valeur);
        }

        /* decalage du cuseur d'affichage vers la droite */
        printf("\x1B[%dC", int_decalage);

        printf("└───────┘\n");
    }

    /* Libération de la mémoire */
    free(pchar_mise);
    free(pchar_jeton);
}

void affichageCartesBanque(sJoueur psJoueur_joueurs) {
    
    /* Calcul du décalage horizontale*/
    int int_decalage = 46 - (( psJoueur_joueurs.int_nombre_cartes * 9) + ( psJoueur_joueurs.int_nombre_cartes * 1 ))/2;

    /* Affichage du pseudo centré */
    printf("\n");
    printf("\x1B[%dC", 41 + (int) (12 - strlen(psJoueur_joueurs.pchar_pseudo) - 1)/2);
    printf("\x1B[4m%s\x1B[m\n", psJoueur_joueurs.pchar_pseudo);
    printf("\x1B[%dC", int_decalage);


    /* Affichage des cartes de la banque */
    for(int i=0; i<psJoueur_joueurs.int_nombre_cartes; i++) {
        if(i != 0) {
            printf(" ");
        }
        
        printf("┌───────┐");
    }

    printf("\n");
    /* decalage du cuseur d'affichage vers la droite */
    printf("\x1B[%dC", int_decalage);

    for(int i=0; i<psJoueur_joueurs.int_nombre_cartes; i++) {
        if(i != 0) {
            printf(" ");
        }
        
        switch (psJoueur_joueurs.psCarte_cartes[i].int_valeur)
        {
        case AS:
            printf("│A      │");
            break;

        case 10:
            printf("│10     │");
            break;
        
        case VALET:
            printf("│V      │");
            break;

        case DAME:
            printf("│Q      │");
            break;
        
        case ROI:
            printf("│K      │");
            break;
        
        default:
            printf("│%d      │", psJoueur_joueurs.psCarte_cartes[i].int_valeur);
        }

    }

    printf("\n");
    /* decalage du cuseur d'affichage vers la droite */
    printf("\x1B[%dC", int_decalage);

    for(int i=0; i<psJoueur_joueurs.int_nombre_cartes; i++) {
        if(i != 0) {
            printf(" ");
        }
        
        switch (psJoueur_joueurs.psCarte_cartes[i].eCouleur_couleur)
        {
            case piques:
                printf("│♠      │");
                break;

            case trefles:
                printf("│♣      │");
                break;

            case carreaux:
                printf("│♦      │");
                break;

            case coeurs:
                printf("│♥      │");
                break;
        }
    }

    printf("\n");
    /* decalage du cuseur d'affichage vers la droite */
    printf("\x1B[%dC", int_decalage);

    for(int i=0; i<psJoueur_joueurs.int_nombre_cartes; i++) {
        if(i != 0) {
            printf(" ");
        }
        
        printf("│       │");
    }

    printf("\n");
    /* decalage du cuseur d'affichage vers la droite */
    printf("\x1B[%dC", int_decalage);

    for(int i=0; i<psJoueur_joueurs.int_nombre_cartes; i++) {
        if(i != 0) {
            printf(" ");
        }
        
        switch (psJoueur_joueurs.psCarte_cartes[i].eCouleur_couleur)
        {
            case piques:
                printf("│     ♠ │");
                break;

            case trefles:
                printf("│     ♣ │");
                break;

            case carreaux:
                printf("│     ♦ │");
                break;

            case coeurs:
                printf("│     ♥ │");
                break;
        }
    }

    printf("\n");
    /* decalage du cuseur d'affichage vers la droite */
    printf("\x1B[%dC", int_decalage);

    for(int i=0; i<psJoueur_joueurs.int_nombre_cartes; i++) {
        if(i != 0) {
            printf(" ");
        }
        
        switch (psJoueur_joueurs.psCarte_cartes[i].int_valeur)
        {
        case AS:
            printf("│      A│");
            break;

        case 10:
            printf("│     10│");
            break;
        
        case VALET:
            printf("│      V│");
            break;

        case DAME:
            printf("│      Q│");
            break;
        
        case ROI:
            printf("│      K│");
            break;
        
        default:
            printf("│      %d│", psJoueur_joueurs.psCarte_cartes[i].int_valeur);
        }
    }

    printf("\n");
    /* decalage du cuseur d'affichage vers la droite */
    printf("\x1B[%dC", int_decalage);

        for(int i=0; i<psJoueur_joueurs.int_nombre_cartes; i++) {
        if(i != 0) {
            printf(" ");
        }
        
        printf("└───────┘");
    }

    printf("\n");

}


void affichageChoix(int int_choix, bool* pbool_option, char* pchar_pseudo) {
    
    printf("   ¦ │                                                                                  ¦ │\n");

    /* Affichage du speudo centré */
    if(int_choix != -1) {
        printf("   ¦ │                                                                                  ¦ │\n");
        printf("\x1B[A\x1B[%dC", 41 + (int) (12 - strlen(pchar_pseudo) - 1)/2);
        printf("\x1B[4m%s\x1B[m\n", pchar_pseudo);
    }

    /* Affichage des propositions avec la position du curseur */
    switch (int_choix)
    {
    case 1:
        if(pbool_option[DOUBLER] == true) {
            printf("   ¦ │                      [*] Tirer     [ ] Rester     [ ] Doubler                    ¦ │\n");
        } else {
            printf("   ¦ │                              [*] Tirer     [ ] Rester                            ¦ │\n");
        }
        break;
    
    case 2:
        if(pbool_option[DOUBLER] == true) {
            printf("   ¦ │                      [ ] Tirer     [*] Rester     [ ] Doubler                    ¦ │\n");
        } else {
            printf("   ¦ │                              [ ] Tirer     [*] Rester                            ¦ │\n");
        }
        break;

    case 3:
        printf("   ¦ │                      [ ] Tirer     [ ] Rester     [*] Doubler                    ¦ │\n");
        break;

    case -1:
        printf("   ¦ │                                                                                  ¦ │\n");
        printf("\x1B[A\x1B[%dC", 45  - (int) (strlen(pchar_pseudo) -1 + strlen("à brulé(e)") -1)/2);
        printf("\x1B[4m%s\x1B[m a brule(e)\n", pchar_pseudo);
        break;

    default:
        if(pbool_option[DOUBLER] == true) {
            printf("   ¦ │                      [ ] Tirer     [ ] Rester     [ ] Doubler                    ¦ │\n");
        } else {
            printf("   ¦ │                              [ ] Tirer     [ ] Rester                            ¦ │\n");
        }
        break;
    }

}

void affichageResultat(sJoueur* psJoueur_joueurs, int int_nombre_joueurs) {
    printf("   ¦ │                                                                                  ¦ │\n");
    printf("   ¦ │                                                                                  ¦ │\n");
    printf("   ¦ │                                                                                  ¦ │\n");


    int int_valeur_banque; // Valeur de la main de la banque
    /* Calcul de la valeur de la main */
    int_valeur_banque = valeurMain(psJoueur_joueurs[int_nombre_joueurs-1]);

    /*Affichage si il y a 4 joueurs */
    if(int_nombre_joueurs-1 >= 4) {
        
        /* Decalage du curseur dans le terminal */
        printf("\x1B[2A\x1B[71C");
        
        /* Affichage suivant la main du joueur contre la main de la banque */
        if( (valeurMain(psJoueur_joueurs[3]) <= 21 && valeurMain(psJoueur_joueurs[3]) > int_valeur_banque) 
            || (valeurMain(psJoueur_joueurs[3]) <= 21 && int_valeur_banque > 21) ) {
            
            /* Le joueur a gagné donc affichage du gain */
            psJoueur_joueurs[3].int_jeton += psJoueur_joueurs[3].int_mise * 2;
            printf("   Gain :\n");
            printf("\x1B[71C");
            printf("    %d\n", psJoueur_joueurs[3].int_mise * 2);
        } else {
            if(valeurMain(psJoueur_joueurs[3]) <= 21 && valeurMain(psJoueur_joueurs[3]) == int_valeur_banque) {
            
            /* Il y a égalité entre le joueur et la banque */
            psJoueur_joueurs[3].int_jeton += psJoueur_joueurs[3].int_mise;
            printf(" Egalite :\n");
            printf("\x1B[71C");
            printf("    %d\n", psJoueur_joueurs[3].int_mise);
            } else {
                /* Le joueur a perdu */
                printf("    Perdu\n\n");
            }
        }
    }

    /*Affichage si il y a 2 joueurs */
    if(int_nombre_joueurs-1 >= 2) {
        
        /* Decalage du curseur dans le terminal */
        printf("\x1B[2A\x1B[56C");
        
        /* Affichage suivant la main du joueur contre la main de la banque */
        if( (valeurMain(psJoueur_joueurs[1]) <= 21 && valeurMain(psJoueur_joueurs[1]) > int_valeur_banque) 
            || (valeurMain(psJoueur_joueurs[1]) <= 21 && int_valeur_banque > 21) ) {

            /* Le joueur a gagné donc affichage du gain */
            psJoueur_joueurs[1].int_jeton += psJoueur_joueurs[1].int_mise * 2;
            printf("   Gain :\n");
            printf("\x1B[56C");
            printf("    %d\n", psJoueur_joueurs[1].int_mise * 2);
        } else {
            if(valeurMain(psJoueur_joueurs[1]) <= 21 && valeurMain(psJoueur_joueurs[1]) == int_valeur_banque) {
            
            /* Il y a égalité entre le joueur et la banque */
            psJoueur_joueurs[1].int_jeton += psJoueur_joueurs[1].int_mise;
            printf(" Egalite :\n");
            printf("\x1B[71C");
            printf("    %d\n", psJoueur_joueurs[1].int_mise);
            } else {
                /* Le joueur a perdu */
                printf("    Perdu\n\n");
            }
        }
    } 

    /*Affichage si il y a 1 joueur */
    if(int_nombre_joueurs-1 >= 1) {
        
        /* Decalage du curseur dans le terminal */
        printf("\x1B[2A\x1B[41C");
        
        /* Affichage suivant la main du joueur contre la main de la banque */
        if( (valeurMain(psJoueur_joueurs[0]) <= 21 && valeurMain(psJoueur_joueurs[0]) > int_valeur_banque)
            || (valeurMain(psJoueur_joueurs[0]) <= 21 && int_valeur_banque > 21) ) {

            /* Le joueur a gagné donc affichage du gain */
            psJoueur_joueurs[0].int_jeton += psJoueur_joueurs[0].int_mise * 2;
            printf("   Gain :\n");
            printf("\x1B[41C");
            printf("    %d\n", psJoueur_joueurs[0].int_mise * 2);
        } else {
            if(valeurMain(psJoueur_joueurs[0]) <= 21 && valeurMain(psJoueur_joueurs[0]) == int_valeur_banque) {
            
            /* Il y a égalité entre le joueur et la banque */
            psJoueur_joueurs[0].int_jeton += psJoueur_joueurs[0].int_mise;
            printf(" Egalite :\n");
            printf("\x1B[71C");
            printf("    %d\n", psJoueur_joueurs[0].int_mise);
            } else {
                /* Le joueur a perdu */
                printf("    Perdu\n\n");
            }
        }
    }

    /*Affichage si il y a 3 joueurs */
    if(int_nombre_joueurs-1 >= 3) {
        
        /* Decalage du curseur dans le terminal */
        printf("\x1B[2A\x1B[26C");
        
        /* Affichage suivant la main du joueur contre la main de la banque */
        if( (valeurMain(psJoueur_joueurs[2]) <= 21 && valeurMain(psJoueur_joueurs[2]) > int_valeur_banque)
            || (valeurMain(psJoueur_joueurs[2]) <= 21 && int_valeur_banque > 21) ) {

            /* Le joueur a gagné donc affichage du gain */
            psJoueur_joueurs[2].int_jeton += psJoueur_joueurs[2].int_mise * 2;
            printf("   Gain :\n");
            printf("\x1B[26C");
            printf("    %d\n", psJoueur_joueurs[2].int_mise * 2);
        } else {
            if(valeurMain(psJoueur_joueurs[2]) <= 21 && valeurMain(psJoueur_joueurs[2]) == int_valeur_banque) {
            
            /* Il y a égalité entre le joueur et la banque */
            psJoueur_joueurs[2].int_jeton += psJoueur_joueurs[2].int_mise;
            printf(" Egalite :\n");
            printf("\x1B[71C");
            printf("    %d\n", psJoueur_joueurs[2].int_mise);
            } else {
                /* Le joueur a perdu */
                printf("    Perdu\n\n");
            }
        }
    }

    /*Affichage si il y a 5 joueurs */
    if(int_nombre_joueurs-1 == 5) {
        
        /* Decalage du curseur dans le terminal */
        printf("\x1B[2A\x1B[11C");
        
        /* Affichage suivant la main du joueur contre la main de la banque */
        if( (valeurMain(psJoueur_joueurs[4]) <= 21 && valeurMain(psJoueur_joueurs[4]) > int_valeur_banque)
            || (valeurMain(psJoueur_joueurs[4]) <= 21 && int_valeur_banque > 21) ) {

            /* Le joueur a gagné donc affichage du gain */
            psJoueur_joueurs[4].int_jeton += psJoueur_joueurs[4].int_mise * 2;
            printf("   Gain :\n");
            printf("\x1B[11C");
            printf("    %d\n", psJoueur_joueurs[4].int_mise * 2);
        } else {
            if(valeurMain(psJoueur_joueurs[4]) <= 21 && valeurMain(psJoueur_joueurs[4]) == int_valeur_banque) {
            
            /* Il y a égalité entre le joueur et la banque */
            psJoueur_joueurs[4].int_jeton += psJoueur_joueurs[4].int_mise;
            printf(" Egalite :\n");
            printf("\x1B[71C");
            printf("    %d\n", psJoueur_joueurs[4].int_mise);
            } else {
                /* Le joueur a perdu */
                printf("    Perdu\n\n");
            }
        }
    }

    printf("   ¦ │                                                                                  ¦ │\n");

}


void affichagePartie(sJoueur* psJoueur_joueurs, int int_nombre_joueurs, int int_numero_joueur, int int_choix, bool* pbool_options, bool bool_resultat) {
    
    int int_max_cartes; // Nombre max de carte que possede un joueur

    /* Calcul du max de carte */
    int_max_cartes = maxCarteJoueurs(psJoueur_joueurs, int_nombre_joueurs-1);


    /* Affichage de l'en-tête */
    affichageHaut();

    /* Affichage des cotés */
    affichageCotes(int_max_cartes); 

    /* Affichage des cartes de la banque */
    affichageCartesBanque(psJoueur_joueurs[int_nombre_joueurs - 1]);

    int int_decalage_verticale; // Decalage du curseur dans le termanil */

    /* Inittialisation */
    int_decalage_verticale = 0;
    int a = 10;

    /*Affichage si il y a 4 joueurs */
    if(int_nombre_joueurs-1 >= 4) {
        affichageCartes(psJoueur_joueurs[3], 71);
        int_decalage_verticale = a + ( (psJoueur_joueurs[3].int_nombre_cartes-1) * 3);   
    } else {
        int_decalage_verticale = a;
        affichageCarteVide(71);
    }

    printf("\x1B[%dA", int_decalage_verticale);

    /*Affichage si il y a 2 joueurs */
    if(int_nombre_joueurs-1 >= 2) {
        affichageCartes(psJoueur_joueurs[1], 56);
        int_decalage_verticale = a + ((psJoueur_joueurs[1].int_nombre_cartes-1) * 3);
    } else {
        int_decalage_verticale = a;
        affichageCarteVide(56);
    }   

    printf("\x1B[%dA", int_decalage_verticale);
    
    /*Affichage si il y a 1 joueurs */
    if(int_nombre_joueurs-1 >= 1) {
        affichageCartes(psJoueur_joueurs[0], 41);

        int_decalage_verticale = a + ((psJoueur_joueurs[0].int_nombre_cartes-1) * 3);
    } else {
        int_decalage_verticale = a;
        affichageCarteVide(41);
    }

    printf("\x1B[%dA", int_decalage_verticale);
    
    /*Affichage si il y a 3 joueurs */
    if(int_nombre_joueurs-1 >= 3) {
        affichageCartes(psJoueur_joueurs[2], 26);
        int_decalage_verticale = a + ((psJoueur_joueurs[2].int_nombre_cartes-1) * 3);
    } else {
        int_decalage_verticale = a;
        affichageCarteVide(26);
    }
    
    printf("\x1B[%dA", int_decalage_verticale);

    /*Affichage si il y a 5 joueurs */
    if(int_nombre_joueurs-1 == 5) {
        affichageCartes(psJoueur_joueurs[4], 11);
        int_decalage_verticale = a + ((psJoueur_joueurs[4].int_nombre_cartes-1) * 3);
    } else {
        int_decalage_verticale = a;
        affichageCarteVide(11);
    }

    printf("\x1B[%dA", int_decalage_verticale);

    /* Decalage du curseur */
    printf("\x1B[%dE", a + (3 * (int_max_cartes-1)));

    /* Si il y a des choix possibles, alors ils sont affichés */
    if(int_choix != -2) {
        affichageChoix(int_choix, pbool_options, psJoueur_joueurs[int_numero_joueur].pchar_pseudo);
    }

    /* Si la partie est finie, le resultat est alors affiché */
    if(bool_resultat == true) {
        affichageResultat(psJoueur_joueurs,int_nombre_joueurs);
    }

    /* Affichage de la partie basse */
    affichageBas();
}


void affichageMiser(int int_decalage, char* pchar_pseudo, int int_mise) {
    
    char* pchar_mise; // Chaine de la mise d'un joueur

    /* Allocation */
    pchar_mise = malloc((TAILLE_MISE + 1) * sizeof(char));

    /* Ecriture dans la chaine */
    sprintf(pchar_mise, "%d", int_mise);

    /* Affichage du pseudo du joueur centré */
    printf("\n");
    printf("\x1B[%dC", int_decalage-1 + (int) (12 - strlen(pchar_pseudo) - 1)/2);
    printf("\x1B[4m%s\x1B[m\n", pchar_pseudo);
    printf("\n");

    /* Affichage d'un emplacement avec le montant de mise au milieu */
    printf("\x1B[%dC", int_decalage);
    printf("┌───────┐\n");
    printf("\x1B[%dC", int_decalage);
    printf("│       │\n");
    printf("\x1B[%dC", int_decalage);
    printf("│       │\n");
    printf("\x1B[%dC", int_decalage);

    printf("│  ");
    if(int_mise != 0) {
        if(int_mise > 99) {
            printf("%s", pchar_mise);
        } else {
            if(int_mise > 9) {
                printf(" %s", pchar_mise);
            } else {
                printf(" %s ", pchar_mise);
            }
        }
    } else {
        printf("   ");
    }
    printf("  │\n");

    printf("\x1B[%dC", int_decalage);
    printf("│       │\n");
    printf("\x1B[%dC", int_decalage);
    printf("│       │\n");
    printf("\x1B[%dC", int_decalage);
    printf("└───────┘\n");

    /* Libération de la mémoire */
    free(pchar_mise);
}