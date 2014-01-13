//-- Interface de la classe <RedoCommand> (fichier RedoCommand.h) -
#if ! defined ( __RedoCommand___H_ )
#define __RedoCommand___H_

//--------------------------------------------------- Interfaces utilisées
#include "NonHistorizableCommand.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <RedoCommand>
//
//------------------------------------------------------------------------ 

class RedoCommand : public NonHistorizableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques
	virtual void Execute ( );
	
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	RedoCommand ( );
	// Mode d'emploi :
	// Indicates to the controller that it should undo the last operation.

	virtual ~RedoCommand ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
};

//------------------- Autres définitions dépendantes de <RedoCommand>

#endif // __RedoCommand___H_ 
