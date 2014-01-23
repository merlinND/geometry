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
	string status;
	if ( !loadPerformed )
	{
		// First run of Execute: we load the commands from the input stream
		input = new ifstream( path.c_str( ) );
		status = loadAndExecute( input );
		input->close( );
		if ( status == STATUS_OK )
		{
			loadPerformed = true;
		}
	}
	else
	{
		// We must execute succesfully *all* commands, otherwise we just
		// cancel the whole thing
		string status = STATUS_OK;
		
		while ( commandsToDo.size( ) > 0 && status == STATUS_OK )
		{
			Command * currentCommand = commandsToDo.top( );
			status = currentCommand->Execute( );
			// We consider all OK statuses to be equivalent
			if ( status == STATUS_OK_SILENT || status == STATUS_OK )
			{
				status = STATUS_OK;
				commandsToDo.pop( );
				commandsDone.push( currentCommand );
			}
		}
		
		// If we see as much as one error, we need to undo everything
		if ( status == STATUS_ERROR )
		{
			cancelEverything( true );
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
	
	while ( commandsDone.size( ) > 0 && status == STATUS_OK )
	{
		Command * currentCommand = commandsDone.top( );
		if ( currentCommand->IsHistorizable( ) )
		{
			( (HistorizableCommand *) currentCommand )->Undo( );
		}
		// We consider all OK statuses to be equivalent
		if ( status == STATUS_OK_SILENT || status == STATUS_OK )
		{
			status = STATUS_OK;
			commandsDone.pop( );
			commandsToDo.push( currentCommand );
		}
	}
	
	// If we see as much as one error, we need to undo everything
	if ( status == STATUS_ERROR )
	{
		cancelEverything( false );
	}
	
	return status;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

LoadCommand::LoadCommand ( std::string thePath )
		: path( thePath ), input( NULL ), loadPerformed( false )
{
#ifdef MAP
	cout << "Appel au constructeur de <LoadCommand>" << endl;
#endif
} //----- Fin de LoadCommand 

LoadCommand::~LoadCommand ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <LoadCommand>" << endl;
#endif
	
	Command * current;
	while ( commandsToDo.size( ) > 0 )
	{
		current = commandsToDo.top( );
		delete current;
		commandsToDo.pop( );
	}
	while ( commandsDone.size( ) > 0 )
	{
		current = commandsDone.top( );
		delete current;
		commandsDone.pop( );
	}
	
} //----- Fin de ~LoadCommand

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées
string LoadCommand::loadAndExecute ( istream * input )
{
	string status = STATUS_OK;
	while ( status != STATUS_ERROR && input->good( ) )
	{
		Command * loadedCommand = CommandInterpreter::InterpretCommand(
				*input );
		if ( loadedCommand == NULL )
		{
			status = STATUS_ERROR;
		}
		else
		{
			status = loadedCommand->Execute( );
			// We consider all OK statuses to be equivalent
			if ( status == STATUS_OK_SILENT || status == STATUS_OK )
			{
				status = STATUS_OK;
				commandsDone.push( loadedCommand );
			}
			else
			{
				delete loadedCommand;
			}
		}
	}
	
	// If anything went wrong, we must rewind
	if ( status == STATUS_ERROR )
	{
		cancelEverything( true );
	}
	
	return status;
}

void LoadCommand::cancelEverything ( bool undo )
{
	// We were Executing commands but something failed,
	// so now we undo everything.
	if ( undo )
	{
		while ( commandsDone.size( ) > 0 )
		{
			Command * currentCommand = commandsDone.top( );
			if ( currentCommand->IsHistorizable( ) )
			{
				( (HistorizableCommand *) currentCommand )->Undo( );
			}
			commandsDone.pop( );
			commandsToDo.push( currentCommand );
		}
	}
	// We were Undoing commands but something failed,
	// so now we redo everything we had undone
	else
	{
		while ( commandsToDo.size( ) > 0 )
		{
			Command * currentCommand = commandsToDo.top( );
			currentCommand->Execute( );
			commandsToDo.pop( );
			commandsDone.push( currentCommand );
		}
	}
}
