//-- Interface de la classe <LoadCommand> (fichier LoadCommand.h) -
#if ! defined ( __LoadCommand___H_ )
#define __LoadCommand___H_

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include <stack>
#include "HistorizableCommand.h"

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
typedef stack<Command *> AnyCommandStack;
//------------------------------------------------------------------------ 
// Rôle de la classe <LoadCommand>
// Load a batch of commands saved from a file and execute it.
// If *any* command is wrong in any way, execute no command at all.
//------------------------------------------------------------------------

class LoadCommand : public HistorizableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques
	virtual std::string Execute ( );
	virtual std::string Undo ( );
	
	bool Good ( );
	
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	LoadCommand ( std::string path );
	virtual ~LoadCommand ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
	void loadCommandsFromInput ( istream & input );
	
//----------------------------------------------------- Attributs protégés
	// The stream from which we will parse the commands at the first
	// execution
	ifstream input;
	// A field that will indicate if we were able to load all commands
	// successfully from the given input
	bool loadFailed;
	// Two stacks to keep track of which of the loaded commands where
	// executed yet.
	// Warning: none of those commands actually go into the Controller's
	// history, since we want a LOAD command to be undoable in one single
	// call to UNDO.
	AnyCommandStack commandsToDo, commandsDone;
};

//------------------- Autres définitions dépendantes de <LoadCommand>

#endif // __LoadCommand___H_ 
