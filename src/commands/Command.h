//---------- Interface de la classe <Command> (fichier Command.h) --------
#if ! defined ( COMMAND_H_ )
#define COMMAND_H_

//--------------------------------------------------- Interfaces utilisées
#include "../geometricObjects/GeometricObject.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <Command>
// Abstract parent class of all Command classes.
//------------------------------------------------------------------------
class Command
{
//----------------------------------------------------------------- PUBLIC
public:
//--------------------------------------------------- Constantes de classe
	static const std::string STATUS_OK;
	static const std::string STATUS_OK_SILENT;
	static const std::string STATUS_ERROR;
	
//----------------------------------------------------- Méthodes publiques
	virtual bool IsHistorizable ( ) = 0;
	
	virtual void AddTarget ( TId targetId );
	
	virtual std::string Execute ( ) = 0;
	// Mode d'emploi :
	// Execute the command. It should gather any information needed
	// to be able to be undone.
	
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	Command ( );
	virtual ~Command ( );
//------------------------------------------------------------------ PRIVE
	
protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
	// A counter which is incremented each time a new command
	// is executed.
	static int executionCounter;
	
	// A list of the target(s)' name
	// To access the actual instances, use Controller::GetObjectByName
	IdSet targets;
};
#endif // COMMAND_H_
