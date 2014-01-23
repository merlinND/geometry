//-- Interface de la classe <RedoCommand> (fichier RedoCommand.h) -
#if ! defined ( __RedoCommand___H_ )
#define __RedoCommand___H_

//--------------------------------------------------- Interfaces utilisées
#include "NonHistorizableCommand.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <RedoCommand>
// Indicates to the controller that it should redo the last
// undone operation.
//------------------------------------------------------------------------ 

class RedoCommand : public NonHistorizableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques
	virtual std::string Execute ( );

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	RedoCommand ( );

	virtual ~RedoCommand ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
};

//------------------- Autres définitions dépendantes de <RedoCommand>

#endif // __RedoCommand___H_ 
