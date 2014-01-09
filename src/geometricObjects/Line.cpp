/*************************************************************************
 Line  -  description
 -------------------
 début                : 9 janv. 2014
 copyright            : (C) 2014 par rbrunat
 *************************************************************************/

//---------- Réalisation de la classe <Line> (fichier Line.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;Line
#include <iostream>
#include <sstream>
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
	ostringstream os;
		os << first.x << " " << first.y << " " << last.x << " " << last.y << endl;
		string representation;
		representation = "L " + os.str( );
		cout << representation;
		return representation;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Line::Line ( Point firstPoint, Point lastPoint )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Line>" << endl;
#endif
	first = firstPoint;
	last = lastPoint;
} //----- Fin de Line

Line::~Line ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Line>" << endl;
#endifL
} //----- Fin de ~Line

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
