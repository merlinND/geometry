//-- Réalisation de la classe <CommandInterpreter> (fichier CommandInterpreter.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
//------------------------------------------------------ Include personnel
#include "CommandInterpreter.h"
#include "AllCommands.h"
#include "../Controller.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

Command * CommandInterpreter::InterpretCommand ( istream & line )
{
	//----- Extract all we can from the input
	string token;
	vector<string> tokens;
	while ( line.good() && line.peek() != '\n' )
	{
		line >> token;
		tokens.push_back(token);
	}
	// Empty the last character (linefeed)
	line.get();
	line.clear();
	
	//----- Build a Command from this input
	// At any time, if anything is wrong, we just let the result pointer
	// to NULL, which indicates an error.
	Command * result = NULL;
	if ( tokens.empty() )
		return NULL;
	
	if ( "MOVE" == tokens[0] )
	{
		MoveCommand * mc = new MoveCommand( );
		// Parameters : target name and offset
		if ( tokens.size() == 4 )
		{
			if ( isNameUsedInDocument( tokens[1] ) )
			{
				mc->AddTarget(tokens[1]);
				if ( isValidPoint( tokens[2], tokens[3] ) )
				{
					Vector2D offset = makePointFromInput( tokens[2], tokens[3] );
					mc->SetOffset( offset );
					result = mc;
				}
			}
		}
	}
	// TODO: add support for all command types
	else if ( "LIST" == tokens[0] )
	{
		result = new ListCommand( );
	}
	else if ( "UNDO" == tokens[0] )
	{
		result = new UndoCommand( );
	}
	else if ( "REDO" == tokens[0] )
	{
		result = new RedoCommand( );
	}
	else if ( "EXIT" == tokens[0] )
	{
		result = new ExitCommand( );
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
	int x, y;
	stringstream ss( stringX + " " + stringY );
	valid = valid && ( ss >> x );
	valid = valid && ( ss >> y );
	
	return valid;
}

Point CommandInterpreter::makePointFromInput( string stringX, string stringY )
{
	int x, y;
	// Convert both strings to integers and return a new point
	stringstream ss( stringX + " " + stringY );
	ss >> x;
	ss >> y;
	return Point( x, y );
}
