#include "saisie.h"

int lireTouche(void) {

    char c1; // Caractère
    
    /* Lecture d'un caractère */
    c1 = getche();

    /* Test si le cartère est une flèche directionnelle */
    if(c1 == 27) {
        
        c1 = getche();
        
        if(c1 == 91) {
        
            c1 = getche();
            
            /* Replacage du curseur au debut de la ligne */
            printf("\r     \r");

            /* Renvoie la valeur associé à la flèche */
            switch (c1)
            {
            case 65:
                return(HAUT);
            
            case 66:
                return(BAS);
            
            case 67:
                return(DROITE);
            
            case 68:
                return(GAUCHE);  

            default:
                return (c1);
            }
        } 
    }
    
    /* Pour la touche entrer, il remonter d'un ligne */
    if(c1 == 10) {
        printf("\033[A");
    }
    printf("\r     \r");
    return(c1);
}