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
*                           D�FINITION DES TYPES ET CONSTANTES                          *
****************************************************************************************/

typedef int* t_trajet;
typedef int* t_chemin;

/****************************************************************************************
*                           D�CLARATION DES FONCTIONS PRIVEES                           *
****************************************************************************************/

void liberer_tableau(int* tableau);
int saisir_nombre(char* message, int borne_min, int borne_max, int* adresse_valeur_saisie);

/****************************************************************************************
*                           D�FINITION DES FONCTIONS PUBLIQUES                          *
****************************************************************************************/

int main(void)
{
	//Cr�ation du tableau du trajet
	t_trajet mon_trajet = creer_trajet(); 
	
	//La premi�re case du tableau du trajet vaut 0 quand la saisie n'est pas valide
	//Les donn�es du trajet sont affich�es si toutes les saisies sont valides
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


	//Lib�ration de la m�moire avant de terminer le programme principal
	liberer_tableau(mon_trajet);

	system("pause");
	return EXIT_SUCCESS;
}

/****************************************************************************************
*                           D�FINITION DES FONCTIONS PRIVEES                            *
****************************************************************************************/

void liberer_tableau(int* tableau)
{
	free(tableau);
}

