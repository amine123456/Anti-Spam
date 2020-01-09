
#include <regex.h>
#include <stdio.h>

typedef struct Elemnt Elemnt;
struct Elemnt
{
	int nombre ;
	Elemnt *suivant;	
	}

Liste initialisation(){
	
	Liste *liste = malloc(sizeof(*liste));
	Element *element = malloc(sizeof(*element));
	
	if(liste == NULL || element == NULL){
		
		exit(EXIT_FAILURE);
		
		
		
		}
		
		element->nombre = 0;
		element->suivant= NULL;
		liste->premier = element;
		
		return liste
	
	
	}

void insertion(Liste *liste , int nvNombre){
	
	Element *nouveau = malloc(sizeof(*nouveau));
	
	if(liste == NULL || nouveau == NULL){
		
		exit(EXIT_FAILURE);	
		}
	
	nouveau->nombre = nvNombre ;
	nouveau->suivant = liste->premier;
	liste->premier = nouveau ;
	
	}
	
	void afficherListe(Liste *liste){
		
		
		if(liste == NULL){
		
		exit(EXIT_FAILURE);	
		}
		Element *actuel = liste->premier;
		
		while(actuel != NULL){
			
			printf("%d ->" , actuel->nombre);
			actuel= actuel->suivant;
			
			}
		printf("NULL \n");
		
		}
	

void main(){
	
	
Liste *maliste = initialisation();

insertion(maliste , 4);

	afficherListe(maliste);
}
