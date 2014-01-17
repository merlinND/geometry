//-- Réalisation de la classe <Controller> (fichier Controller.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Controller.h"

//------------------------------------------------------------- Constantes
// Initializing static field
Controller * Controller::theInstance = NULL;

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

Controller * Controller::GetInstance( )
{
	if ( NULL == theInstance )
	{
		theInstance = new Controller;
	}
	else
	{
#ifdef MAP
		cout << "Accès à l'unique instance de <Controller>" << endl;
#endif
	}
	return theInstance;
} // ----- End getInstance

string Controller::ProcessCommand ( Command * command )
{
	command->Execute();
	
	if ( command->IsHistorizable() )
	{
		history.AddCommand( (HistorizableCommand *) command );
	}
	
	return "OK";
} // ----- End processCommand

void Controller::Undo()
{
	history.Undo();
}
void Controller::Redo()
{
	history.Redo();
}

GeometricObject * Controller::GetObjectById ( int idToFind )
{
	GeometricMap::iterator it = allObjects.find( idToFind );
	if ( it != allObjects.end() )
	{
		return it->second;
	}
	else
	{
		return NULL;
	}
} //----- End GetObjectByName

string Controller::GetNameById ( int idToFind )
{
	GeometricMap::iterator found = allObjects.find( idToFind );
	if ( found != allObjects.end() )
	{
		return found->second->GetName();
	}
	else
	{
		return NULL;
	}
} //----- End GetNameById

int Controller::GetIdByName( string name )
{
	IdSet components = model.GetComponents();
	IdSet::iterator it = components.end();
	GeometricObject * currentObject;
	while ( it != components.end() )
	{
		currentObject = GetObjectById( *it );
		if ( currentObject->GetName() == name )
		{
			return *it;
		}
		++it;
	}
	return NULL;
} //----- End GetNameById


bool Controller::IsNameUsedInDocument( string name )
{
	return true;
	// TODO : use the agregate's method to return the result
	//return model.HasObjectWithName( name );
}

IdSet Controller::ClearDocument ( )
{
	IdSet removedIds = model.GetComponents();
	model.RemoveAllComponents();
	return removedIds;
}

bool Controller::ShouldExit()
{
	return exitFlag;
}
void Controller::Exit()
{
	exitFlag = true;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

Controller::~Controller ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <Controller>" << endl;
#endif
} //----- Fin de ~Controller

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées

Controller::Controller ( ) : model( "__document__" ), exitFlag( false )
{
#ifdef MAP
	cout << "Appel au constructeur de <Controller>" << endl;
#endif
} //----- Fin de Controller
