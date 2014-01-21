//---------- Réalisation de la classe <History> (fichier History.cpp) ----
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "History.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void History::Undo ( )
{
	if ( !undoStack.empty() )
	{
		HistorizableCommand * mostRecentCommand = undoStack.top();
		undoStack.pop();
		mostRecentCommand->Undo();
		redoStack.push(mostRecentCommand);
	}
} // ----- End undo

void History::Redo ( )
{
	if ( !redoStack.empty() )
	{
		HistorizableCommand * mostRecentlyUndoneCommand = redoStack.top();
		redoStack.pop();
		mostRecentlyUndoneCommand->Execute();
		undoStack.push(mostRecentlyUndoneCommand);
	}
} // ----- End redo

void History::AddCommand ( HistorizableCommand * commandToAdd )
{
	undoStack.push( commandToAdd );
	// As soon as you add a command on top of the history,
	// it becomes impossible to redo anything that you had undone
	emptyRedoStack();
} // ----- End addCommand
void History::DeleteLastCommand ( )
{
	undoStack.pop();
} // ----- End deleteLastCommand

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
History::History ( )
{
#ifdef MAP
	cout << "Appel au constructeur de <History>" << endl;
#endif
} //----- Fin de History

History::~History ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <History>" << endl;
#endif
} //----- Fin de ~History

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void History::emptyRedoStack ( )
{
	CommandStack emptyStack;
	redoStack = emptyStack;
}