//-- Interface de la classe <NoneCommand> (fichier NoneCommand.h) -
#if ! defined ( __NoneCommand___H_ )
#define __NoneCommand___H_

//--------------------------------------------------- Interfaces utilisées
#include "NonHistorizableCommand.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <NoneCommand>
// A command that does nothing, but that is not an error either.
//------------------------------------------------------------------------ 

class NoneCommand : public NonHistorizableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques
	virtual std::string Execute ( );

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	NoneCommand ( );

	virtual ~NoneCommand ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
};

//------------------- Autres définitions dépendantes de <NoneCommand>

#endif // __NoneCommand___H_ 
