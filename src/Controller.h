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
typedef map<int, GeometricObject *> GeometricMap;

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
	
	GeometricObject * GetObjectById ( int idToFind );
	// Mode d'emploi :
	// This method should be the only access point to actual
	// GeometricObject instances. Agregate and Command objects only
	// have their targets' id. They must use this method to access
	// the corresponding instances.
	// Contrat :
	// Returns NULL if the object is not found
	
	std::string GetNameById ( int idToFind );
	// Mode d'emploi :
	// Returns an object's name from its id.
	// Contrat :
	// Returns NULL if the object is not found
	
	int GetIdByName ( std::string name );
	// Mode d'emploi :
	// Returns the id corresponding to this name *in the current
	// document only*, not in all objects that were ever created.
	// Contrat :
	// Returns NULL if the object is not found in the document
	
	bool IsNameUsedInDocument ( std::string name );
	// Mode d'emploi :
	// Enables to check if a name is used by an object that is
	// *currently* part of the document.
	
	IdSet ClearDocument ( );
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
	// The constructor is private because <Controller> is a singleton.
//----------------------------------------------------- Attributs protégés
	// Pointer to the only Controller instance that exists
	static Controller * theInstance;
	
	// Indicated if the application should exit
	bool exitFlag;
	
	// Holds the commands that can we can undo & redo
	History history;

	// An associative array of GeometricObjects that were created
	// in this session, even if they are not part of the document
	// Object id (int) => Pointer to the instance
	GeometricMap allObjects;
	
	// An agregate object which contains all GeometricObjects that are
	// *currently* part of the document
	Agregate model;
};

//------------------- Autres définitions dépendantes de <Controller>

#endif // __Controller___H_ 
