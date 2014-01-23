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
#include "../geometricObjects/AllGeometricObjects.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

Command * CommandInterpreter::InterpretCommand ( istream & line )
{
	//----- Extract all we can from one line of the input
	string token;
	vector<string> tokens;
	while ( line && line.peek( ) != '\n' )
	{
		line >> token;
		if ( token.length( ) > 0 )
		{
			tokens.push_back( token );
		}
	}
	// Empty the last character (linefeed)
	line.get( );
	
	// Ignore empty input or comments (line starting with #)
	if ( tokens.empty( ) || tokens[0][0] == '#' )
		return new NoneCommand( );
	
	//----- Build a Command from this input
	// At any time, if anything is wrong, we just let the result pointer
	// to NULL, which indicates an error.
	Controller * controller = Controller::GetInstance( );
	Command * result = NULL;
	
	// We allow the commands to be typed in lowercase
	string command = tokens[0];
	transform( command.begin( ), command.end( ), command.begin( ), ::toupper );
	
	if ( Circle::INITIALS == command )
	{
		// Parameters: target name, circle center and radius
		if ( tokens.size( ) == 5 )
		{
			if ( isValidName( tokens[1] )
					&& isValidPoint( tokens[2], tokens[3] )
					&& isValidInteger( tokens[4] ) )
			{
				string name = tokens[1];
				Point center = makePointFromInput( tokens[2], tokens[3] );
				long radius = makeNumberFromInput( tokens[4] );
				if ( radius >= 0 )
				{
					Circle * circle = controller->CreateCircle( name, center,
							radius );
					AddCommand * ac = new AddCommand( );
					ac->AddTarget( circle->GetId( ) );
					result = ac;
				}
			}
		}
	}
	else if ( Line::INITIALS == command )
	{
		// Parameters: target name and the two extreme points
		if ( tokens.size( ) == 6 )
		{
			if ( isValidName( tokens[1] )
					&& isValidPoint( tokens[2], tokens[3] )
					&& isValidPoint( tokens[4], tokens[5] ) )
			{
				string name = tokens[1];
				Point begin = makePointFromInput( tokens[2], tokens[3] );
				Point end = makePointFromInput( tokens[4], tokens[5] );
				Line * line = controller->CreateLine( name, begin, end );
				AddCommand * ac = new AddCommand( );
				ac->AddTarget( line->GetId( ) );
				result = ac;
			}
		}
	}
	else if ( Polyline::INITIALS == command )
	{
		// Parameters: target name and a list of points (at least one)
		if ( tokens.size( ) >= 4 && tokens.size( ) % 2 == 0 )
		{
			bool valid = isValidName( tokens[1] );
			vector<Point> points;
			int i = 2;
			while ( valid && i < (int) tokens.size( ) - 1 )
			{
				valid = valid && isValidPoint( tokens[i], tokens[i + 1] );
				if ( valid )
				{
					points.push_back(
							makePointFromInput( tokens[i], tokens[i + 1] ) );
				}
				i += 2;
			}
			// If every point was a valid point
			if ( valid )
			{
				Polyline * polyline = controller->CreatePolyline( tokens[1] );
				for ( int i = 0; i < (int) points.size( ); ++i )
				{
					polyline->AddPoint( points.at( i ) );
				}
				AddCommand * ac = new AddCommand( );
				ac->AddTarget( polyline->GetId( ) );
				result = ac;
			}
		}
	}
	else if ( Rectangle::INITIALS == command )
	{
		// Parameters: target name and two corner points
		if ( tokens.size( ) == 6 )
		{
			if ( isValidName( tokens[1] )
					&& isValidPoint( tokens[2], tokens[3] )
					&& isValidPoint( tokens[4], tokens[5] ) )
			{
				string name = tokens[1];
				Point ulc = makePointFromInput( tokens[2], tokens[3] );
				Point lrc = makePointFromInput( tokens[4], tokens[5] );
				Rectangle * rectangle = controller->CreateRectangle( name, ulc,
						lrc );
				AddCommand * ac = new AddCommand( );
				ac->AddTarget( rectangle->GetId( ) );
				result = ac;
			}
		}
	}
	else if ( Agregate::INITIALS == command )
	{
		// Parameters: target name and a list of object names
		if ( tokens.size( ) >= 3 )
		{
			bool valid = isValidName( tokens[1] );
			IdSet componentsId;
			int i = 2;
			while ( valid && i < (int) tokens.size( ) )
			{
				TId correspondingId = controller->GetIdByName( tokens[i] );
				valid = valid && ( correspondingId != Controller::NOT_FOUND );
				if ( valid )
				{
					componentsId.insert( correspondingId );
				}
				++i;
			}
			// If every name given corresponds to an object in the document
			if ( valid )
			{
				Agregate * agregate = controller->CreateAgregate( tokens[1] );
				for ( IdSet::iterator it = componentsId.begin( );
						it != componentsId.end( ); ++it )
				{
					agregate->AddComponent( *it );
				}
				AddCommand * ac = new AddCommand( );
				ac->AddTarget( agregate->GetId( ) );
				result = ac;
			}
		}
	}
	else if ( "MOVE" == command )
	{
		// Parameters: target name and offset
		if ( tokens.size( ) == 4 )
		{
			// Find the id corresponding to this name (in the current document)
			TId targetId = controller->GetIdByName( tokens[1] );
			if ( targetId != Controller::NOT_FOUND
					&& isValidPoint( tokens[2], tokens[3] ) )
			{
				Vector2D offset = makePointFromInput( tokens[2], tokens[3] );
				
				MoveCommand * mc = new MoveCommand( );
				mc->AddTarget( targetId );
				mc->SetOffset( offset );
				result = mc;
			}
		}
	}
	else if ( "DELETE" == command )
	{
		// Parameters: a list of target names (at least one)
		if ( tokens.size( ) >= 2 )
		{
			// Find the id corresponding each name (in the current document)
			bool valid = true;
			DeleteCommand * dc = new DeleteCommand( );
			int i = 1;
			while ( valid && i < (int) tokens.size( ) )
			{
				TId targetId = controller->GetIdByName( tokens[i] );
				if ( targetId != Controller::NOT_FOUND )
				{
					dc->AddTarget( targetId );
				}
				else
				{
					valid = false;
					delete dc;
				}
				++i;
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
		if ( tokens.size( ) == 2 )
		{
			SaveCommand * sc = new SaveCommand( tokens[1] );
			// Check that this path is indeed writable
			if ( sc->Good( ) )
			{
				result = sc;
			}
			else
			{
				delete sc;
			}
		}
	}
	else if ( "LOAD" == command )
	{
		// Parameter: a path to the file
		if ( tokens.size( ) == 2 )
		{
			// Unfortunately, we can't check much before the actual
			// execution of the command
			result = new LoadCommand( tokens[1] );
		}
	}
	// All commands with no parameters
	else if ( tokens.size( ) == 1 )
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

bool CommandInterpreter::isNameUsedInDocument ( string text )
{
	Controller * controller = Controller::GetInstance( );
	return controller->IsNameUsedInDocument( text );
}

bool CommandInterpreter::isValidName ( string text )
{
	bool valid = true;
	valid = valid && ( text.length( ) > 0 ); // At least one character
	valid = valid && ( text.find( ' ' ) == string::npos ); // No space
	// TODO : add other constraints
	valid = valid && !isNameUsedInDocument( text );
	return valid;
}

bool CommandInterpreter::isValidInteger ( string text )
{
	long x = 0;
	stringstream ss( text );
	return ( text.length( ) > 0 ) && ( ss >> x );
}

bool CommandInterpreter::isValidPoint ( string stringX, string stringY )
{
	return isValidInteger( stringX ) && isValidInteger( stringY );
}

long CommandInterpreter::makeNumberFromInput ( string text )
{
	long x;
	stringstream ss( text );
	ss >> x;
	return x;
}

Point CommandInterpreter::makePointFromInput ( string stringX, string stringY )
{
	return Point( makeNumberFromInput( stringX ),
			makeNumberFromInput( stringY ) );
}
