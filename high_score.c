#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "func.h"

int high_score (void)
{
    const char* vFileName = "high_score.txt";
    int score;
    char buffer[256], name[256];
    
    FILE *vFileStream = fopen(vFileName, "r");
    
    if (vFileStream == NULL) {
	fprintf(stderr, "Error loading '%s' : File not found !", vFileName);
	return -1;
    }
    
    printw("\nJoueur\t\tscore\n");
    //On lit le pseudo et le score
    while( fgets(buffer, sizeof(buffer) -1, vFileStream) ) {
	if( 2 == sscanf(buffer, "%s %d", name, &score) ) {
	    printw("%s\t\t%d\n", name, score);
	}
	// TODO : recopier le nom/score dans un tableau ?
	
	refresh();
    }
    
    fclose (vFileStream);
    
    printw("Appuyer sur une touche pour retourner au menu.");
    getch();
    
    refresh();
    return 0;
}


int save_score(const char* pPlayerName, int pScore)
{
    
    printw("Saving score for %s\n", pPlayerName);
    refresh();
    
    int vNewPlayerName = 1;
    char vBuffer[256];
    int vReadScore;
    char vReadName[256];
    const char* vTempFileName = "high_score.temp.txt";
    const char* vScoreFileName = "high_score.txt";
    FILE* vTempFileStream = NULL;
    FILE* vScoreFileStream = NULL;
    
    
    // Copier le fichier score
    vTempFileStream = fopen(vTempFileName, "w");
    vScoreFileStream = fopen(vScoreFileName, "r");
    if(!vScoreFileStream) {
	fprintf(stderr, "Could not open %s : file does not exists !", vScoreFileName);
	return -1;
    }
    
    // eof returns 1 if end of file is reached
    while(fgets(vBuffer, 256, vScoreFileStream))
	if(strlen(vBuffer) > 1)
	    fprintf(vTempFileStream, "%s", vBuffer);
	
	fclose(vScoreFileStream);
    fclose(vTempFileStream);
    
    // Lecture de l'ancien et écriture du nouveau
    vScoreFileStream = fopen(vScoreFileName, "w");
    vTempFileStream = fopen(vTempFileName, "r");
    if(!vTempFileStream) {
	fprintf(stderr, "Could not open %s : file does not exists !", vScoreFileName);
	return -1;
    }
    
    while(fgets(vBuffer, 256, vTempFileStream)) {
	
	sscanf(vBuffer, "%s %d", vReadName, &vReadScore);
	
	if(!strcmp(vReadName, pPlayerName)) {
	    vNewPlayerName = 0;
	    if(pScore < vReadScore)
		vReadScore = pScore;
	}
	
	fprintf(vScoreFileStream, "%s %d\n", vReadName, vReadScore);
    }
    
    if(vNewPlayerName)
	fprintf(vScoreFileStream, "%s %d\n", pPlayerName, pScore);
    
    fclose(vTempFileStream);
    fclose(vScoreFileStream);
    
    
    return 0;
}