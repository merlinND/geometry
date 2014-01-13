//---------- Réalisation de la classe <Line> (fichier Line.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système

#include <iostream>
#include <sstream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Line.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Line::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Line::GetRepresentation ( )
{
	ostringstream os;
	os << name << " " << first.x << " " << first.y << " " << last.x << " " << last.y << endl;
	string representation;
	representation = "L " + os.str( );
	cout << representation;
	return representation;
}

void Line::Move (int dx, int dy)
{
	first.x += dx;
	first.y += dy;
	last.x += dx;
	last.y += dy;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Line::Line ( string myLine, Point firstPoint, Point lastPoint )
	: GeometricObject ( myLine ), first ( firstPoint ), last( lastPoint )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Line>" << endl;
#endif

} //----- Fin de Line

Line::~Line ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Line>" << endl;
#endif
} //----- Fin de ~Line

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
