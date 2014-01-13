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
void History::undo ( )
{
	if ( !undoStack.empty() )
	{
		HistorizableCommand * mostRecentCommand = undoStack.top();
		undoStack.pop();
		mostRecentCommand->undo();
		redoStack.push(mostRecentCommand);
	}
	else
	{
		cout << "Nothing to undo" << endl;
	}
} // ----- End undo

void History::redo ( )
{
	if ( !redoStack.empty() )
	{
		HistorizableCommand * mostRecentlyUndoneCommand = redoStack.top();
		redoStack.pop();
		mostRecentlyUndoneCommand->execute();
		undoStack.push(mostRecentlyUndoneCommand);
	}
	else
	{
		cout << "Nothing to redo" << endl;
	}
} // ----- End redo

void History::addCommand ( HistorizableCommand * commandToAdd )
{
	undoStack.push( commandToAdd );
} // ----- End addCommand
void History::deleteLastCommand ( )
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
	redoStack.empty();
}