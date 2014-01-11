/*

 Agregate  -  description
 -------------------
 début                : 6 janv. 2014
 copyright            : (C) 2014 par rbrunat
 *************************************************************************/

//---------- Réalisation de la classe <Agregate>  Agregate  -  description

//---------- Réalisation de la classe <Agregate> (fichier Agregate.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>
//------------------------------------------------------ Include personnel
#include "Agregate.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Agregate::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Agregate::GetRepresentation ( )
{
	ostringstream os;

		string representation;

		return representation;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Agregate::Agregate ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Agregate>" << endl;
#endif

} //----- Fin de Agregate

Agregate::~Agregate ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Agregate>" << endl;
#endif
} //----- Fin de ~Agregate

//------------------------------------------------------------------ PRIVE

