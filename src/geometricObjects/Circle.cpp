//---------- Réalisation de la classe <Circle> (fichier Circle.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Circle.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Circle::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Circle::GetRepresentation ( )
{
	ostringstream os;
	os << center.x << " " << center.y << " " << rayon << endl;
	string representation;
	representation = "C " + os.str( );
	cout << representation;
	return representation;
}

//-------------------------------------------- Constructeurs - destructeur

Circle::Circle ( Point centre, int R )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Circle>" << endl;
#endif
	center = centre;
	rayon = R;
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
