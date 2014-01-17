//---------- Réalisation de la classe <Rectangle> (fichier Rectangle.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
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
	string representation = "R " + name + " ";
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
