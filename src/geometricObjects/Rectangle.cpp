//---------- Réalisation de la classe <Rectangle> (fichier Rectangle.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Rectangle::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Rectangle::GetRepresentation ( )
{
	ostringstream os;
		os << name << " " << upperLeftCorner.x << " " << upperLeftCorner.y << " " << lowerRightCorner.x << " " << lowerRightCorner.y << endl;
		string representation;
		representation = "R " + os.str( );
		cout << representation;
		return representation;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Rectangle::Rectangle ( string myRectangle, Point uLC, Point lRC )
	: GeometricObject ( myRectangle ),upperLeftCorner( uLC ), lowerRightCorner( lRC )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle

Rectangle::~Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
