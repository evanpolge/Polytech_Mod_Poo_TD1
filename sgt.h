//******************************************************************************
//                                                                             *
//                     NE PAS MODIFIER CE FICHIER SAUF                         *
//     pour ajouter des include ou des définitions de fonctions en-lignes      *
//                                                                             *
//******************************************************************************
#pragma once


class sgt
{
	// Data _________________________________________________________________________

	// La première extrémité et la seconde extrémité du segment
	// Les extrémités sont distinguées (comme pour un vecteur)


public:
	// Construction _________________________________________________________________

	// Construction par défaut : les deux extrémités se trouvent à l'origine

	// Constuction à partir de deux points

	// L'opérateur d'affectation implicite et le constructeur de copie implicite
	// conviennent : on ne les code pas explicitement.

	// Accesseurs ___________________________________________________________________

	// Renvoie une copie du premier point du segt
	// nom : get_p1

	// Donne une valeur au premier point du segt
	// nom : set_p1

	// Renvoie une copie du second point du segt
	// nom : get_p2

	// Donne une valeur au second point du segt
	// nom : set_p2

	// Fonctions qui retournent les limites des intervalles définis par les pro-
	// jections du segment sur les axes x et y : [x1, x2] et [y1, y2]
	// nom : x1
	// nom : x2
	// nom : y1
	// nom : y2

	// Opérations ___________________________________________________________________

	// Renvoie vrai si le segment d'appel et l'argument sont égaux : leurs premières
	// extrémités sont égales et leurs secondes extrémités sont égales.
	// nom : operator==

	// Renvoie la longueur du segment (distance euclidienne entre ses extrémités)
	// nom : length

	// Translation du segment de (dx,dy)
	// nom : offset

	// Renvoie le point milieu du segment.
	// nom : centerPt

	// Renvoie un point situé sur segment et le plus proche du point argument
	// nom : closerTo

	// Renvoie la distance euclidienne du segment au point argument
	// nom : euclide

	// Modifie la longueur du segment sans changer son point milieu, ni son 
	// orientation. La largeur est modifiée d'un certain % donné en argment.
	// Cet argument peut être compris entre 0 et 1, ce qui correspond à une 
	// réduction de longueur, ou bien supérieur à 1, ce qui correspond à une
	// augmentation de longueur. Mais il ne peut pas être négatif.
	// nom : inflate

	// Renvoie un point aléatoire situé sur le segment
	// nom : randPt

	// Ecriture dans un flux au format : SGT((x,y), (x,y))
	// nom : print
};

// Insertion d'un segment dnas un flux
// nom : operator<<





