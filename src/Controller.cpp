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

Controller * Controller::getInstance ( )
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

void Controller::undo()
{
	history.undo();
}
void Controller::redo()
{
	history.redo();
}

bool Controller::shouldExit()
{
	return exitFlag;
}
void Controller::exit()
{
	exitFlag = true;
}

string Controller::processCommand ( Command * command )
{
	command->execute();
	
	if ( command->isHistorizable() )
	{
		history.addCommand( (HistorizableCommand *) command );
	}
	
	return "OK";
} // ----- End processCommand

GeometricObject * Controller::getObjectByName ( string name )
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
