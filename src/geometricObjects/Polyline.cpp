/*************************************************************************
                           Polyline  -  description
                             -------------------
    début                : Jan 13, 2014
    copyright            : (C) 2014 par rbrunat
*************************************************************************/

//---------- Réalisation de la classe <Polyline> (fichier Polyline.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Polyline.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Polyline::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Polyline::GetRepresentation()
{
	ostringstream os;
	for (int i = 0; ( int ) i < points.size(); i++)
	{
		os << points[i].x << " " << points[i].y << " " ;
	}
		os << name << " " << os << endl;
		string representation;
		representation = "PL " + os.str( );
		cout << representation;
		return representation;

}

//------------------------------------------------- Surcharge d'opérateurs
Polyline & Polyline::operator = ( const Polyline & unPolyline )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*Polyline::Polyline ( const Polyline & unPolyline  )
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de copie de <Polyline>" << endl;
#endif
} //----- Fin de Polyline (constructeur de copie)
*/

Polyline::Polyline ( string myPolyline, vector <Point> polyPoint) : GeometricObject ( myPolyline)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Polyline>" << endl;
#endif

	for (int i = 0; i < (int) polyPoint.size(); i++)
	{
		points [i] = polyPoint [i];
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
