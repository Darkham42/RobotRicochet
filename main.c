#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <time.h>

#include "func.h"

int main (void)
{
    int menu;
    
    /* initialisation des objectifs en random */
    srand(time(NULL));
    
    /* ncurses init */
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    curs_set(0); // hide the cursor
    start_color();
    
    /* color definitions */
    init_pair(1, COLOR_WHITE, COLOR_BLACK); // normal
    init_pair(2, COLOR_RED, COLOR_BLACK); // rouge
    init_pair(3, COLOR_YELLOW, COLOR_BLACK); // rouge
    
    do {
	clear();
	attron(COLOR_PAIR(2));
	printw("*******************************************\n");
	printw("*                                         *\n");
	printw("*        Welcome to Ricochet Robot        *\n");
	printw("*                                         *\n");
	printw("*******************************************\n\n");
	attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(3));
	printw("\n------------------ Menu ------------------\n\n");
	printw("   (1) --------- Mode Solo -------- (1)\n");
	printw("   (2) ---- Mode Multi-joueurs ---- (2)\n");
	printw("   (3) -------- High Score -------- (3)\n");
	printw("   (4) ------- Règles du jeu ------ (4)\n");
	printw("   (5) ---------- Quitter --------- (5)\n");
	attroff(COLOR_PAIR(3));
	refresh();

	printw("\n\n\n\nProgramme réalisé par LEBERT Jasmine et PICARD Thomas.");
	refresh();
	
	do
	{
	    char userValue = getchar();
	    /* Conversion de la valeur ASCII renvoyée en valeur entière*/
	    menu = atoi(&userValue);
	}
	while (menu < 1 || menu > 5);
	
	// On agit en fonction du choix de l'utilisateur.
	switch(menu)
	{
	    case 1 :
		mode_solo();// Choix 1 on lance le mode solo
		break;
		
	    case 2 :
		mode_multi();// Choix 2 on lance le mode multi
		break;
		
	    case 3 :
		high_score("high_score.txt");
		break;

		case 4 :
		regles();
		break;
		
	    case 5 :
	    default :
		printf("Au revoir !\n");
		sortie_propre();// Autre choix : on quitte (autre choix = 3 en raison du do while)
	}
    } while( 1 );
    
    return 0;
}

void sortie_propre() {
    // attente d'une touche
    getch();
    endwin();
    exit(1);
}

int regles() {

	attron(COLOR_PAIR(2));
	mvprintw(19,80,"Robot Ricochet");
	attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(3));
	mvprintw(21,25,"Le but du jeu solo est de positioner un robot sur l'objectif 'X' de la carte en le moins de coup possible à l'aide des 4 robots");
	mvprintw(22,25,"'R', 'V', 'B' et 'G' à sa disposition.");
	mvprintw(24,25,"Dans le mode solo il y a deux cartes prédéfinies, une aléatoire et une personnalisable (CF Documentation)");
	mvprintw(26,25,"Le mode multi se déroule de manière à ce que les 4 joueurs rentre leurs pseudo puis choisissent la carte.");
	mvprintw(27,25,"Une fois la carte choisi un objectif est généré de façon aléatoire et alors chacun des joueurs doit définir un nombre de");
	mvprintw(28,25,"coup pour atteindre l'objectif à l'aide des 4 robots à sa disposition.");
	mvprintw(29,25,"Le premier joueur est selectionné alétoirement et dispose du nombre de coup défini précedément.");
	mvprintw(30,25,"Le jeu se fait en 3 manches.");
	mvprintw(35,10,"Appuyez sur n'importe quelle touche pour retourner au menu.");
	attroff(COLOR_PAIR(3));
	getch();
	refresh();

   return 0;
}