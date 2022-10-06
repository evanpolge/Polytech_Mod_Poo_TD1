#include "stdafx.h"
#include "figure.h"
#include "algorithm"

class sgt;

// Teste si la figure est dans un état valide
bool figure::valid(void) const
{
	// TODO
	return true;
}

//// constructeurs, destructeur
//figure::figure(const rct& _rLimit)
//{
//	assert(_rLimit.valid());
//
//	// TODO
//	// Décommentez ces lignes et codez après avoir codé la classe rectangle
//	// Utilisez aussi la liste d'initialisation
//
//	assert(valid());
//}

figure::~figure(void)
{
	assert(valid());

	// TODO
}


//figure::figure(const figure& f)
//{
//	assert(f.valid());
//
//	// TODO
//	// Décommentez ces lignes et codez après avoir corrigé la déclaration
//	// Utilisez aussi la liste d'initialisation
//
//
//	assert(valid());
//}


// Insertion dans un flux
ostream& operator<<(ostream& s, const figure& f)
{
	assert(f.valid());

	// TODO 


	return s;
}

// Renvoie le segment de rang "i", en lecture ou en écriture
//graphSgt& figure::operator[](unsigned long i) const
//{
//
//	// TODO 
//	// Décommentez ces lignes et codez (utilise la classe graphSgt, déjà codée)
//
//
//}

// Ajoute un segment graphique à la figure. La géométrie du segment est donnée
// par l'argument, son épaisseur de trait est l'épaisseur de trait courante de
// la figure et son état est non-sélectionné. Le segement n'est inséré dans la 
// figure que s'il est inclus dans son rectange limite
// Valeur de retour : le rang du nouveau segment dans le tableau de segments.
//const unsigned long figure::add(const sgt s)
//{
//    assert( valid() );
//
//	// Décommentez ces lignes et codez après avoir codé la classe segment
//	// TODO
//
//
//    assert( valid() );
//    return 0; // Précisez
//}

// Renvoie le nombre de segments actuellement sélectionnés
const unsigned long figure::getNbrSelected(void) const
{
    assert(valid());
	
	// TODO

	return 0; // Précisez
}

// Supprime tous les segments sélectionnés et renvoie leur nombre
const unsigned long figure::remove(void)
{
	assert( valid() );


	assert( valid() );
	return 0; // Précisez
}

// Retourne le rang du (ou d'un) segment de la figure qui est le plus proche
// du point argument. Si la figure est vide, déclenche une assertion.
const unsigned long figure::closerTo(pt pRef) const
{
    assert( valid() );

	// TODO

	return 0; // Précisez
}

// Ecrit la figure dans le flux argument : le rectangle cadre et la liste de
// tous les segments, un par ligne ; un * précède les segments sélectionnés.
void figure::print(ostream& s) const
{
	assert( valid() );

	// TODO
}

// Agrandit le tableau de segments de 10%, mais au moins 8 palces de plus
void figure::expand(void)
{
	assert( valid() );
	
	// TODO

	assert( valid() );
}

