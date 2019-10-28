/****************************************************************************************
/*                                  TRAJET.C                                            *
/****************************************************************************************
Auteures : Carole Meyer et Sabrina Kingsley
Date   : 22 octobre 2019
Session : Automne 2019

...que fait ce module ?...

*****************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "trajet.h"


/****************************************************************************************
*                           DÉFINITION DES TYPES ET CONSTANTES                          *
****************************************************************************************/



/****************************************************************************************
*                           DÉCLARATION DES FONCTIONS PRIVEES                           *
****************************************************************************************/

int saisir_nombre(char* message, int borne_min, int borne_max, int* adresse_valeur_saisie);

/****************************************************************************************
*                           DÉFINITION DES FONCTIONS PUBLIQUES                          *
****************************************************************************************/
t_trajet creer_trajet(void)
{
	int borne_depart; //Valeur de la borne de depart du trajet
	int borne_arrivee; //Valeur de la borne d'arrivee du trajet
	int autonomie; //Valeur de l'autonomie du vehicule de l'utilisateur

	//Tableau qui conserve les informations saisies par l'utilisateur
	t_trajet info_utilisateur = (t_trajet)malloc(NB_CASES_TAB_TRAJET * sizeof(t_trajet));

	if (info_utilisateur != NULL) //Verification de l'allocation de la memoire
	{
		printf("En tout temps, vous pouvez entrer la lettre '%c' si vous desirez fermer le programme.\n\n", CHAR_ANNULATION);

		//Saisie de la valeur de la borne de depart
		borne_depart = saisir_nombre(MESS_DEPART, BORNE_MIN, BORNE_MAX, &info_utilisateur[INDICE_TRAJET_DEPART]);
		if (borne_depart == ANNULATION) //Si la fonction retourne 0, c'est que l'utilisateur veut fermer le programme
		{
			info_utilisateur[0] = ANNULATION; //Indication que l'utilisateur veut fermer le programme
		}

		//Saisie de la valeur de la borne d'arrivee
		borne_arrivee = saisir_nombre(MESS_ARRIVEE, BORNE_MIN, BORNE_MAX, &info_utilisateur[INDICE_TRAJET_ARRIVEE]);
		if (borne_arrivee == ANNULATION) //Si la fonction retourne 0, c'est que l'utilisateur veut fermer le programme
		{
			info_utilisateur[0] = ANNULATION; //Indication que l'utilisateur veut fermer le programme
		}

		//Saisie de la valeur de l'autonomie du vehicule
		autonomie = saisir_nombre(MESS_AUTONOMIE, AUTONOMIE_MIN, AUTONOMIE_MAX, &info_utilisateur[INDICE_TRAJET_AUTONOMIE]);
		if (autonomie == ANNULATION) //Si la fonction retourne 0, c'est que l'utilisateur veut fermer le programme
		{
			info_utilisateur[0] = ANNULATION; //Indication que l'utilisateur veut fermer le programme
		}
	}
	return info_utilisateur;
}


int obtenir_depart(t_trajet tab_trajet)
{
	return tab_trajet[INDICE_TRAJET_DEPART];
}

int obtenir_arrivee(t_trajet tab_trajet)
{
	return tab_trajet[INDICE_TRAJET_ARRIVEE];
}

int obtenir_autonomie(t_trajet tab_trajet)
{
	return tab_trajet[INDICE_TRAJET_AUTONOMIE];
}

/****************************************************************************************
*                           DÉFINITION DES FONCTIONS PRIVEES                            *
****************************************************************************************/

int saisir_nombre(char* message, int borne_min, int borne_max, int* adresse_valeur_saisie)
{
	int validite_valeur = 0;
	char saisie[100];

	do
	{
		printf("%s", message);
		scanf("%s", &saisie);

		if (saisie[0] != CHAR_ANNULATION)
		{
			//Retourne 0 par la fonction atoi si la saisie est une chaine de caractères. Retourne la valeur du chiffre saisi en int sinon.
			*adresse_valeur_saisie = atoi(saisie);
			validite_valeur = 1;
		}
		else
		{
			return ANNULATION;
		}

	} while (*adresse_valeur_saisie < borne_min || *adresse_valeur_saisie > borne_max);


	return validite_valeur;
}