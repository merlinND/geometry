//-- Réalisation de la classe <RedoCommand> (fichier RedoCommand.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "RedoCommand.h"
#include "../Controller.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

string RedoCommand::Execute ( )
{
	Controller::GetInstance( )->Redo( );
	// TODO: we should take into account the returned status
	// from the Command itself
	return STATUS_OK;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

RedoCommand::RedoCommand ( )
{
#ifdef MAP
	cout << "Appel au constructeur de <RedoCommand>" << endl;
#endif
} //----- Fin de RedoCommand 

RedoCommand::~RedoCommand ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <RedoCommand>" << endl;
#endif
} //----- Fin de ~RedoCommand

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées
