//-- Interface de la classe <ClearCommand> (fichier ClearCommand.h) -
#if ! defined ( __ClearCommand___H_ )
#define __ClearCommand___H_

//--------------------------------------------------- Interfaces utilisées
#include <vector>

#include "HistorizableCommand.h"
#include "../geometricObjects/GeometricObject.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <ClearCommand>
// Remove all objects from the document.
//------------------------------------------------------------------------

class ClearCommand : public HistorizableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques
	
	virtual std::string Execute ( );
	virtual std::string Undo ( );
	
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	ClearCommand ( );

	virtual ~ClearCommand ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
	IdSet documentContent;
};

//------------------- Autres définitions dépendantes de <ClearCommand>

#endif // __ClearCommand___H_ 
