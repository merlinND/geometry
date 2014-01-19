//---------- Réalisation de la classe <SaveCommand> (fichier SaveCommand.cpp) ----
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "SaveCommand.h"
#include "../Controller.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
string SaveCommand::Execute ( )
{
	Controller * controller = Controller::GetInstance();
	// This set is naturally sorted by GeometricObject id. Since the ids
	// increment linearly, it is a guarantee that each object necessary
	// to the creation of a future Agregate object will indeed be present
	// before any other reference is made to it.
	IdSet ids = controller->GetAllIdsInDocument();
	GeometricObject * currentObject;
	for ( IdSet::iterator it = ids.begin();
		 it != ids.end(); ++it )
	{
		currentObject = controller->GetObjectById( *it );
		outputStream << currentObject->GetRepresentation();
		outputStream << endl;
	}
	
	outputStream.close();
	return STATUS_OK;
}

bool SaveCommand::Good ( )
{
	return outputStream.good();
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
SaveCommand::SaveCommand ( string const path )
	: outputStream( path, ios::out|ios::trunc )
{
#ifdef MAP
	cout << "Appel au constructeur de <SaveCommand>" << endl;
#endif
	
} //----- Fin de SaveCommand

SaveCommand::~SaveCommand ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <SaveCommand>" << endl;
#endif
} //----- Fin de ~SaveCommand

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
