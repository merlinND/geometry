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
	
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	LoadCommand ( std::string thePath );
	virtual ~LoadCommand ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
	std::string loadAndExecute ( istream * input );
	// Mode d'emploi :
	// Load commands from the input and execute them one by one.
	// If anything fails, we cancel everything that had been done.
	// Return the status of execution (STATUS_OK, etc).
	
	void cancelEverything ( bool undo );
	// Mode d'emploi :
	// The parameter indicates in which direction we want to cancel things,
	// i.e. were we doing or undoing things when we called this method?
	
//----------------------------------------------------- Attributs protégés
	// The stream from which we will parse the commands at the first
	// execution
	std::string path;
	ifstream * input;
	// A field that will indicate if we already loaded the commands
	bool loadPerformed;
	// Two stacks to keep track of which of the loaded commands where
	// executed yet.
	// Warning: none of those commands actually go into the Controller's
	// history, since we want a LOAD command to be undoable in one single
	// call to UNDO.
	AnyCommandStack commandsToDo, commandsDone;
};

//------------------- Autres définitions dépendantes de <LoadCommand>

#endif // __LoadCommand___H_ 
