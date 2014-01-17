//---------- Interface de la classe <Command> (fichier Command.h) --------
#if ! defined ( COMMAND_H_ )
#define COMMAND_H_

//--------------------------------------------------- Interfaces utilisées
#include "../geometricObjects/GeometricObject.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <Command>
// TODO
//------------------------------------------------------------------------
class Command
{
//----------------------------------------------------------------- PUBLIC
	
public:
//----------------------------------------------------- Méthodes publiques
	virtual bool IsHistorizable ( ) = 0;
	
	virtual void AddTarget ( int targetId );
	
	virtual void Execute ( ) = 0;
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
