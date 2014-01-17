//-- Réalisation de la classe <MoveCommand> (fichier MoveCommand.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "MoveCommand.h"
#include "../geometricObjects/Point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

void MoveCommand::Execute ( )
{
	cout << "Executing MoveCommand [not implemented]" << endl;
}
void MoveCommand::Undo ( )
{
	cout << "Undoing MoveCommand [not implemented]" << endl;
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
