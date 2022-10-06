#pragma once
#include "pt.h"
class pt;
class sgt;

class rct  
{
private:
// Data _________________________________________________________________________

	// Un rectangle parallèle aux axes est défini par son point central, par sa
	// sa largeur et par sa hauteur.

	pt pC;
	double w, h; // width, height 

    // Un rectangle peut être dégénéré en un point quand sa largeur et sa hauteur
    // sont nulles, ou dégénéré en un segment, quand l'une seulement de ces deux
    // quantités (largeur / hauteur) est nulle. Un rectangle n'est jamais vide au
    // sens ensembliste, même s'il est dégénéré. Il faut le prendre en considéra-
    // tion pour les calculs d'union ou d'intersection entre deux rectangles.

public:
// Mise au point ________________________________________________________________

	// Cette fonction renvoie *toujours* vrai, mais en configuration DEBUG, elle
	// déclenche auparavant une assertion si la condition de validité (w >= 0 et 
	// h >= 0) n'est pas vraie.
	bool valid(void) const;


// Construction _________________________________________________________________

	// Construction par défaut : rectangle réduit à un seul point (0,0)
	rct(void); 
	
	// Construction à partir des bords [x1..x2]x[y1..y2] 
	rct(const double x1, const double x2, const double y1, const double y2);

	// Construction à partir de deux points absolument quelconques : le plus pe-
	// tit rectangle qui contient les deux points.
	rct(const pt p1, const pt p2);

	// L'opérateur d'affectation implicite et le constructeur de copie implicite 
	// conviennent. On ne les code pas explicitement.
    rct(const rct& r2);
    
// Accesseurs __________________________________________________________________
	
	const pt getCenterPt(void) const;      // Renvoie une copie du point central	
	const double getWidth(void) const;                     // Renvoie la largeur
	const double getHeight(void) const;                    // Renvoie la hauteur

// Attributs dérivés ___________________________________________________________
	
	const double x1(void) const;	        // Renvoie l'abscisse du coté gauche
	const double x2(void) const;             // Renvoie l'abscisse du coté droit
	const double y1(void) const;	           // Renvoie l'ordonnée du coté bas
	const double y2(void) const;              // Renvoie l'ordonnée du coté haut

	const pt bottomLeft(void) const;         // Renvoie le coin inférieur gauche
	const pt topRight(void) const;            // Renvoie le coin supérieur droit
	const pt topLeft(void) const;            // Renvoie le coin supérieur gauche
	const pt bottomRight(void) const;         // Renvoie le coin inférieur droit

	double area(void) const;                               // Renvoie la surface


// Prédicats ___________________________________________________________________

	
	// Deux rectangles sont égaux s'ils ont les mêmes limites
	bool operator==(const rct& s2) const;
	
	// Renvoie vrai ssi le point argument est contenu dans le rectangle
	bool contains(const pt& p) const;

	/*
	// Renvoie vrai ssi le segment argument est dans le rectangle 
	bool contains(const sgt& s) const;
	*/
	// Renvoie vrai ssi le rectangle argument est dans le rectangle 
	bool contains(const rct& c) const;

// Opérations __________________________________________________________________
	
	// Translate (déplacement relatif) le rectangle de (dx, dy)
	void offset(const double dx, const double dy);

	// Déformation du rectangle : la largeur est modifiée de px %, et la hauteur
	// de py %, mais sans déplacement du centre. L'argument px (resp. py) peut
	// être compris entre 0 et 1, ce qui correspond à une  réduction de largeur 
	// (resp. hauteur), ou bien supérieur à 1, ce qui correspond à une augmenta-
	// tion de largeur (resp. hauteur). Mais ils ne peuvent pas être négatifs.
	void inflate(const double px, const double py);
/*
	// Renvoie la distance du point argument au rectangle (0 si ptRef est conte-
	// nu dans le rectangle, sinon sa distance au plus proche côté du rectangle)
	double euclide(const pt& ptRef) const;
	*/
	// Renvoie un point aléatoire contenu dans le rectangle
	pt randPt(void) const;
	/*
	// Renvoie un segment aléatoire contenu dans le rectangle
	sgt randSgt(void) const;
	*/
	// Renvoie un rectangle aléatoire contenu dans le rectangle
	rct randRct(void) const;


 	// Ecrit le rectangle dans le flux argument au format RCT[x1, x2]x[y1, y2]
	void print(ostream& s) const;
};

// Fonctions globales associées à la classe "rct"
//_______________________________________________________________________________

// Insertion dans un flux de sortie
ostream& operator<<(ostream& s, const rct& rc);


// Fonctions membres en ligne de la classe rct
//_______________________________________________________________________________
//
inline const pt rct::getCenterPt(void) const
{
	assert(valid());
	return this->pC;
};

inline const double rct::getWidth(void) const                     // Renvoie la largeur
{
	assert(valid());
	return this->w;
};

inline const double rct::getHeight(void) const                    // Renvoie la hauteur
{
	assert(valid());
	return this->h;
};