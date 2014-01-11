//-- Interface de la classe <Controller> (fichier Controller.h)
#if ! defined ( __Controller___H_ )
#define __Controller___H_

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"
#include "History.h"
#include "../geometricObjects/GeometricObject.h"
//------------------------------------------------------------- Constantes 
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <Controller>
//
//------------------------------------------------------------------------ 

class Controller
{
//----------------------------------------------------------------- PUBLIC

public:
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques
	
	static Controller * getInstance ( );
	// Mode d'emploi :
	// Only acess point to a Controller instance (Singleton pattern)
	
	std::string processCommand ( Command & command );
	
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

	// Constructeur par copie
	Controller ( const Controller & theController );
	// Mode d'emploi :
	// 
	// Contrat :
	// 

	virtual ~Controller ( );
	// Mode d'emploi :
	// 
	// Contrat :
	// 

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
	Controller ( );
	// Mode d'emploi :
	// Constructeur privé car <Controller> est singleton
//----------------------------------------------------- Attributs protégés
	// Pointer to the only Controller instance that exists
	static Controller * theInstance;
	
	
	History history;

	// An agregate object which contains all GeometricObjects that *are*
	// currently part of the document
	// TODO: change to an Agregate type (and not pointer)
	GeometricObject * model;
	// A list of *all* GeometricObjects that were created in this session,
	// even if they are not part of the document
	// TODO: choose appropriate type
};

//------------------- Autres définitions dépendantes de <Controller>

#endif // __Controller___H_ 
