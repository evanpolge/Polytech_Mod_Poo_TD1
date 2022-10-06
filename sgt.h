//******************************************************************************
//                                                                             *
//                     NE PAS MODIFIER CE FICHIER SAUF                         *
//     pour ajouter des include ou des définitions de fonctions en-lignes      *
//                                                                             *
//******************************************************************************
#pragma once
#include "pt.h"

class sgt
{
	// Data _________________________________________________________________________

	// La première extrémité et la seconde extrémité du segment
	// Les extrémités sont distinguées (comme pour un vecteur)
	pt p1;
	pt p2;

public:
	// Construction _________________________________________________________________

	// Construction par défaut : les deux extrémités se trouvent à l'origine
	sgt(void);

	// Constuction à partir de deux points
	sgt(const pt p1, const pt p2);

	// L'opérateur d'affectation implicite et le constructeur de copie implicite
	// conviennent : on ne les code pas explicitement.
    sgt(const sgt& s2);

	// Accesseurs ___________________________________________________________________

	// Renvoie une copie du premier point du segt
	// nom : get_p1
	const pt get_p1 (void) const;
	// Donne une valeur au premier point du segt
	// nom : set_p1
	void set_p1(const pt p3);
	// Renvoie une copie du second point du segt
	// nom : get_p2
	const pt get_p2 (void) const;
	// Donne une valeur au second point du segt
	// nom : set_p2
	void set_p2 (const pt p2);

	// Fonctions qui retournent les limites des intervalles définis par les pro-
	// jections du segment sur les axes x et y : [x1, x2] et [y1, y2]
	// nom : x1
	const double get_x1 (void) const;
	// nom : x2
	const double get_x2 (void) const;
	// nom : y1
	const double get_y1 (void) const;
	// nom : y2
	const double get_y2 (void) const;

	// Opérations ___________________________________________________________________

	// Renvoie vrai si le segment d'appel et l'argument sont égaux : leurs premières
	// extrémités sont égales et leurs secondes extrémités sont égales.
	// nom : operator==
	bool operator==(const sgt& s2) const;

	// Renvoie la longueur du segment (distance euclidienne entre ses extrémités)
	// nom : length
	const double length(void) const;
	// Translation du segment de (dx,dy)
	// nom : offset
	void offset(const double dx, const double dy);

	// Renvoie le point milieu du segment.
	// nom : centerPt
	const pt centerPt(void) const;

	// Renvoie un point situé sur segment et le plus proche du point argument
	// nom : closerTo
	const pt closerTO(const pt& p1) const;

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

// DEFINITION DES FONCTIONS INLINE
//______________________________________________________________________________

// Donne une valeur au premier point du segt
inline void sgt::set_p1(const pt p3)
{
	this-> p1.setX(p3.getX());
	this-> p1.setY(p3.getY());
}

// Donne une valeur au second point du segt
inline void sgt::set_p2(const pt p4)
{
	this-> p2.setX(p4.getX());
	this-> p2.setY(p4.getY());
}

// Renvoie une copie du premier point du segt
inline const pt sgt::get_p1(void) const
{
	return this-> p1;
}

// Renvoie une copie du second point du segt
inline const pt sgt::get_p2(void) const
{
	return this-> p2;
}

// Renvoie une copie de la coordonnée x du premier point du segt
inline const double sgt::get_x1 (void) const
{
	return this->p1.getX();
}
// Renvoie une copie de la coordonnée x du second point du segt
inline const double sgt::get_x2 (void) const
{
	return this->p2.getX();
}

// Renvoie une copie de la coordonnée y du premier point du segt
inline const double sgt::get_y1 (void) const
{
	return this->p1.getY();
}
// Renvoie une copie de la coordonnée y du second point du segt
inline const double sgt::get_y2 (void) const
{
	return this->p2.getY();
}

// Insertion d'un segment dnas un flux
// nom : operator<<





