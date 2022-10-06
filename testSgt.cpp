#include "stdafx.h"
#include "pt.h"
#include "sgt.h"
void testSgt(void);

void testSgt(void) // Les segments _____________________________________________
{
	cout << "\nTest de la classe segment\n\n" << endl;
	// 1er tests
	{
		// TODO
		// Construction par défaut : les deux extrémités se trouvent à l'origine
		sgt s0;
		assert(s0 == s0);
		double x1 = dRand(-20,10); double x2 = dRand(-10,30);
		double y1 = dRand(-20,10); double y2 = dRand(-10,30);
		// Constuction à partir de deux points
		sgt s1(pt(x1,y1), pt(x2,y2));
		assert(EPSEQUAL(s1.get_x1(), x1)); assert(EPSEQUAL(s1.get_x2(), x2));
		assert(EPSEQUAL(s1.get_y1(), y1)); assert(EPSEQUAL(s1.get_y2(), y2));
		// L'opérateur d'affectation implicite et le constructeur de copie implicite
		// conviennent : on ne les code pas explicitement.
		sgt s2(s1);
		assert(s2 == s1);
		// Renvoie la longueur du segment (distance euclidienne entre ses extrémités)
		double dist = s2.length();
		assert(EPSEQUAL(dist, sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))));
		// Translation du segment de (dx,dy)
		double dx = dRand(-2, 5); double dy = dRand(-2, 5);
		s2.offset(dx, dy);
		assert(EPSEQUAL(s2.get_x1(), x1+dx) && EPSEQUAL(s2.get_y1(), y1+dy));
		assert(EPSEQUAL(s2.get_x2(), x2+dx) && EPSEQUAL(s2.get_y2(), y2+dy));
		// Renvoie le point milieu du segment.
		pt p0(s1.centerPt());
		assert(EPSEQUAL(p0.getX(), (x1+x2)/2.0 ) && EPSEQUAL(p0.getY(), (y1+y2)/2.0 ));
		// Renvoie un point situé sur segment et le plus proche du point argument
		//const pt closerTO(void) const;

		double arret = 0.0;
	}

	// CloserTo
	{
		for (int k = 0; k < 100; ++k)
		{
			// On vérifie sgt::closerPtTo en générant 3 points aléatoires p1, p2 et p3.
			// On calcule pClose le point du segment [p1,p2] le plus proche de p3.
			// Puis on vérifie qu'une sélection d'autres points aléatoires du segment
			// [p1,p2] sont tous plus éloignés.

			// TODO


		}
	}

}