#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

int Random (int _iMin, int _iMax) 
{ 
    return (_iMin + (rand () % (_iMax-_iMin+1))); 
}

void obstacles_random(map_t *map, int n_obstacles)
{
    int n;
    for(n = 0 ; n < n_obstacles ; ++n) {
	
	int x, y;
	x = 2 * Random(2, 15);
	y = 2 * Random(2, 15);
	
	switch( Random(0, 6) ) {
	    case 0:
		map->plateau[y][x] = '+';
		map->plateau[y][x-1] = '=';
		map->plateau[y][x+1] = '=';
		map->plateau[y-1][x] = '|';
		map->plateau[y+1][x] = '|';
		break;
		
	    case 1:
		map->plateau[y][x] = '+';
		map->plateau[y][x-1] = '=';
		map->plateau[y+1][x] = '|';
		break;
		
	    case 2:
		map->plateau[y][x] = '+';
		map->plateau[y][x-1] = '=';
		map->plateau[y-1][x] = '|';
		break;
		
	    case 3:
		map->plateau[y][x] = '+';
		map->plateau[y][x+1] = '=';
		map->plateau[y+1][x] = '|';
		break;
		
	    case 4:
		map->plateau[y][x] = '+';
		map->plateau[y][x+1] = '=';
		map->plateau[y-1][x] = '|';
		break;
		
	    case 5:
		map->plateau[y][x] = '|';
		break;
		
	    case 6:
		map->plateau[y][x] = '=';
		break;
	}
    }
}

// retourne 1 si une position est invalide
int positions_invalides(map_t *map) {
    int i, j;
    
    // test par rapport au carre central
    if( ((map->objectif.x == 8) && (map->objectif.y == 8)) ||
	((map->objectif.x == 8) && (map->objectif.y == 9)) ||
	((map->objectif.x == 9) && (map->objectif.y == 8)) ||
	((map->objectif.x == 9) && (map->objectif.y == 9)) )
    {
	return 1;
    }
    
    for(i = 0; i < NB_ROBOTS; i++) {
	// verification par rapport à l'objectif
	if( (map->robots[i].pos.x != 0) && (map->objectif.x == map->robots[i].pos.x) ) { return 1; }
	if( (map->robots[i].pos.y != 0) && (map->objectif.y == map->robots[i].pos.y) ) { return 1; }
	
	// verification par rapport aux autres robots
	for(j = 0; j < i; j++) {
	    if( (map->robots[i].pos.x != 0) && (map->robots[j].pos.x == map->robots[i].pos.x) ) { return 1; }
	    if( (map->robots[i].pos.y != 0) && (map->robots[j].pos.y == map->robots[i].pos.y) ) { return 1; }
	}
	
	// test par rapport au carre central
	if( ((map->robots[i].pos.x == 8) && (map->robots[i].pos.y == 8)) ||
	    ((map->robots[i].pos.x == 8) && (map->robots[i].pos.y == 9)) ||
	    ((map->robots[i].pos.x == 9) && (map->robots[i].pos.y == 8)) ||
	    ((map->robots[i].pos.x == 9) && (map->robots[i].pos.y == 9)) )
	{
	    return 1;
	}
    }
    return 0;
}

void map_random(map_t *tmp) {
    int i;
    
    // on initialise tout à 0
    memset(tmp, 0, sizeof(map_t));
    
    /* initialisation objectif */
    do {
	tmp->objectif.x = 2 * Random(1, 16) - 1;
	tmp->objectif.y = 2 * Random(1, 16) - 1;
    } while( positions_invalides(tmp) );
    
    /* initialisation robots */
    do {
	tmp->robots[BLEU].pos.x = 2 * Random(1, 16) - 1;
	tmp->robots[BLEU].pos.y = 2 * Random(1, 16) - 1;
	tmp->robots[BLEU].couleur = 'B';
    } while( positions_invalides(tmp) );
    
    do {
	tmp->robots[ROUGE].pos.x = 2 * Random(1, 16) - 1;
	tmp->robots[ROUGE].pos.y = 2 * Random(1, 16) - 1;
	tmp->robots[ROUGE].couleur = 'R';
    } while( positions_invalides(tmp) );
    
    do {
	tmp->robots[VERT].pos.x = 2 * Random(1, 16) - 1;
	tmp->robots[VERT].pos.y = 2 * Random(1, 16) - 1;
	tmp->robots[VERT].couleur = 'V';
    } while( positions_invalides(tmp) );
    
    do {
	tmp->robots[GRIS].pos.x = 2 * Random(1, 16) - 1;
	tmp->robots[GRIS].pos.y = 2 * Random(1, 16) - 1;
	tmp->robots[GRIS].couleur = 'G';
    } while( positions_invalides(tmp) );
    
    /* initialisation plateau */
    i = 0;
    strncpy(tmp->plateau[i++],"+-------------------------------+", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.............+---+.............|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . |   | . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.............|   |.............|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . |   | . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.............+---+.............|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"+-------------------------------+", SIZE_X);
    
    // ajout des obstacles
    obstacles_random(tmp, 15);
}