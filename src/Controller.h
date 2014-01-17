//-- Interface de la classe <Controller> (fichier Controller.h)
#if ! defined ( __Controller___H_ )
#define __Controller___H_

//--------------------------------------------------- Interfaces utilisées
#include <map>

#include "commands/Command.h"
#include "commands/History.h"
#include "geometricObjects/Agregate.h"
//------------------------------------------------------------- Constantes 
//------------------------------------------------------------------ Types
typedef map<std::string, GeometricObject *> GeometricMap;

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
	
	static Controller * GetInstance ( );
	// Mode d'emploi :
	// Only acess point to a Controller instance (Singleton pattern)
	
	std::string ProcessCommand ( Command * command );
	// Mode d'emploi :
	// Attempt to execute the command passed as argument,
	// and add it to the History if appropriate.
	
	void Undo ( );
	// Mode d'emploi :
	// Undo the last processed command.
	void Redo ( );
	// Mode d'emploi :
	// Redo the last un-done command.
	
	GeometricObject * GetObjectByName ( std::string name );
	// Mode d'emploi :
	// This method should be the only access point to actual
	// GeometricObject instances. Agregate and Command objects only
	// have their targets' names. They must use this method to access
	// the corresponding instances.
	// Contrat :
	// Returns NULL if the object is not found
	
	bool IsNameUsedInDocument ( std::string name );
	// Mode d'emploi :
	// Enables to check if a name is used by an object that is
	// *currently* part of the document.
	
	vector<string> ClearDocument ( );
	// Mode d'emploi :
	// Removes every object from the document. The actual object instances
	// are not freed, since the clear command could very well be undone.
	// Returns a list of all the objects' ids contained in the document.
	
	bool ShouldExit ( );
	// Mode d'emploi :
	// Use this method to know wether the application should exit or not
	void Exit ( );
	// Mode d'emploi :
	// Use this method to indicate that the application should exit
	
	
	
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
	// Indicated if the application should exit
	bool exitFlag;
	
	History history;

	// An agregate object which contains all GeometricObjects that *are*
	// currently part of the document
	Agregate model;
	
	// An associative array of GeometricObjects that were created
	// in this session, even if they are not part of the document
	GeometricMap allObjects;
};

//------------------- Autres définitions dépendantes de <Controller>

#endif // __Controller___H_ 
