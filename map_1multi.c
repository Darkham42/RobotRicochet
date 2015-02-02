#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

void map_1multi(map_t *tmp) {
    int i;
    
    // on initialise tout à 0
    memset(tmp, 0, sizeof(map_t));
    /* initialisation objectif */
    do {
	tmp->objectif.x = 2 * Random(1, 16) - 1;
	tmp->objectif.y = 2 * Random(1, 16) - 1;
    } while( positions_invalides(tmp) );
    
    
    /* initialisation robots */
    tmp->robots[BLEU].pos.x = 19;
    tmp->robots[BLEU].pos.y = 23;	
    tmp->robots[BLEU].couleur = 'B';
    
    tmp->robots[ROUGE].pos.x = 11;
    tmp->robots[ROUGE].pos.y = 3;	
    tmp->robots[ROUGE].couleur = 'R';
    
    tmp->robots[VERT].pos.x = 11;
    tmp->robots[VERT].pos.y = 13;	
    tmp->robots[VERT].couleur = 'V';
    
    tmp->robots[GRIS].pos.x = 29;
    tmp->robots[GRIS].pos.y = 5;	
    tmp->robots[GRIS].couleur = 'G';
    
    /* initialisation plateau */
    i = 0;
    strncpy(tmp->plateau[i++],"+-------------------------------+", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . | . . . . . . . | . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.........................+=....|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . | . . . | . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|..........=+......=+...........|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|....=+........................=|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . | . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|=..............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . | . . . . . . | . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.+=..........+=.......=+...+=..|", SIZE_X);
    strncpy(tmp->plateau[i++],"| | . . . . . . . . . . | . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.............+---+.............|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . |   | . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.............|   |.............|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . |   | . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.............+---+......=+.....|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . | . . . . . . . . | . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|.......+=..+=.................=|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . | . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|=..............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|..............=+.+=............|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . . . . | | . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|..=+...........................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . | . . . . . . . . . . . | . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|......=+...................+=..|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . | . . . . . . . . . . . |", SIZE_X);
    strncpy(tmp->plateau[i++],"|...............................|", SIZE_X);
    strncpy(tmp->plateau[i++],"| . . . . | . . . . . . . . | . |", SIZE_X);
    strncpy(tmp->plateau[i++],"+-------------------------------+", SIZE_X);
}