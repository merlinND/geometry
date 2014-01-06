//---------- Interface de la classe <Command> (fichier Command.h) --------
#if ! defined ( COMMAND_H_ )
#define COMMAND_H_

//--------------------------------------------------- Interfaces utilisées
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
	virtual void execute ( ) = 0;
	// Mode d'emploi :
	// Execute the command. It should gather any information needed to be able
	// to be undone.
	virtual void undo ( ) = 0;
	// Mode d'emploi :
	// Undoing should bring back the application to the same state as before
	// this Command was executed.
	
	//------------------------------------------------- Surcharge d'opérateurs
	//-------------------------------------------- Constructeurs - destructeur
	Command ( );
	virtual ~Command ( );
	//------------------------------------------------------------------ PRIVE
	
protected:
	//----------------------------------------------------- Méthodes protégées
	//----------------------------------------------------- Attributs protégés
	
};
#endif // COMMAND_H_
