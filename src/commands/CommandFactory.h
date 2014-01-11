//-- Interface de la classe <CommandFactory> (fichier CommandFactory.h)
#if ! defined ( __CommandFactory___H_ )
#define __CommandFactory___H_

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <CommandFactory>
// CommandFactory est une classe Singleton permettant d'obtenir une
// instance de commande à partir de sa représentation textuelle données
// par l'utilisateur.
// Ex : "MOVE" => MoveCommand
//------------------------------------------------------------------------

class CommandFactory
{
//----------------------------------------------------------------- PUBLIC

public:
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques
	
	static CommandFactory * getInstance ( );
	// Mode d'emploi :
	// L'unique manière d'obtenir une instance de CommandFactory
	
	Command & getCommandFromText ( const std::string text );
	
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

	virtual ~CommandFactory ( );
	// Mode d'emploi :
	// 
	// Contrat :
	// 

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
	CommandFactory ( );
	// Contrat :
	// Constructeur privé par la classe est un singleton
//----------------------------------------------------- Attributs protégés
	static CommandFactory * theInstance;
};

//------------------- Autres définitions dépendantes de <CommandFactory>

#endif // __CommandFactory___H_ 
