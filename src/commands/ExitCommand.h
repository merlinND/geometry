//-- Interface de la classe <ExitCommand> (fichier ExitCommand.h) -
#if ! defined ( __ExitCommand___H_ )
#define __ExitCommand___H_

//--------------------------------------------------- Interfaces utilisées
#include "NonHistorizableCommand.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <ExitCommand>
// Tells the controller that the program should exit.
//------------------------------------------------------------------------ 

class ExitCommand : public NonHistorizableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques
	virtual std::string Execute ( );
	
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	ExitCommand ( );
	
	virtual ~ExitCommand ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
};

//------------------- Autres définitions dépendantes de <ExitCommand>

#endif // __ExitCommand___H_ 
