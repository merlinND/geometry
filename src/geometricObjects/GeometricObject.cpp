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

string GeometricObject::GetName ( )
{
	return name;
}
int GeometricObject::GetId ( )
{
	return objectId;
}
string const GeometricObject::GetInitials ( )
{
	return initials;
}

int GeometricObject::GetLastAppliedCommandId()
{
	return lastAppliedCommandId;
}
void GeometricObject::SetLastAppliedCommandId( int commandId )
{
	lastAppliedCommandId = commandId;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

GeometricObject::GeometricObject ( string theName, string theInitials )
	: name ( theName ), initials( theInitials )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <GeometricObject>" << endl;
#endif
	lastAppliedCommandId = 0;
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
