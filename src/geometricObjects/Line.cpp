//---------- Réalisation de la classe <Line> (fichier Line.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Line.h"

//------------------------------------------------------------- Constantes
const string Line::INITIALS = "L";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Line::GetRepresentation ( )
{
	return GetInitials( ) + " " + name + " " + first.GetRepresentation( ) + " "
			+ last.GetRepresentation( );
}

void Line::Move ( long dx, long dy )
{
	first.x += dx;
	first.y += dy;
	last.x += dx;
	last.y += dy;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Line::Line ( string myLine, Point firstPoint, Point lastPoint )
		: GeometricObject( myLine, INITIALS ), first( firstPoint ),
			last( lastPoint )
{
#ifdef MAP
	cout << "Appel au constructeur de <Line>" << endl;
#endif

} //----- Fin de Line

Line::~Line ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <Line>" << endl;
#endif
} //----- Fin de ~Line

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
