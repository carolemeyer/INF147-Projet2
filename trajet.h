/****************************************************************************************
/*                                  TRAJET.H                                            *
/****************************************************************************************
Auteures : Carole Meyer et Sabrina Kingsley
Date   : 22 octobre 2019
Session : Automne 2019

Ce module trajet déclare plusieurs fonctions génériques utilisées 
pour la gestion du trajet.
On y trouve les sous-programmes suivants :
-->	obtenir_depart		: retourne le numéro de la borne de départ ; 
-->	obtenir_arrivee		: retourne le numéro de la borne d'arrivée ;
-->	obtenir_autonomie	: retourne l'autonomie de la voiture ;

*****************************************************************************************/

#ifndef __TRAJET__ 
#define __TRAJET__

/****************************************************************************************
*                          DÉFINITION DES TYPES ET CONSTANTES                           *
****************************************************************************************/
typedef int* t_trajet;
#define INDICE_TRAJET_DEPART 0
#define INDICE_TRAJET_ARRIVEE 1
#define INDICE_TRAJET_AUTONOMIE 2
#define BORNE_MIN 1 
#define BORNE_MAX 150
#define AUTONOMIE_MIN 200
#define AUTONOMIE_MAX 500
#define MESS_DEPART "Quelle sera le numero de la borne de depart? Veuillez entrer une valeur entre 1 et 150.\n"
#define MESS_ARRIVEE "Quelle sera le numero de la borne d'arrivee? Veuillez entrer une valeur entre 1 et 150.\n"
#define MESS_AUTONOMIE "Quelle est l'autonomie de votre vehicule? Veuillez entrer une valeur entre 200 et 500.\n"
#define ANNULATION 0 //Valeur qui indique que l'utilisateur veut fermer le programme
#define NB_CASES_TAB_TRAJET 3
#define CHAR_ANNULATION 'q' //Caractere que l'utilisateur doit saisir pour fermer le programme


/****************************************************************************************
*                       DÉCLARATION DES FONCTIONS PUBLIQUES                             *
****************************************************************************************/
t_trajet creer_trajet(void);
int obtenir_depart(t_trajet tab_trajet);
int obtenir_arrivee(t_trajet tab_trajet);
int obtenir_autonomie(t_trajet tab_trajet);

#endif