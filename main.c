/****************************************************************************************
/*                                  MAIN.C                                              *
/****************************************************************************************
Auteures : Carole Meyer et Sabrina Kingsley
Date   : 22 octobre 2019
Session : Automne 2019

...que fait ce module ?...

*****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "trajet.h"
#include "chemin.h"


/****************************************************************************************
*                           DÉFINITION DES TYPES ET CONSTANTES                          *
****************************************************************************************/

typedef int* t_trajet;
typedef int* t_chemin;

/****************************************************************************************
*                           DÉCLARATION DES FONCTIONS PRIVEES                           *
****************************************************************************************/

void liberer_tableau(int* tableau);
int saisir_nombre(char* message, int borne_min, int borne_max, int* adresse_valeur_saisie);

/****************************************************************************************
*                           DÉFINITION DES FONCTIONS PUBLIQUES                          *
****************************************************************************************/

int main(void)
{
	//Création du tableau du trajet
	t_trajet mon_trajet = creer_trajet(); 
	
	//La première case du tableau du trajet vaut 0 quand la saisie n'est pas valide
	//Les données du trajet sont affichées si toutes les saisies sont valides
	if (mon_trajet[INDICE_TRAJET_DEPART] != ANNULATION)
	{
		printf("Le trajet va de la borne %i a la borne %i.\n"
			"L'autonomie du vehicule est de : %i km.\n", 
			mon_trajet[INDICE_TRAJET_DEPART], mon_trajet[INDICE_TRAJET_ARRIVEE], mon_trajet[INDICE_TRAJET_AUTONOMIE]);
	}
	else
	{
		printf("La saisie est annulee.\n");
	}


	//Libération de la mémoire avant de terminer le programme principal
	liberer_tableau(mon_trajet);

	system("pause");
	return EXIT_SUCCESS;
}

/****************************************************************************************
*                           DÉFINITION DES FONCTIONS PRIVEES                            *
****************************************************************************************/

void liberer_tableau(int* tableau)
{
	free(tableau);
}

