//---------- Réalisation de la classe <GeometricObject> (fichier GeometricObject.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "GeometricObject.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type GeometricObject::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

GeometricObject::GeometricObject ( string myObject )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <GeometricObject>" << endl;
#endif
	lastAppliedCommandId = 0;
	name = myObject;
} //----- Fin de GeometricObject

GeometricObject::~GeometricObject ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <GeometricObject>" << endl;
#endif
} //----- Fin de ~GeometricObject

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
