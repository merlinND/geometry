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

void Controller::Undo()
{
	history.Undo();
}
void Controller::Redo()
{
	history.Redo();
}

bool Controller::ShouldExit()
{
	return exitFlag;
}
void Controller::Exit()
{
	exitFlag = true;
}

string Controller::ProcessCommand ( Command * command )
{
	command->Execute();
	
	if ( command->IsHistorizable() )
	{
		history.AddCommand( (HistorizableCommand *) command );
	}
	
	// TODO : modulate input (do not input anything on empty lines)
	return "OK";
} // ----- End processCommand

GeometricObject * Controller::GetObjectByName ( string name )
{
	GeometricMap::iterator it = allObjects.find( name );
	if ( it != allObjects.end() )
	{
		return it->second;
	}
	else
	{
		return NULL;
	}
} // ----- End getObjectByName

bool Controller::IsNameUsedInDocument( string name )
{
	return true;
	// TODO : use the agregate's method to return the result
	//return model.HasObjectWithName( name );
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

Controller::Controller ( ) : exitFlag( false )
{
#ifdef MAP
	cout << "Appel au constructeur de <Controller>" << endl;
#endif
} //----- Fin de Controller
