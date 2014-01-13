//---------- Interface de la classe <ListCommand> (fichier ListCommand.h) --------
#if ! defined ( LIST_COMMAND_H_ )
#define LIST_COMMAND_H_

//--------------------------------------------------- Interfaces utilisées
#include "NonHistorizableCommand.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <ListCommand>
// TODO
//------------------------------------------------------------------------
class ListCommand : NonHistorizableCommand
{
	//----------------------------------------------------------------- PUBLIC
	
public:
	//----------------------------------------------------- Méthodes publiques
	virtual void execute ( );
	virtual void undo ( );
	
	//------------------------------------------------- Surcharge d'opérateurs
	//-------------------------------------------- Constructeurs - destructeur
	ListCommand ( );
	virtual ~ListCommand ( );
	//------------------------------------------------------------------ PRIVE
	
protected:
	//----------------------------------------------------- Méthodes protégées
	//----------------------------------------------------- Attributs protégés
	
};
#endif // LIST_COMMAND_H_