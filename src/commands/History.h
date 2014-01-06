//---------- Interface de la classe <History> (fichier History.h) ----------
#if ! defined ( HISTORY_H_ )
#define HISTORY_H_

//--------------------------------------------------- Interfaces utilisées
#include <stack>

#include "Command.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
typedef std::stack<Command *> CommandStack;
//------------------------------------------------------------------------
// Rôle de la classe <History>
// TODO
//------------------------------------------------------------------------
class History
{
	//----------------------------------------------------------------- PUBLIC
	
public:
	//----------------------------------------------------- Méthodes publiques
	void undo ( );
	// Mode d'emploi :
	// Contrat :
	void redo ( );
	// Mode d'emploi :
	// Contrat :
	
	void addCommand ( Command & commandToAdd );
	// Mode d'emploi :
	// Add a command to the history. It will then become the first command to
	// be undone.
	void deleteLastCommand ( );
	// Mode d'emploi :
	// Delete the last command from the history. It is lost forever.
	
	//------------------------------------------------- Surcharge d'opérateurs
	//-------------------------------------------- Constructeurs - destructeur
	History ( );
	virtual ~History ( );
	//------------------------------------------------------------------ PRIVE
	
protected:
	//----------------------------------------------------- Méthodes protégées
	void emptyRedoStack ( );
	//----------------------------------------------------- Attributs protégés
	CommandStack undoStack, redoStack;
};
#endif // HISTORY_H_
