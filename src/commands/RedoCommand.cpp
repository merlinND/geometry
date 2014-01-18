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
	cout << "Executing RedoCommand" << endl;
	Controller::GetInstance()->Redo();
	return STATUS_OK_SILENT;
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
