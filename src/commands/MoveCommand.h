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
//
//------------------------------------------------------------------------ 

class MoveCommand : public HistorizableCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques
	virtual void Execute ( );
	virtual void Undo ( );
	
	void SetOffset ( Vector2D theOffset );
	void SetOffset ( int dx, int dy );
	
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	MoveCommand ( );
	// Mode d'emploi :
	// Moves a set of GeometricObjects by the desired vector.

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
