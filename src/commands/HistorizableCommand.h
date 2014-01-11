//---------- Interface de la classe <HistorizableCommand> (fichier HistorizableCommand.h) --------
#if ! defined ( HISTORIZABLE_COMMAND_H_ )
#define HISTORIZABLE_COMMAND_H_

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <HistorizableCommand>
// Simple intermediate class to group together all commands that should
// be undoable.
//------------------------------------------------------------------------
class HistorizableCommand : public Command
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques
	virtual inline bool isHistorizable ( )
	{
		return true;
	}
	
protected:
	
};
#endif // HISTORIZABLE_COMMAND_H_
