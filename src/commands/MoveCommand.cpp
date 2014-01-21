//-- Réalisation de la classe <MoveCommand> (fichier MoveCommand.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "MoveCommand.h"
#include "../Controller.h"
#include "../geometricObjects/Point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

string MoveCommand::Execute ( )
{
	executionCounter++;
	
	Controller * controller = Controller::GetInstance();
	GeometricObject * currentObject;
	for ( IdSet::iterator it = targets.begin();
		 it != targets.end(); ++it )
	{
		currentObject = controller->GetObjectById( *it );
		if ( currentObject->GetLastAppliedCommandId() != executionCounter )
		{
			currentObject->SetLastAppliedCommandId( executionCounter );
			currentObject->Move( offset.x, offset.y );
		}
	}
	return STATUS_OK;
}
string MoveCommand::Undo ( )
{
	// Re-execute the movement with an inversed offset
	offset.Reverse();
	Execute();
	offset.Reverse();
	return STATUS_OK;
}

void MoveCommand::SetOffset ( Vector2D theOffset )
{
	offset = theOffset;
}
void MoveCommand::SetOffset ( int dx, int dy )
{
	offset.x = dx;
	offset.y = dy;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

MoveCommand::MoveCommand ( ) : offset( 0, 0 )
{
#ifdef MAP
	cout << "Appel au constructeur de <MoveCommand>" << endl;
#endif
} //----- Fin de MoveCommand 

MoveCommand::~MoveCommand ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <MoveCommand>" << endl;
#endif
} //----- Fin de ~MoveCommand

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées
