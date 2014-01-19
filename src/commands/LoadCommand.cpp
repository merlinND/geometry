//-- Réalisation de la classe <LoadCommand> (fichier LoadCommand.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <istream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "LoadCommand.h"
#include "HistorizableCommand.h"
#include "CommandInterpreter.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

string LoadCommand::Execute ( )
{
	// We must execute succesfully *all* commands, otherwise we just
	// cancel the whole thing
	string status = STATUS_OK;
	
	while ( commandsToDo.size() > 0 && status == STATUS_OK )
	{
		Command * currentCommand = commandsToDo.top();
		status = currentCommand->Execute();
		// We consider all OK statuses to be equivalent
		if ( status == STATUS_OK_SILENT || status == STATUS_OK )
		{
			status = STATUS_OK;
			commandsToDo.pop();
			commandsDone.push( currentCommand );
		}
	}
	
	// If we see as much as one error, we need to undo everything
	if ( status == STATUS_ERROR )
	{
		while ( commandsDone.size() > 0 )
		{
			Command * currentCommand = commandsDone.top();
			if ( currentCommand->IsHistorizable() )
			{
				((HistorizableCommand *)currentCommand)->Undo();
			}
			commandsDone.pop();
			commandsToDo.push( currentCommand );
		}
	}
	
	return status;
}
string LoadCommand::Undo ( )
{
	// If we were able to Execute this LOAD command one, we should
	// be able to undo it whithout trouble.
	// But just in case we apply the same safety mechanism.
	
	// We must execute succesfully *all* commands, otherwise we just
	// cancel the whole thing
	string status = STATUS_OK;
	
	while ( commandsDone.size() > 0 && status == STATUS_OK )
	{
		Command * currentCommand = commandsDone.top();
		if ( currentCommand->IsHistorizable() )
		{
			((HistorizableCommand *)currentCommand)->Undo();
		}
		// We consider all OK statuses to be equivalent
		if ( status == STATUS_OK_SILENT || status == STATUS_OK )
		{
			status = STATUS_OK;
			commandsDone.pop();
			commandsToDo.push( currentCommand );
		}
	}
	
	// If we see as much as one error, we need to undo everything
	if ( status == STATUS_ERROR )
	{
		while ( commandsToDo.size() > 0 )
		{
			Command * currentCommand = commandsToDo.top();
			currentCommand->Execute();
			commandsToDo.pop();
			commandsDone.push( currentCommand );
		}
	}
	
	return status;
}

bool LoadCommand::Good ( )
{
	return !loadFailed;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

LoadCommand::LoadCommand ( std::string path )
	: input ( path.c_str() )
{
#ifdef MAP
	cout << "Appel au constructeur de <LoadCommand>" << endl;
#endif
	
	loadFailed = false;
	if ( input.good() )
	{
		loadCommandsFromInput( input );
	}
	else
	{
		loadFailed = true;
	}
	
} //----- Fin de LoadCommand 

LoadCommand::~LoadCommand ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <LoadCommand>" << endl;
#endif
	
	Command * current;
	while ( commandsToDo.size() > 0 )
	{
		current = commandsToDo.top();
		delete current;
		commandsToDo.pop();
	}
	while ( commandsDone.size() > 0 )
	{
		current = commandsDone.top();
		delete current;
		commandsDone.pop();
	}
	
} //----- Fin de ~LoadCommand

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées
void LoadCommand::loadCommandsFromInput ( istream & input )
{
	Command * loadedCommand;
	AnyCommandStack wrongOrderStack;
	while ( !loadFailed  && input ) // && input.peek() != input.eof()
	{
		loadedCommand = CommandInterpreter::InterpretCommand( input );
		if ( loadedCommand == NULL )
		{
			loadFailed = true;
		}
		else
		{
			wrongOrderStack.push( loadedCommand );
		}
	}
	
	// If everything went well, we put the Commands back into the right order
	while ( wrongOrderStack.size() > 0 )
	{
		commandsToDo.push ( wrongOrderStack.top() );
		wrongOrderStack.pop();
	}
}
