#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

void map_1(map_t *tmp) {
    int i;
    
    /* initialisation objectif */
    tmp->objectif.x = 29;
    tmp->objectif.y = 19;
    
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