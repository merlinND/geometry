//-- Interface de la classe <CommandInterpreter> (fichier CommandInterpreter.h)
#if ! defined ( __CommandInterpreter___H_ )
#define __CommandInterpreter___H_

//--------------------------------------------------- Interfaces utilisées
#include <iostream>

#include "Command.h"
#include "../geometricObjects/Point.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <CommandInterpreter>
// CommandInterpreter is a static class allowing to obtain an instance
// of the Command object representing the action corresponding to the
// user input (given as string).
//------------------------------------------------------------------------

class CommandInterpreter
{
//----------------------------------------------------------------- PUBLIC

public:
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques
	
	static Command * InterpretCommand ( istream & line );
	// Mode d'emploi :
	// Returns a pointer to the command object corresponding to the text
	// entered, configured with all the correct parameters.
	// Contrat :
	// If the input corresponds to no known command, or is wrong in any
	// way, returns NULL
	
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

	// Static class => private constructor
	virtual ~CommandInterpreter ( );
	
//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
	
	CommandInterpreter ( );
	// Contrat :
	// Static class
	
	static bool isNameUsedInDocument ( std::string name );
	// Mode d'emploi :
	// Checks whether an object with the given name *currently*
	// exists in the document.
	
	static bool isValidName ( std::string text );
	// Mode d'emploi :
	// Checks if a given string is a valid name to be given
	// to a GeometricObject.
	
	static bool isValidInteger ( std::string text );
	// Mode d'emploi :
	// Checks if a given string can be converted to a valid integer.
	// An empty string is not considered to be a valid integer.
	
	static bool isValidPoint ( std::string stringX, std::string stringY );
	// Mode d'emploi :
	// Checks if the two strings can be used to create a valid Point
	// or Vector2D. We accept integer coordinates only.
	
	static Point makePointFromInput ( std::string stringX,
									  std::string stringY );
	// Mode d'emploi :
	// Creates a Point instance from the given strings.
	// Contract :
	// The given strings have been checked first using isValidPoint.
	
	static int makeIntegerFromInput ( std::string text );
	// Mode d'emploi :
	// Creates an integer from the given string.
	// Contract :
	// The given string have been checked first using isValidInteger.
	
//----------------------------------------------------- Attributs protégés
};

//------------------- Autres définitions dépendantes de <CommandInterpreter>

#endif // __CommandInterpreter___H_ 
