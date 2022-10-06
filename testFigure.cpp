#include "stdafx.h"
#include "figure.h"


void testFigure(void)
{
	cout << "\nTest de la classe figure\n\n" << endl;

	// On initialise un rectangle cadre de dimension et de position aléatoires


	// On constuit une figure vide délimitée par ce rectangle et on l'affiche


    // On ajoute un segment nul à la figure encore vide et on l'affiche
 

	// On génére un point de référence aléatoire dans le rectangle cadre pour 
	// distinguer les segments de la figure en segments "proches" de ce point et
	// les autres


	// Pour définir la notion de "proche du pt de référence", on produit une
	// valeur de distance aléatoire qui soit inférieure à la largeur et à la
	// hauteur du rectangle cadre


	// On agrandit le rectangel cadre d'environ 10% dans chaque axe de façon à
	// produire aussi parfois des segments qui sont dans le rectangle cadre, 
	// mais pas dans les limites de la figure.


	// On peuple la figure avec des segments aléatoires inclus dans le rectangle
	// cadre et on sélectionne ceux qui sont proches du point de référence.
	// On change aussi régulièrement l'épaisseur du crayon courant.


	// On vérifie ce que l'on peut.


	// Construction par copie
	// On teste la construction par copie en vérifiant la duplication : une figure
	// et sa copie ont des segments identiques et dans le même ordre.


	// Suppression des segmenst sélectionnés
	// On supprime de tous les segments sélectionnés et on teste ce qu'on peut.


	// Recherche du segment le plus proche d'un point donné (si la figure est
	// non vide)

		// On choisit comme pt de référence un pt d'un sgt aléatoire de la figure


		// On recherche le sgt de la figure le plus proche de ce pt de référence

		// On vérifie ce qu'il faut.

}
