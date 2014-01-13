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

void RedoCommand::execute ( )
{
	cout << "Executing RedoCommand" << endl;
	Controller::getInstance()->redo();
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
