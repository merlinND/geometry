//---------- Interface de la classe <ListCommand> (fichier ListCommand.h) --------
#if ! defined ( __ListCommand___H_ )
#define __ListCommand___H_

//--------------------------------------------------- Interfaces utilisées
#include "NonHistorizableCommand.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <ListCommand>
// List all objects currently in the document (one object per line).
//------------------------------------------------------------------------
class ListCommand : public NonHistorizableCommand
{
	//----------------------------------------------------------------- PUBLIC
	
public:
	//----------------------------------------------------- Méthodes publiques
	virtual std::string Execute ( );

	//------------------------------------------------- Surcharge d'opérateurs
	//-------------------------------------------- Constructeurs - destructeur
	ListCommand ( );
	virtual ~ListCommand ( );
	//------------------------------------------------------------------ PRIVE
	
protected:
	//----------------------------------------------------- Méthodes protégées
	//----------------------------------------------------- Attributs protégés
	
};
#endif // __ListCommand___H_
