#include "stdafx.h"
#include "pt.h"
#include "sgt.h"
#include "rct.h"


void testRect(void);

void testRct(void)// Test des rectangles
{
	cout << "\nTest de la classe rectangle\n\n" << endl;

	// TODO
	// 1ers tests
	{
		// Construction _________________________________________________________________
		cout << "\nConstructeur : \n" << endl;
		// Construction par défaut : rectangle réduit à un seul point (0,0)
		rct r0;
		cout << "r0= ";
		r0.print(cout);
		cout << endl;
		assert(r0==r0);

		// Construction à partir des bords [x1..x2]x[y1..y2] 
		double x1 = dRand(-10, 20);	double x2 = dRand(20, 40);
		double y1 = dRand(-30, 40); double y2 = dRand(40, 60);/*
		double x1 = dRand(-10, 20);	double x2 = dRand(-20, -10);
		double y1 = dRand(-30, 40); double y2 = dRand(-40, -30);*/
		rct r1(x1,x2,y1,y2);
		cout << "r1= ";
		r1.print(cout);
		cout << endl;
		pt pC0(r1.getCenterPt());
		assert(EPSEQUAL(r1.getHeight(), y2-y1));
		assert(EPSEQUAL(r1.getWidth(), x2-x1));
		assert(EPSEQUAL(pC0.getX(), (x2+x1)/2));
		assert(EPSEQUAL(pC0.getY() ,(y2+y1)/2));
		
		// L'opérateur d'affectation implicite et le constructeur de copie implicite 
		// conviennent. On ne les code pas explicitement.
		rct r2(r1);
		cout << "r2= ";
		r2.print(cout);
		cout << endl;
		assert(r2 == r1);

		// Construction à partir de deux points absolument quelconques : le plus pe-
		// tit rectangle qui contient les deux points.
		double x3 = dRand(-10, 20);	double x4 = dRand(20, 40);
		double y3 = dRand(-30, 40); double y4 = dRand(40, 60);
		pt p0(x3, y3);
		pt p1(x4,y4);
		rct r3(p0, p1);
		pt pC1(r3.getCenterPt());
		assert(EPSEQUAL(r3.getHeight(), fabs(y3-y4)));
		assert(EPSEQUAL(r3.getWidth(), fabs(x3-x4)));
		assert(EPSEQUAL(pC1.getX(), (x3+x4)/2));
		assert(EPSEQUAL(pC1.getY() ,(y3+y4)/2));

		// Accesseurs __________________________________________________________________
		cout << "\nAccesseurs : \n" << endl;
		double width = r1.getWidth();
		cout << "r1 width" << "(" << width << ")" << endl;
		double height = r1.getHeight();
		cout << "r1 height" << "(" << height << ")" << endl;
		pt pC2 = r1.getCenterPt();
		cout << "r1 pC" << "(x:" << pC2.getX() << ", y:" << pC2.getY() << ")" << endl;
		
		assert(EPSEQUAL(width, fabs(x2-x1)));
		assert(EPSEQUAL(height, fabs(y2-y1)));
		assert(EPSEQUAL(pC2.getX(), (x1+x2)/2));
		assert(EPSEQUAL(pC2.getY() ,(y1+y2)/2));
	}
	// Attributs dérivés ___________________________________________________________
	{
		cout << "\nAttributs dérivés : \n" << endl;
		double x1 = dRand(-10, 20);	double x2 = dRand(20, 40);
		double y1 = dRand(-30, 40); double y2 = dRand(40, 60);
		rct r0(x1,x2,y1,y2);
		cout << "r0= ";
		r0.print(cout);
		cout << endl;

		// Abscisse gauche x1
		double abs_gauche = r0.x1();
		assert(EPSEQUAL(abs_gauche, x1));

		// Abscisse droit x2
		double abs_droit = r0.x2();
		assert(EPSEQUAL(abs_droit, x2));

		// Ordonnée bas y1
		double ord_bas = r0.y1();
		assert(EPSEQUAL(ord_bas, y1));

		// Ordonnée haut y2
		double ord_haut = r0.y2();
		assert(EPSEQUAL(ord_haut, y2));
		
		// Calcul de l'air
		double area = r0.area();
		assert(EPSEQUAL(area, fabs(x1-x2)*fabs(y1-y2)));

		// Calcul du point inférieur gauche
		pt pX1;
		pX1 = r0.bottomLeft();
		assert(EPSEQUAL(pX1.getX(), x1));
		assert(EPSEQUAL(pX1.getY(), y1));

		// Calcul du point inférieur droit
		pt pX2;
		pX2 = r0.bottomRight();
		assert(EPSEQUAL(pX2.getX(), x2));
		assert(EPSEQUAL(pX2.getY(), y1));
		// Calcul du point supérieur gauche
		pt pY1;
		pY1 = r0.topLeft();
		assert(EPSEQUAL(pY1.getX(), x1));
		assert(EPSEQUAL(pY1.getY(), y2));
		// Calcul du point supérieur droit
		pt pY2;
		pY2 = r0.topRight();
		assert(EPSEQUAL(pY2.getX(), x2));
		assert(EPSEQUAL(pY2.getY(), y2));
	}

	// Prédicats ___________________________________________________________________
	{
		cout << "\nPredicats : \n\n" << endl;
		double x1 = dRand(-10, 10);	double x2 = dRand(30, 40);
		double y1 = dRand(-30, 30); double y2 = dRand(50, 70);
		pt p0(x1, y1);
		pt p1(x2, y2);
		rct r0(p0, p1);
		cout << "r0= ";
		r0.print(cout);
		cout << endl;
		assert(r0.contains(p0));
		assert(r0.contains(p1));

		double x3 = dRand(10, 20);	double y3 = dRand(30, 40);
		double x4 = dRand(20, 30);	double y4 = dRand(40, 50);

		pt p2(x3, y3);
		pt p3(x4, y4);
		rct r1(p2, p3);
		cout << "r1= ";
		r1.print(cout);
		cout << endl;
		// Renvoie vrai ssi le point argument est contenu dans le rectangle
		assert(r0.contains(p2));
		// Renvoie vrai ssi le rectangle argument est dans le rectangle 
		assert(r0.contains(r1));


		cout << "\nOperations : \n\n" << endl;
		// Opérations __________________________________________________________________
		// Renvoie un point aléatoire contenu dans le rectangle
		pt p4(r0.randPt()); 
		assert(r0.contains(p4));
		// Renvoie un rectangle aléatoire contenu dans le rectangle
		rct r2(r0.randRct());
		cout << "r2= ";
		r2.print(cout);
		cout << endl;
		assert(r0.contains(r2));

		// Translate (déplacement relatif) le rectangle de (dx, dy)
		rct r3(r0);
		cout << "r3= ";
		r3.print(cout);
		cout << endl;
		double dx = dRand(-10, 20);	double dy = dRand(-15, 5);
		r3.offset(dx, dy);
		cout << "r3= ";
		r3.print(cout);
		cout << endl;
		pt pC0(r3.getCenterPt());
		assert(EPSEQUAL(pC0.getX(), (x1+x2)/2+dx));
		assert(EPSEQUAL(pC0.getY(), (y1+y2)/2+dy));

		// Déformation du rectangle : la largeur est modifiée de px %, et la hauteur
		// de py %, mais sans déplacement du centre. L'argument px (resp. py) peut
		// être compris entre 0 et 1, ce qui correspond à une  réduction de largeur 
		// (resp. hauteur), ou bien supérieur à 1, ce qui correspond à une augmenta-
		// tion de largeur (resp. hauteur). Mais ils ne peuvent pas être négatifs.
		rct r4(r0);
		cout << "r4= ";
		r4.print(cout);
		cout << endl;
		double px = dRand(0,2); double py = dRand(0,2);
		r4.inflate(px, py);
		cout << "r4= ";
		r4.print(cout);
		cout << endl;
		if (px < 1)
			assert(EPSEQUAL(r4.getWidth(), fabs(x1-x2)*(1-px)));
		else
			assert(EPSEQUAL(r4.getWidth(), fabs(x1-x2)*(px-1)+fabs(x1-x2)));

		if (py < 1)
			assert(EPSEQUAL(r4.getHeight(), fabs(y1-y2)*(1-py)));
		else
			assert(EPSEQUAL(r4.getHeight(), fabs(y1-y2)*(py-1)+fabs(y1-y2)));

		double arret = 0.0;
	}
}