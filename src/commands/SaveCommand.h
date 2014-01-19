//---------- Interface de la classe <SaveCommand> (fichier SaveCommand.h) --------
#if ! defined ( __SaveCommand___H_ )
#define __SaveCommand___H_

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include "NonHistorizableCommand.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <SaveCommand>
// Saves the current document's content at the specified path.
//------------------------------------------------------------------------
class SaveCommand : public NonHistorizableCommand
{
	//----------------------------------------------------------------- PUBLIC
	
public:
	//----------------------------------------------------- Méthodes publiques
	virtual std::string Execute ( );
	
	bool Good ( );
	
	//------------------------------------------------- Surcharge d'opérateurs
	//-------------------------------------------- Constructeurs - destructeur
	SaveCommand ( std::string const path );
	virtual ~SaveCommand ( );
	//------------------------------------------------------------------ PRIVE
	
protected:
	//----------------------------------------------------- Méthodes protégées
	//----------------------------------------------------- Attributs protégés
	ofstream outputStream;
};
#endif // __SaveCommand___H_
