//-- Interface de la classe <CommandInterpreter> (fichier CommandInterpreter.h)
#if ! defined ( __CommandInterpreter___H_ )
#define __CommandInterpreter___H_

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"

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
	
	static Command & interpretCommand ( std::string line );
	
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
	
	static Command & getCommandFromText ( const std::string text );
	// Mode d'emploi :
	// Returns a new instance of the appropriate Command
	// Example: "MOVE" => MoveCommand
	
//----------------------------------------------------- Attributs protégés
};

//------------------- Autres définitions dépendantes de <CommandInterpreter>

#endif // __CommandInterpreter___H_ 
