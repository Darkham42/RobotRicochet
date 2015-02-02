#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

void map_2(map_t *tmp) {
    int i;
    
    /* initialisation objectif */
    tmp->objectif.x = 11;
    tmp->objectif.y = 17;
    
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