#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "func.h"

int mode_solo ()
{
    char pseudo[256];
    
    /* variable pour la map : un pointeur vers la structure */
    map_t carte;
    
    char userValueMapS;
    
    int gagne,map,cpt = 0;
    
    //menu----------------------------------------------------------------------
    
    clear();
    attron(COLOR_PAIR(3));
    printw("---------------- Mode Solo ----------------\n\n");
    attron(COLOR_PAIR(1));
    printw("   (1) ---------- Map 1 -------- (1)\n");
    printw("   (2) ---------- Map 2 -------- (2)\n");
    printw("   (3) ------ Map aléatoire ---- (3)\n");
    printw("   (4) ---- Map personalisée --- (4)\n");
    printw("\nQuelle map voulez-vous charger ?\n");
    refresh();
    
    do
    {
	userValueMapS = getchar();
	map = atoi(&userValueMapS);
    }
    while (map < 1 || map > 4);
    
    switch(map)
    {
	case 1 :
	    map_1(&carte);
	    break;
	    
	case 2 :
	    map_2(&carte);
	    break;
	    
	case 3 :
	    map_random(&carte);
	    break;
	    
	case 4 :
	    map_perso(&carte, "map_perso.txt");
	    break;
	    
	default :
	    printf("Au revoir !\n");
	    sortie_propre(); // Autre choix : on quitte.
    }
    
    
    //affichage_plateau(plt,rbi,rbj,rri,rrj,rvi,rvj,rgi,rgj,x,y);
    clear();
    affichage_plateau(&carte);
    
    //jeux-------------------------------------------------------------------------------------------------------------------------------
    
    do
    {
	//choix du robots :
	int robot;
	mvprintw(14,90,"Veuillez choisir votre robot: R, B, V ou G ");
	refresh();
	
	robot = choice_robot();
	
	//choix du déplacement :
	affichage_selection_robot(&carte, robot);
	
	mvprintw(16,115,"(8) vers le haut (8)");
	mvprintw(18,115,"(2) vers le bas  (2)");
	mvprintw(17,98,"(4) vers la gauche (4)");
	mvprintw(17,130,"(6) vers la droite (6)");
	mvprintw(20,90,"Score courant : %d\n", cpt);
	refresh();
	
	choice_move_robot (&carte, robot);
	
	// compteur du nombre de coups joués
	cpt++;
	gagne = verification_victoire(&carte);
	
	affichage_plateau(&carte);
    } while( !gagne );
    
    printw("Bravo vous avez gagné !\n");
    printw("Score final : %d\n",cpt);
    refresh();
    
    printw("Veuillez saisir votre pseudo :\n");
    curs_set(1);
    echo();    
    refresh();
    scanw("%s", pseudo);
    curs_set(0);
    noecho();
    refresh();

    save_score(pseudo, cpt);

    // retour au menu principal
    return 0;
}