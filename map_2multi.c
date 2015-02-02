#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

void map_2multi(map_t *tmp) {
    int i;
    
    // on initialise tout à 0
    memset(tmp, 0, sizeof(map_t));
    /* initialisation objectif */
    do {
	tmp->objectif.x = 2 * Random(1, 16) - 1;
	tmp->objectif.y = 2 * Random(1, 16) - 1;
    } while( positions_invalides(tmp) );
    
    /* initialisation robots */
    tmp->robots[BLEU].pos.x = 7;
    tmp->robots[BLEU].pos.y = 15;	
    tmp->robots[BLEU].couleur = 'B';
    
    tmp->robots[ROUGE].pos.x = 15;
    tmp->robots[ROUGE].pos.y = 27;	
    tmp->robots[ROUGE].couleur = 'R';
    
    tmp->robots[VERT].pos.x = 15;
    tmp->robots[VERT].pos.y = 25;	
    tmp->robots[VERT].couleur = 'V';
    
    tmp->robots[GRIS].pos.x = 19;
    tmp->robots[GRIS].pos.y = 5;	
    tmp->robots[GRIS].couleur = 'G';
    
    /* initialisation plateau */
    i = 0;
    strncpy(tmp->plateau[i++],"+-------------------------------+", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . | . . . . . . . | . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.............+=................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . | . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|=..............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . | . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|....=+=..........+=............|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . | . . . . . | . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|..............................=|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . | . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|..............=+...............|", SIZE_X);
    strncpy(tmp->plateau[i++],"| | . . . . . . . . . . . . | . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.+=...................=+..=+...|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . | . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.............+---+.............|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . |   | . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|..........=+.|   |......=+....=|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . | |   | . . . | . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.............+---+.............|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . | . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.....+=....+=..................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . | . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|=................+=.......=+...|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . | . . . | . . . . | . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.........+=....................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . | . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|......................=+.......|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . | . . . . | . . . . . | . |", SIZE_X);
    strncpy(tmp->plateau[i++],"+-------------------------------+", SIZE_X);
}