#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

int map_perso(map_t *map, const char *pFileName)
{
    unsigned int vRow, vRobot;
    FILE* vFileStream = fopen(pFileName, "r");
    char buffer[SIZE_X +1];
    
    if(!vFileStream) {
	fprintf(stderr, "Error loading '%s' : File not found !", pFileName);
	return -1;
    }
    
    // Lecture du plateau ligne par ligne
    for(vRow = 0 ; vRow < SIZE_Y ; ++vRow) {
	fgets(buffer, SIZE_X+1, vFileStream);
	strncpy(map->plateau[vRow], buffer, SIZE_X);
	map->plateau[vRow][SIZE_X-1] = 0;
    }
    
    // Lecture de l'objectif
    fscanf(vFileStream, "%d %d", &map->objectif.x, &map->objectif.y);
    
    // Lecture de la position des robots
    for(vRobot = 0 ; vRobot < NB_ROBOTS ; ++vRobot) {
	fscanf(vFileStream, "%d %d %c", &map->robots[vRobot].pos.x, &map->robots[vRobot].pos.y, &map->robots[vRobot].couleur);
    }
    fclose(vFileStream);
    return 0;
}