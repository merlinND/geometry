//-- Réalisation de la classe <DeleteCommand> (fichier DeleteCommand.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "DeleteCommand.h"
#include "../Controller.h"
#include "../geometricObjects/Agregate.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

void DeleteCommand::AddTarget( int targetId )
{
	targets.insert( targetId );
	IdSet emptySet;
	parentAgregates.push_back( emptySet );
}

string DeleteCommand::Execute ( )
{
	executionCounter++;
	
	Controller * controller = Controller::GetInstance();
	IdSet allAgregates = controller->GetAllAgregatesInDocument();
	
	vector<IdSet>::iterator parentsIterator = parentAgregates.begin();
	// For each object to delete
	for ( IdSet::iterator it = targets.begin();
		 it != targets.end(); ++it )
	{
		// Remove it from the document
		controller->RemoveObjectFromDocument( *it );
		
		// Find all agregates containing the deleted object
		// in order to remember them
		Agregate * currentAgregate;
		for ( IdSet::iterator jt = allAgregates.begin();
			 jt != allAgregates.end(); ++jt )
		{
			currentAgregate = (Agregate *) controller->GetObjectById( *jt );
			if ( currentAgregate->Contains( *it ) )
			{
				currentAgregate->RemoveComponent( *it );
				parentsIterator->insert( *jt );
			}
		}
		parentsIterator++;
	}
	return STATUS_OK;
}
string DeleteCommand::Undo ( )
{
	Controller * controller = Controller::GetInstance();
	
	vector<IdSet>::iterator agregatesIterator = parentAgregates.begin();
	// For each object that was deleted
	// (and its corresponding parent agregates)
	for ( IdSet::iterator it = targets.begin();
		 it != targets.end(); ++it )
	{
		// Add it back to the document
		controller->AddObjectBackInDocument( *it );
		
		// And add it back in all agregates that it used
		// to be part of
		Agregate * currentAgregate;
		for ( IdSet::iterator jt = agregatesIterator->begin();
			 jt != agregatesIterator->end(); ++jt )
		{
			currentAgregate = (Agregate *) controller->GetObjectById( *jt );
			currentAgregate->AddComponent( *it );
		}
		
		agregatesIterator++;
	}
	
	return STATUS_OK;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

DeleteCommand::DeleteCommand ( )
{
#ifdef MAP
	cout << "Appel au constructeur de <DeleteCommand>" << endl;
#endif
} //----- Fin de DeleteCommand 

DeleteCommand::~DeleteCommand ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <DeleteCommand>" << endl;
#endif
} //----- Fin de ~DeleteCommand

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées
