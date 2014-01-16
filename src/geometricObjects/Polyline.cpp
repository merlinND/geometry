/*************************************************************************
                           Polyline  -  description
                             -------------------
    début                : Jan 13, 2014
    copyright            : (C) 2014 par rbrunat
*************************************************************************/

//---------- Réalisation de la classe <Polyline> (fichier Polyline.cpp) -------

#include <iostream>
using namespace std;
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


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
//olyline & Polyline::operator = ( const Polyline & unPolyline )
// Algorithme :
//
//{
//} //----- Fin de operator =


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

	for (int i = 0; i < (int) polyPoint.size(); i++)
	{
		points [i] = polyPoint [i];
	}

#ifdef MAP
    cout << "Appel au constructeur de <Polyline>" << endl;
#endif


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
