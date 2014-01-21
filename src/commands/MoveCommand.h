//-- Interface de la classe <MoveCommand> (fichier MoveCommand.h) -
#if ! defined ( __MoveCommand___H_ )
#define __MoveCommand___H_

//--------------------------------------------------- Interfaces utilisées
#include "HistorizableCommand.h"
#include "../geometricObjects/Point.h"
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types 
//------------------------------------------------------------------------ 
// Rôle de la classe <MoveCommand>
// Moves a set of GeometricObjects by the desired vector.
//------------------------------------------------------------------------ 

class MoveCommand : public HistorizableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques
	virtual std::string Execute ( );
	virtual std::string Undo ( );
	
	void SetOffset ( Vector2D theOffset );
	void SetOffset ( long dx, long dy );
	
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	MoveCommand ( );

	virtual ~MoveCommand ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
	// The quantity by which target objects should be displaced
	Vector2D offset;
};

//------------------- Autres définitions dépendantes de <MoveCommand>

#endif // __MoveCommand___H_ 
