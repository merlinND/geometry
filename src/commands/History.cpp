//---------- Réalisation de la classe <History> (fichier History.cpp) ----
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "History.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void History::undo ( )
{
	Command * mostRecentCommand = undoStack.top();
	undoStack.pop();
	mostRecentCommand->undo();
	redoStack.push(mostRecentCommand);
} // ----- End undo

void History::redo ( )
{
	Command * mostRecentlyUndoneCommand = redoStack.top();
	redoStack.pop();
	mostRecentlyUndoneCommand->execute();
	undoStack.push(mostRecentlyUndoneCommand);
} // ----- End redo

void History::addCommand ( Command & commandToAdd )
{
	undoStack.push(& commandToAdd);
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