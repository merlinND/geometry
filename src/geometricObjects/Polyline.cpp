//---------- Réalisation de la classe <Polyline> (fichier Polyline.cpp) --

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Polyline.h"

//------------------------------------------------------------- Constantes
const string Polyline::INITIALS = "PL";

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

string Polyline::GetRepresentation ( )
{
	
	string representation = GetInitials( ) + " " + name + " ";
	for ( int i = 0; i < (int) points.size( ); i++ )
	{
		representation += points[i].GetRepresentation( ) + " ";
	}
	return representation;
}

void Polyline::AddPoint ( Point extraPoint )
{
	points.push_back( extraPoint );
}

void Polyline::Move ( long dx, long dy )
{
	for ( int i = 0; i < (int) points.size( ); i++ )
	{
		points[i].x += dx;
		points[i].y += dy;
	}
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

Polyline::Polyline ( string name )
		: GeometricObject( name, INITIALS )
{
#ifdef MAP
	cout << "Appel au constructeur de <Polyline>" << endl;
#endif
} //----- Fin de Polyline

Polyline::~Polyline ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <Polyline>" << endl;
#endif
} //----- Fin de ~Polyline

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
