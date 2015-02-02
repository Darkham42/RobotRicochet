#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "func.h"

// on utilise map_t et pas map_t* pour obtenir une copie de la carte initiale
int jeu_manche(map_t carte, Player *joueur, int nbr_manche) {
    int nb_coups_restant = joueur->score_d;
    int gagne;

    do{
	affichage_plateau(&carte);
	
	attron(COLOR_PAIR(2));
	mvprintw(10,100,"Manche n°%d",nbr_manche);
	attroff(COLOR_PAIR(2));
	refresh();
	
	//choix du robots :
	mvprintw(14,90,"%s veuillez choisir votre robot: R, B, V ou G ",joueur->pseudo);
	refresh();
	
	int robot = choice_robot();
	
	//choix du déplacement :
	affichage_selection_robot(&carte, robot);
	
	mvprintw(16,115,"(8) vers le haut (8)");
	mvprintw(18,115,"(2) vers le bas  (2)");
	mvprintw(17,98,"(4) vers la gauche (4)");
	mvprintw(17,130,"(6) vers la droite (6)");
	mvprintw(20,90,"Nombres de coups estimé :%d\n", joueur->score_d);
	mvprintw(20,90,"Nombres de coups restant : %d\n", nb_coups_restant);
	mvprintw(21,90,"Nombres d'objectifs acquis : %d\n", joueur->score_o);
	refresh();
	
	choice_move_robot (&carte, robot);
	
	nb_coups_restant--;
	gagne = verification_victoire(&carte);
    }while( !gagne && nb_coups_restant > 0);
    
    if (gagne) {
	joueur->score_o++;
    }

    // pour tester le tri
    //joueur->score_o += Random(0,3);
    
    return nb_coups_restant;
}

//void caron ne peut pas prévoir tous les cas possible d'usage de la fonction qsort
int compare_score_joueur(const void *p1, const void *p2) {
    return ((Player *)p1)->score_o < ((Player *)p2)->score_o;
}

int mode_multi ()
{
    /* variable pour la map : un pointeur vers la structure */
    map_t carte_initiale;
    Player joueurs[4];

    char userValueMapS;
    
    int n,map,j_deb = 0,nbr_manche = 1;
    int points;

    
    //menu----------------------------------------------------------------------
    clear();
    attron(COLOR_PAIR(3));
    printw("---------------- Mode Multi ----------------\n\n");
    refresh();
    
    for(n = 0; n < 4; n++) {
	printw("\n\nVeuillez saisir le pseudo du joueur %d :\n", n);
	refresh();
	joueurs[n].num_player = n;
	curs_set(1);
	echo();
	refresh();
	scanw("%s",joueurs[n].pseudo);
	curs_set(0);
	noecho();
	joueurs[n].score_d = 0;
	joueurs[n].score_o = 0;
	
	printw("\nJoueur n°%d\nPseudo : %s\nScore déplacement : %d\nScore Objectif : %d\n",joueurs[n].num_player,joueurs[n].pseudo,joueurs[n].score_d,joueurs[n].score_o);
	refresh();
    }
    
    attron(COLOR_PAIR(1));
    mvprintw(17,88,"--------- Choix de la map -------");
    mvprintw(19,88,"(1) ---------- Map 1 -------- (1)");
    mvprintw(20,88,"(2) ---------- Map 2 -------- (2)");
    mvprintw(22,88,"Quelle map voulez-vous charger ?\n");
    refresh();
    
    do
    {
	userValueMapS = getchar();
	map = atoi(&userValueMapS);
    }
    while (map < 1 || map > 2);

    // boucle des manches
    do{
	switch(map)
	{
	    case 1 :
		map_1multi(&carte_initiale);
		break;
		
	    case 2 :
		map_2multi(&carte_initiale);
		break;
		
	    default :
		printf("Au revoir !\n");
		sortie_propre(); // Autre choix : on quitte.
	}
	
	clear();
	affichage_plateau(&carte_initiale);
	
	for(n = 0; n < 4; n++) {
	    do {
		mvprintw(17,85,"%s en combien de coups pensez vous pouvoir prendre l'objectif ?           \n",joueurs[n].pseudo);
		refresh();
		curs_set(1);
		echo();
		refresh();
		mvscanw(18,85,"%d",&(joueurs[n].score_d));
		curs_set(0);
		noecho();
	    } while (joueurs[n].score_d <= 0 || joueurs[n].score_d > 50);
	}

	//jeu-----------------------------------------------------------------------

	/* On choisi qui commence via un random */
	mvprintw(18,85,"Nous allons laisser le destin choisir qui va commencer.");
	refresh();

	j_deb = Random(1, 4);
	mvprintw(17,85,"C'est à %s de commencer.\n",joueurs[j_deb%4].pseudo);
	mvprintw(18,85,"veuillez appuyer sur n'importe quelle touche pour commencer.");
	refresh();
	getch();
	
	/* Que la partie commence */
	n = 0;
	do {
	    points = jeu_manche(carte_initiale, &joueurs[(j_deb+n)%4], nbr_manche);
	    n++;
	} while( (points == 0) && (n < 4) );
	
	clear();
	mvprintw(17,85,"Récapitualtif de la manche n°%d",nbr_manche);
	
	// tri des joueurs en fonction de leur score
	qsort(joueurs, 4, sizeof(Player), compare_score_joueur);

	for(n = 0; n < 4; n++) {
	    mvprintw(18+n,85,"%s : %d objectifs attrapés.",joueurs[n].pseudo,joueurs[n].score_o);
	}
	refresh();
	nbr_manche++;

	mvprintw(22,85,"veuillez appuyer sur n'importe quelle touche pour commencer.");
	refresh();
	getch();
    } while (nbr_manche < 4);
    
    mvprintw(23,85,"Fin des 3 manches.");
    refresh();
    getch();
    
    return 0;
}