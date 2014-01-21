//-- Réalisation de la classe <CommandInterpreter> (fichier CommandInterpreter.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
//------------------------------------------------------ Include personnel
#include "CommandInterpreter.h"
#include "AllCommands.h"
#include "../Controller.h"
#include "SaveCommand.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

Command * CommandInterpreter::InterpretCommand ( istream & line )
{
	//----- Extract all we can from one line of the input
	string token;
	vector<string> tokens;
	while ( line && line.peek() != '\n' )
	{
		line >> token;
		if ( token.length() > 0 )
		{
			tokens.push_back(token);
		}
	}
	// Empty the last character (linefeed)
	line.get();
	
	// Ignore empty input or comments (line starting with #)
	if ( tokens.empty() || tokens[0][0] == '#')
		return new NoneCommand();
	
	//----- Build a Command from this input
	// At any time, if anything is wrong, we just let the result pointer
	// to NULL, which indicates an error.
	Controller * controller = Controller::GetInstance();
	Command * result = NULL;
	
	// We allow the commands to be typed in lowercase
	string command = tokens[0];
	transform(command.begin(), command.end(), command.begin(),::toupper);
	
	if ( "MOVE" == command )
	{
		MoveCommand * mc = new MoveCommand( );
		// Parameters: target name and offset
		if ( tokens.size() == 4 )
		{
			// Find the id corresponding to this name (in the current document)
			int targetId = controller->GetIdByName( tokens[1] );
			if ( targetId != Controller::NOT_FOUND )
			{
				mc->AddTarget( targetId );
				
				if ( isValidPoint( tokens[2], tokens[3] ) )
				{
					Vector2D offset = makePointFromInput( tokens[2], tokens[3] );
					mc->SetOffset( offset );
					result = mc;
				}
			}
		}
	}
	else if ( "DELETE" == command )
	{
		DeleteCommand * dc = new DeleteCommand( );
		// Parameters: a list of target names (at least one)
		if ( tokens.size() >= 2 )
		{
			// Find the id corresponding each name (in the current document)
			bool valid = true;
			for ( int i = 1; i < tokens.size(); ++i )
			{
				int targetId = controller->GetIdByName( tokens[1] );
				if ( targetId != Controller::NOT_FOUND )
				{
					dc->AddTarget( targetId );
				}
				else
				{
					valid = false;
				}
			}
			// All given names must exist in the document, otherwise we do
			// not delete *any* of the given names
			if ( valid )
			{
				result = dc;
			}
		}
	}
	else if ( "CLEAR" == command )
	{
		result = new ClearCommand( );
	}
	else if ( "SAVE" == command )
	{
		// Parameter: a path to the file
		if ( tokens.size() == 2 )
		{
			SaveCommand * sc = new SaveCommand ( tokens[1] );
			// Check that this path is indeed writable
			if ( sc->Good() )
			{
				result = sc;
			}
		}
	}
	else if ( "LOAD" == command )
	{
		// Parameter: a path to the file
		if ( tokens.size() == 2 )
		{
			LoadCommand * lc = new LoadCommand ( tokens[1] );
			// Check that this path is indeed readable
			if ( lc->Good() )
			{
				result = lc;
			}
		}
	}
	// All commands with no parameters
	else if ( tokens.size() == 1 )
	{
		if ( "LIST" == command )
		{
			result = new ListCommand( );
		}
		else if ( "UNDO" == command )
		{
			result = new UndoCommand( );
		}
		else if ( "REDO" == command )
		{
			result = new RedoCommand( );
		}
		else if ( "EXIT" == command )
		{
			result = new ExitCommand( );
		}
	}
	
	return result;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées

bool CommandInterpreter::isNameUsedInDocument( string text )
{
	return Controller::GetInstance()->IsNameUsedInDocument( text );
}

bool CommandInterpreter::isValidName( string text )
{
	bool valid = true;
	valid = valid && ( text.length() > 0 ); // At least one character
	valid = valid && ( text.find(' ') == string::npos ); // No space
	// TODO : add other constraints
	// TODO : check that name is unique !
	valid = valid && !isNameUsedInDocument( text );
	return valid;
}

bool CommandInterpreter::isValidPoint( string stringX, string stringY )
{
	bool valid = true;
	valid = valid && ( stringY.length() > 0 ) && ( stringY.length() > 0 );
	
	// Try to convert both strings to integers
	int x = 0, y = 0;
	stringstream ss( stringX + " " + stringY );
	valid = valid && ( ss >> x );
	valid = valid && ( ss >> y );
	
	return valid;
}

Point CommandInterpreter::makePointFromInput( string stringX, string stringY )
{
	int x, y;
	// Convert both strings to integers and return a new point
	// TODO : support for negative integers
	stringstream ss( stringX + " " + stringY );
	ss >> x;
	ss >> y;
	return Point( x, y );
}
