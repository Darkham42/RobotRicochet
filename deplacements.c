#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <time.h>

#include "func.h"
//ici sont defini les différents déplacements (droite/gauche, haut/bas)

int verification_victoire(map_t *carte) {
    int i;
    for(i = 0; i < NB_ROBOTS; i++) {
	// verification d'arrivée sur l'objectif
	if( (carte->robots[i].pos.x == carte->objectif.x) && (carte->robots[i].pos.y == carte->objectif.y) ) {
	    return 1;
	}
    }
    // aucun robot sur l'objectif
    return 0;
}

void deplacement_robot(map_t *carte, int robot, int dir_x, int dir_y) {
    int r_x, r_y, i;
    char c, m;
    
    // un seul axe de déplacement
    if( dir_x != 0 && dir_y != 0 ) {
	return;
    }
    
    do {
	// variables pour simplifier la lecture du code
	r_x = carte->robots[robot].pos.x + dir_x;
	r_y = carte->robots[robot].pos.y + dir_y;
	
	// sortie du plateau ?
	if( (r_x <= 0) || (r_y <= 0) || (r_x > (SIZE_X-1)) || (r_y > (SIZE_Y-1)) ) {
	    // le robot reste sur la dernière position valide
	    return;
	}
	
	// la case à franchir		
	m = carte->plateau[r_y][r_x];
	
	// la case d'arrivée
	c = carte->plateau[r_y + dir_y][r_x + dir_x];
	
	if( m == '.' && c == ' ' ) {
	    // verification de la position des autres robots
	    for(i = 0; i < NB_ROBOTS; i++) {
		if( i != robot) {
		    // un robot sur la case d'arrivée ?
		    if( ( (r_y+dir_y) == carte->robots[i].pos.y) && ( (r_x+dir_x) == carte->robots[i].pos.x) ) {
			// oui, donc deplacement impossible
			return;
		    }
		}
	    }
	    
	    // position valide, mise à jour de la position du robot
	    carte->robots[robot].pos.x += 2*dir_x;
	    carte->robots[robot].pos.y += 2*dir_y;
	} else {
	    // position impossible, le robot s'arrête
	    return;
	}
    } while( 1 );
}

int choice_robot(robot) {
    int input_valid = 0;
    refresh();
    
    do {
	input_valid = 0;
	switch( getch() ) {
	    
	    case 'b' :
	    case 'B' :
		robot = BLEU;
		input_valid = 1;
		break;
		
	    case 'r' :
	    case 'R' :
		robot = ROUGE;
		input_valid = 1;
		break;
		
	    case 'v' :
	    case 'V' :
		robot = VERT;
		input_valid = 1;
		break;
		
	    case 'g' :
	    case 'G' :
		robot = GRIS;
		input_valid = 1;
		break;
		
	    case 'q':
	    case 'Q':
		mvprintw(34, 0, "Vous quittez le jeu !");
		sortie_propre();
		break;
	}
    } while( !input_valid );// on ne quitte la boucle que si le caractère est voulu
    return robot;
}

void choice_move_robot (map_t *carte, int robot) {
    int dir_x, dir_y;
    int input_valid = 0;
    
    do {
	input_valid = 0;
	switch( getch() ) {
	    
	    case '6':
	    case KEY_RIGHT :
	    case 'd' :
		dir_x = 1; dir_y = 0;
		input_valid = 1;
		break; // droite
		
	    case '4':
	    case KEY_LEFT :
	    case 'q' :
		dir_x = -1; dir_y = 0;
		input_valid = 1;
		break; // gauche
		
	    case '8':
	    case KEY_UP :
	    case 'z' :
		dir_x = 0; dir_y = -1;
		input_valid = 1;
		break; // haut
		
	    case '2':
	    case KEY_DOWN :
	    case 's' :
		dir_x = 0; dir_y = 1;
		input_valid = 1;
		break; // bas
	}
    } while( !input_valid );
    deplacement_robot(carte, robot, dir_x, dir_y);
}