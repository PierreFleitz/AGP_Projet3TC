#include <stdio.h>
#include <stdlib.h>

/***************************************
*  Création de la structure NODE pour  *
*  notre représentation intermédiaire  *
* 				       *
***************************************/

typedef struct NODE {
	int type_noeud; // type_noeud va être le mot-clé i.e FORWARD 
	int val; 	// Il s'agit ici du paramètre i.e 100 
	struct NODE* repeat;		// Pour l'instruction REPEAT
	struct NODE* next;		// Pointe vers la prochaine instruction 
} NODE ;

typedef struct POINT {
	int value_x; //coordonnée x
	int value_y; // coordonnée y
	int arg; // valeur de l'angle
} POINT ;

static NODE* root;
static POINT* origine;
static FILE* fichier;
NODE *newNode(int type, int valeur, NODE* sousProgramme);
NODE *addNode(NODE* prog,NODE *noeud);
void freeProgram(NODE* program);
void printProgram(NODE* program);
void printProgramRepeat(NODE* program, int compteur);
void writeSVG(NODE* program, FILE *fichier, POINT* origine);
void generatSVG(NODE* program, FILE *fichier, POINT *origine);
