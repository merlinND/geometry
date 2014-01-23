//-- Interface de la classe <AddCommand> (fichier AddCommand.h) -
#if ! defined ( __AddCommand___H_ )
#define __AddCommand___H_

//--------------------------------------------------- Interfaces utilisées
#include <vector>

#include "HistorizableCommand.h"
#include "../geometricObjects/GeometricObject.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <AddCommand>
// Add an object to the document.
//------------------------------------------------------------------------

class AddCommand : public HistorizableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques
	virtual std::string Execute ( );
	virtual std::string Undo ( );

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	AddCommand ( );

	virtual ~AddCommand ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
};

//------------------- Autres définitions dépendantes de <AddCommand>

#endif // __AddCommand___H_ 
