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
}

string Controller::processCommand ( Command & command )
{
	command.execute();
	
	if ( command.isHistorizable() )
	{
		history.addCommand( command );
	}
	
	return "OK";
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

Controller::Controller ( )
{
#ifdef MAP
	cout << "Appel au constructeur de <Controller>" << endl;
#endif
} //----- Fin de Controller
