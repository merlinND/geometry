//-- Interface de la classe <UndoCommand> (fichier UndoCommand.h) -
#if ! defined ( __UndoCommand___H_ )
#define __UndoCommand___H_

//--------------------------------------------------- Interfaces utilisées
#include "NonHistorizableCommand.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <UndoCommand>
//
//------------------------------------------------------------------------ 

class UndoCommand : public NonHistorizableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques
	virtual void execute ( );
	
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	UndoCommand ( );
	// Mode d'emploi :
	// Indicates to the controller that it should undo the last operation.

	virtual ~UndoCommand ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
};

//------------------- Autres définitions dépendantes de <UndoCommand>

#endif // __UndoCommand___H_ 
