//-- Réalisation de la classe <CommandFactory> (fichier CommandFactory.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "CommandFactory.h"
#include "AllCommands.h"
//------------------------------------------------------------- Constantes
// Initializint static field
CommandFactory * CommandFactory::theInstance = NULL;

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

CommandFactory * CommandFactory::getInstance ( )
{
	if (NULL == CommandFactory::theInstance)
	{
		CommandFactory::theInstance = new CommandFactory;
	}
	else
	{
#ifdef MAP
	cout << "Accès à l'instance unique de <CommandFactory>" << endl;
#endif
	}
    return CommandFactory::theInstance;
}

Command & CommandFactory::getCommandFromText( const string text )
{
	Command * c = NULL;
	if ( "MOVE" == text )
	{
		c = new MoveCommand( );
	}
	// TODO: add support for all command types
	else
	{
		// TODO: error handling (command not found)
	}
	
	return *c;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

CommandFactory::~CommandFactory ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <CommandFactory>" << endl;
#endif
} //----- Fin de ~CommandFactory

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées

CommandFactory::CommandFactory ( )
{
#ifdef MAP
	cout << "Appel au constructeur de <CommandFactory>" << endl;
#endif
} //----- Fin de CommandFactory