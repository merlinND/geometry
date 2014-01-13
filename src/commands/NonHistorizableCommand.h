//---------- Interface de la classe <NonHistorizableCommand> (fichier NonHistorizableCommand.h) --------
#if ! defined ( NON_HISTORIZABLE_COMMAND_H_ )
#define NON_HISTORIZABLE_COMMAND_H_

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <NonHistorizableCommand>
// Simple intermediate class to group together all commands that
// should *not* be part of the history.
//------------------------------------------------------------------------
class NonHistorizableCommand : public Command
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	virtual inline bool IsHistorizable ( )
	{
		return false;
	}
};
#endif // NON_HISTORIZABLE_COMMAND_H_
