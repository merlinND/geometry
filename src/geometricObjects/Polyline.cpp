//---------- Réalisation de la classe <Polyline> (fichier Polyline.cpp) --


//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Polyline.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

string Polyline::GetRepresentation()
{
	ostringstream os;
	string temp = "";

	for (int i = 0; i < (int) points.size(); i++)
	{
		os << points[i].x << " " << points[i].y << " " ;
		temp += os.str();
	}
	string representation;
	representation = "PL " + name +os.str()+ temp;
	cout << representation;
	return representation;
}

void Polyline::AddPoint(Point extraPoint)
{
	points.push_back(extraPoint);
}

void Polyline::Move (int dx, int dy)
{
	for (int i = 0;  i < ( int ) points.size(); i++)
	{
		points[i].x += dx;
		points[i].y += dy;
	}
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
Polyline::Polyline ( string myPolyline, vector <Point> polyPoint)
	: GeometricObject ( myPolyline)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Polyline>" << endl;
#endif
	for (int i = 0; i < (int) polyPoint.size(); i++)
	{
		points.push_back( polyPoint [i] );
	}
} //----- Fin de Polyline


Polyline::~Polyline ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Polyline>" << endl;
#endif
} //----- Fin de ~Polyline


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
