//-- Réalisation de la classe <CommandInterpreter> (fichier CommandInterpreter.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "CommandInterpreter.h"
#include "AllCommands.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

Command * CommandInterpreter::interpretCommand ( string line )
{
	// TODO: actual command interpreting (parameters, etc)
	return getCommandFromText( line );
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées

Command * CommandInterpreter::getCommandFromText( const string text )
{
	if ( "MOVE" == text )
	{
		return new MoveCommand( );
	}
	else if ( "LIST" == text )
	{
		return new ListCommand( );
	}
	else if ( "UNDO" == text )
	{
		return new UndoCommand( );
	}
	else if ( "REDO" == text )
	{
		return new RedoCommand( );
	}
	else if ( "EXIT" == text )
	{
		return new ExitCommand( );
	}
	// TODO: add support for all command types
	else
	{
		// TODO: error handling (command not found)
		return NULL;
	}
}