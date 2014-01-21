//---------- Réalisation de la classe <Circle> (fichier Circle.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Circle.h"

//------------------------------------------------------------- Constantes
const string Circle::INITIALS = "C";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Circle::GetRepresentation ( )
{
	ostringstream os;
	os << GetInitials() + " " + name + " ";
	os << center.GetRepresentation() + " ";
	os << radius;
	return os.str();
}
void Circle::Move (long dx, long dy)
{
	center.x += dx;
	center.y += dy;
	return ;
}

//-------------------------------------------- Constructeurs - destructeur

Circle::Circle ( string myCircle, Point theCenter, long R )
	: GeometricObject ( myCircle, INITIALS ),
	  center ( theCenter ), radius ( R )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Circle>" << endl;
#endif

} //----- Fin de Circle

Circle::~Circle ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Circle>" << endl;
#endif
} //----- Fin de ~Circle

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
