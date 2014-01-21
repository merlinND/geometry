//---------- Réalisation de la classe <Rectangle> (fichier Rectangle.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes
const std::string Rectangle::INITIALS = "R";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Rectangle::GetRepresentation ( )
{
	string representation = GetInitials() + " " + name + " ";
	representation += upperLeftCorner.GetRepresentation() + " ";
	representation += lowerRightCorner.GetRepresentation();
	return representation;
}

void Rectangle::Move (int dx, int dy)
{
	upperLeftCorner.x += dx;
	upperLeftCorner.y += dy;
	lowerRightCorner.x += dx;
	lowerRightCorner.y += dy;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Rectangle::Rectangle ( string myRectangle, Point uLC, Point lRC )
	: GeometricObject ( myRectangle, INITIALS ),
	  upperLeftCorner( uLC ), lowerRightCorner( lRC )
{
#ifdef MAP
	cout << "Appel au constructeur de <Rectangle>" << endl;
#endif

} //----- Fin de Rectangle

Rectangle::~Rectangle ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
