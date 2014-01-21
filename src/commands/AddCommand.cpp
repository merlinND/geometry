//-- Réalisation de la classe <AddCommand> (fichier AddCommand.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "AddCommand.h"
#include "../Controller.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

string AddCommand::Execute ( )
{
	executionCounter++;
	Controller * controller = Controller::GetInstance();
	// For each object to add
	for ( IdSet::iterator it = targets.begin();
		 it != targets.end(); ++it )
	{
		controller->AddIdToDocument( *it );
	}
	return STATUS_OK;
}
string AddCommand::Undo ( )
{
	executionCounter++;
	Controller * controller = Controller::GetInstance();
	// For each object that we had added
	for ( IdSet::iterator it = targets.begin();
		 it != targets.end(); ++it )
	{
		controller->RemoveObjectFromDocument( *it );
	}
	return STATUS_OK;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

AddCommand::AddCommand ( )
{
#ifdef MAP
	cout << "Appel au constructeur de <AddCommand>" << endl;
#endif
} //----- Fin de AddCommand 

AddCommand::~AddCommand ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <AddCommand>" << endl;
#endif
} //----- Fin de ~AddCommand

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées
