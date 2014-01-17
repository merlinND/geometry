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
	return "L " + name + " " + first.GetRepresentation()
			+ " " + last.GetRepresentation();
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
