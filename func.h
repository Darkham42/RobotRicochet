#ifndef FONC_H
#define FONC_H

#define SIZE_X	34
#define SIZE_Y	33
#define NB_ROBOTS 4

/* structures */

/* position */
typedef struct {
	int x;
	int y;
} position_t;

/* un robot */
typedef struct {
	position_t pos;
	char couleur;
} robot_t;

/* map */
typedef struct {
	char plateau[SIZE_Y][SIZE_X];
	position_t objectif;
	robot_t robots[NB_ROBOTS]; 
} map_t;

typedef enum {
	BLEU = 0,
	ROUGE,
	VERT,
	GRIS
} ROBOTS_COLORS;

typedef struct {
  int num_player;
  char pseudo[256];
  int score_d;
  int score_o;
} Player;

/* Fonctions */

int mode_solo ();
int mode_multi ();
int high_score ();
void sortie_propre();
int Random (int _iMin, int _iMax);
int positions_invalides(map_t *map);
void map_1(map_t *);
void map_2(map_t *);
void map_1multi(map_t *);
void map_2multi(map_t *);
void map_random(map_t *);
int map_perso(map_t *, const char *);
void affichage_plateau(map_t *map);
int choice_robot();
void affichage_selection_robot(map_t *map, int robot);
void choice_move_robot (map_t *carte, int robot);
int verification_victoire(map_t *);
int save_score(const char *playerName, int score);
void deplacement_robot(map_t *carte, int robot, int dir_x, int dir_y);
void obstacle_random();
int jeu_manche(map_t carte, Player *joueur, int nbr_manche);
int compare_score_joueur(const void *p1, const void *p2);
int regles();

#endif