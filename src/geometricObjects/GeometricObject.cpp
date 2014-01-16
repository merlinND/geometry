//---------- Réalisation de la classe <GeometricObject> (fichier GeometricObject.cpp) -------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "GeometricObject.h"

//------------------------------------------------------------- Constantes
int GeometricObject::objectIdCounter = 0;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
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
	objectId = objectIdCounter;
	objectIdCounter++;
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
