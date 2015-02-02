#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "func.h"

void affichage_plateau(map_t *map) {
    map_t copie;
    int i, y, x;
    
    /* on copie le plateau pour pouvoir le modifier avant l'affichage */
    memcpy(&copie, map, sizeof(map_t));
    
    copie.plateau[copie.objectif.y][copie.objectif.x] = 'X';
    for(i = 0; i < 4; i++) {
	copie.plateau[copie.robots[i].pos.y][copie.robots[i].pos.x] = copie.robots[i].couleur;
    }
    
    clear();
    for(y = 0; y < SIZE_Y; y++) {
	for(x = 0; x < SIZE_X; x++) {
	    printw("%c ",copie.plateau[y][x]);
	}
	printw("\n",copie.plateau[y]);
    }
    
    refresh();
}

void affichage_selection_robot(map_t *map, int robot) {
    int x, y;
    
    // sauvegarde de la position courante
    getyx(stdscr, y, x);
    
    // choix de la couleur
    attron(COLOR_PAIR(2));
    
    // reaffichage du robot
    mvprintw(map->robots[robot].pos.y, map->robots[robot].pos.x * 2, "%c", map->robots[robot].couleur);
    
    attroff(COLOR_PAIR(2));
    
    // retour du curseur
    move(y, x);
    
    refresh();
}