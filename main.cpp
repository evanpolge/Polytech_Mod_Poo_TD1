// main.cpp : définit le point d'entrée pour l'application console.
//
#include "stdafx.h"
void testPt(void);
void testSgt(void);
void testRct(void);
void testFigure(void);

int main(void)
{
	// Initialisation du générateur aleatoire
	unsigned int rseed = unsigned(time(0)) % 10000;
	//rseed = 5975; 
	srand(rseed);

	// Affichage pour ré-utilisation éventuelle (pour retrouver une série précé-
   // dente afin de reproduire les circonstances exactes d'une erreur en cours
	// de correction)
	cerr << "rseed = " << rseed << "\n" << endl;

	// On teste les points
	//for (int k = 0; k<10; ++k)
	testPt();

	// On teste les rectangles
	//for (int k = 0; k < 10; ++k)
		testRct();

	// On teste les segments
	//for (int k = 0; k < 10; ++k)
		testSgt();

	// On teste les figures
	//for (int k = 0; k < 10; ++k)
		testFigure();

	return 0;
}




