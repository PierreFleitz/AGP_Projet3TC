#include <stdio.h>
#include <stdlib.h>
#include "monProg.h"
#include <math.h>

#define FORWARD 1
#define REPEAT 2
#define LEFT 3
#define RIGHT 4
#define CIRCLE 5
#define CARRE 6

/***********************************************************************
 				
				On va interpréter la création de nos 
 				noeuds comme un arbre. Un abre dont  
 				seuls les noeuds de types REPEAT     
 				possèderont un typeg(next) et un     
 				typed(repeat). 
                       
***********************************************************************/
  
NODE *newNode(int type, int valeur, NODE* sousProgramme){
	NODE* noeud;
	noeud=(NODE *)malloc(sizeof(NODE));
	if (noeud == 0){ // On vérifie que noeud peut être créé
		printf("newNode: Il n'y a plus de place mémoire.\n");
		exit(-1);
	}
	
	// On initialise le nouveau noeud
	
	noeud->type_noeud = type;
	noeud->val = valeur;
	noeud->repeat = NULL;
	noeud->next = NULL;
	if (type==2){	// Il s'agit du cas particulier où la nouvelle instruction est un REPEAT
		noeud->repeat = sousProgramme;
	}
	return(noeud);
}

/***********************************************************************
 				       
 				Cette fonction addNode va ajouter un 
 				noeud à la fin de notre programme    
 				rentré en paramètres. Il va le par-  
 				-courir puis ajouter un nouveau noeud
 				       
***********************************************************************/

NODE *addNode(NODE* prog,NODE *noeud){
	NODE* visitor;
	visitor = prog;
	
	while (visitor->next != NULL){ // On parcourt visitor jusqu'à la fin pour y ajouter une nouveau noeud
		
		visitor = visitor->next;
		
	}
	visitor->next = noeud;
	return(prog);
}

/***********************************************************************
 				       
				Fonction freeProgram qui va libérer la mémoire
 				       
***********************************************************************/

void freeProgram(NODE* program){

	if(program==NULL){ // On test si program n'est pas null, dans le cas contraire on quitte la fonction
		return ;
	}
	
	if(program->repeat != NULL){ // Si program possède un repeat donc un sous programme on le free	
		freeProgram(program->repeat);
	}
	
	freeProgram(program->next); // On appelle freeP
	free(program);
}


/***********************************************************************
				       
				On écrit une fonction qui affichera  
				la suite d'instruction.	       
				       
***********************************************************************/

void printProgram(NODE* program){
	NODE* courant;
	courant = program;
	
	int compteur=0;
	
	while (courant != NULL){
		if ( courant->type_noeud == 1 ){ // Cas type de noeud est un FORWARD
			printf("FORWARD %d \n", courant->val);
		}
		if ( courant->type_noeud == 2){ // Cas type de noeud est un REPEAT
			printf("REPEAT %d [\n",courant->val);
			printf("\t");
			printProgramRepeat(courant->repeat, compteur);
			printf("]\n");
		}
		if ( courant->type_noeud == 3){ // Cas type de noeud est un LEFT
			printf("LEFT %d \n", courant->val);
		}
		if ( courant->type_noeud == 4){ // Cas type de noeud est un RIGHT
			printf("RIGHT %d \n", courant->val);
		}
		if ( courant->type_noeud == 5){ // Cas type de noeud est un CIRCLE
			printf("CIRCLE %d \n", courant->val);
		}
		if ( courant->type_noeud == 6){ // Cas type de noeud est un SQUARE
			printf("SQUARE %d \n", courant->val);
		}
		if (courant->next == NULL){
			printf("");
		}
		courant = courant->next;
	}
}

/***********************************************************************
				       				   
 				On écrit une fonction qui affichera 
 				la suite d'instructions présente dans un REPEAT.
 				Cette fonction est quasi identique à printProgram
 				mais elle va permettre de gérer la mise en place de
 				l'indentation du sous programme dans un REPEAT.
 			               			   
***********************************************************************/


void printProgramRepeat(NODE* program,int compteur){
	
	NODE* courant;
	courant = program;
	
	int i;
	compteur ++;
	
	while (courant != NULL){
		if ( courant->type_noeud == 1 ){ // Cas type de noeud est un FORWARD
			printf("FORWARD %d \n", courant->val);
			
			while(compteur != 0){ 			 // On affiche "compteur-1 fois" une tabulation à la ligne après l'instruction en utilisant une boucle while
				printf("\t");	
				compteur--;
			}
		}
		if ( courant->type_noeud == 2){ // Cas type de noeud est un REPEAT
			printf("REPEAT %d [\n",courant->val);
			
			for (i = 0; i <= compteur; i++){ // On affiche "compteur fois" une tabulation à la ligne en utilisant une boucle for
				printf("\t");
			}
			
			printProgramRepeat(courant->repeat, compteur);
			
			while(compteur != 0){ 			 // On affiche "compteur-1 fois" une tabulation à la ligne après l'instruction en utilisant une boucle while
				printf("\t");
				compteur--;
			}
			printf("]\n");
		}
		if ( courant->type_noeud == 3){ // Cas type de noeud est un LEFT
			printf("LEFT %d \n", courant->val);
			
			while(compteur != 0){ 			 // On affiche "compteur-1 fois" une tabulation à la ligne après l'instruction en utilisant une boucle while
				printf("\t");
				compteur--;
			}
		}
		if ( courant->type_noeud == 4){ // Cas type de noeud est un RIGHT
			printf("RIGHT %d \n", courant->val);
			
			while(compteur != 0){ 			 // On affiche "compteur-1 fois" une tabulation à la ligne après l'instruction en utilisant une boucle while
				printf("\t");
				compteur--;
			}
		} 
		if ( courant->type_noeud == 5){ // Cas type de noeud est un CIRCLE
			printf("CIRCLE %d \n", courant->val);
			
			while(compteur != 0){ 			 // On affiche "compteur-1 fois" une tabulation à la ligne après l'instruction en utilisant une boucle while
				printf("\t");
				compteur--;
			}
		}
		if ( courant->type_noeud == 6){ // Cas type de noeud est un SQUARE
			printf("SQUARE %d \n", courant->val);
			
			while(compteur != 0){ 			 // On affiche "compteur-1 fois" une tabulation à la ligne après l'instruction en utilisant une boucle while
				printf("\t");
				compteur--;
			}
		}
		if (courant->next == NULL){
			printf("");
		}
		courant = courant->next;
	}
}

/***********************************************************************
				       				   
 				On écrit une fonction qui va générer 
 				le corps du code SVG   
 			               			   
***********************************************************************/

void writeSVG(NODE* program, FILE *fichier,POINT* origine){

	NODE* courant;
	courant = (NODE*)malloc(sizeof(NODE));
	courant = program;
	
	POINT* fin;
	fin =(POINT *)malloc(sizeof(POINT));
	fin->value_x = 0;
	fin->value_y = 0;
	
	int x1;
	int y1;
	int x2;
	int y2;
	int i;
	
	while(courant!=NULL){
		if(courant != NULL){
			switch(courant->type_noeud) {

			case 1: // Cas de FORWARD
				x1=origine->value_x;
				y1=origine->value_y;

				x2=x1 + (int)courant->val*cos((origine->arg*2*3.14)/360);
				y2=y1 + (int)courant->val*sin((origine->arg*2*3.14)/360);
				fin->value_x=x2;
				fin->value_y=y2;
				fprintf(fichier,"<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"blue\" stroke-width=\"5\" stroke-linecap=\"round\" />\n",x1,y1,x2,y2);
				origine->value_x = fin->value_x;
				origine->value_y = fin->value_y;
				break;

			case 2: // Cas de REPEAT
				for(i=0;i<courant->val;i++){
					writeSVG(courant->repeat,fichier, origine);
				}
				break;

			case 3: // Cas de LEFT
				origine->arg = origine->arg - courant->val;
				break;

			case 4: // Cas de RIGHT
				origine->arg = origine->arg + courant->val;
				break;

			case 5: // Cas du CIRCLE
				x1= origine->value_x;
				y1= origine->value_y;
				x2= origine->value_x;
				y2= origine->value_y;
				fin->value_x = x2;
				fin->value_y = y2;
				fprintf(fichier,"<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"blue\" stroke-width=\"5\" fill=\"blue\" />\n",x1,y1,courant->val);
				origine->value_x = fin->value_x;
				origine->value_y = fin->value_y;
				break;
				
			case 6: // Cas du SQUARE
				x1= origine->value_x - courant->val/2; // Position du rectangle axe horizontale par rapport au coin supérieur gauche
				y1= origine->value_y - courant->val/2; // Position du rectangle axe verticale par rapport au coin supérieur gauche
				x2= origine->value_x; 
				y2= origine->value_y;
				fin->value_x = x2;
				fin->value_y = y2;
				fprintf(fichier,"<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"blue\" stroke-width=\"5\" fill=\"blue\" />\n",x1,y1,courant->val,courant->val);
				origine->value_x = fin->value_x;
				origine->value_y = fin->value_y;
				break;
			}
		}
	courant = courant->next;	
	}
	free(courant);
	free(fin);
}

/***********************************************************************
				       				   
 				On écrit une fonction qui va générer dans 
 				un fichier l'en-tête de notre code SVG et
 				qui appellera la fonction writeSVG pour
 				générer le corps du code SVG.   
 			               			   
***********************************************************************/

void generatSVG(NODE* program, FILE *fichier, POINT *origine){
	
	NODE* courant;
	courant = (NODE*)malloc(sizeof(NODE));
	courant = program;

	origine =(POINT *)malloc(sizeof(POINT));

	fichier = fopen("tplogo.svg","w"); // On créé le fichier tplogo de type SVG
	
	origine->value_x=500;
	origine->value_y=500;
	origine->arg=0;

	if (fichier != NULL){

		fprintf(fichier,"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
		fprintf(fichier,"<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"1500\" height=\"1500\">\n");
		fprintf(fichier,"<title> TPLOGO SVG FLEITZ </title>\n");
		fprintf(fichier,"<desc> Du LOGO. </desc>\n");
		writeSVG(courant,fichier,origine);
		fprintf(fichier,"</svg>");
		fclose(fichier);
	}
}
