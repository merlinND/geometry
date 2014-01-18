//-- Interface de la classe <DeleteCommand> (fichier DeleteCommand.h) -
#if ! defined ( __DeleteCommand___H_ )
#define __DeleteCommand___H_

//--------------------------------------------------- Interfaces utilisées
#include <vector>

#include "HistorizableCommand.h"
#include "../geometricObjects/GeometricObject.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <DeleteCommand>
// Remove a GeometricObject from the document.
// All references to the removed object in Agregate objects are also
// removed. Thus, when calling Undo(), theses references must be
// added back.
//------------------------------------------------------------------------

class DeleteCommand : public HistorizableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques
	virtual void AddTarget( int targetId );
	
	virtual std::string Execute ( );
	virtual std::string Undo ( );
	
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	DeleteCommand ( );

	virtual ~DeleteCommand ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
	// The agregates in which each deleted object was included at
	// the time of Execute(). One IdSet per deleted object.
	vector<IdSet> parentAgregates;
};

//------------------- Autres définitions dépendantes de <DeleteCommand>

#endif // __DeleteCommand___H_ 
