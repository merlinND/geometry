//-- Réalisation de la classe <NoneCommand> (fichier NoneCommand.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "NoneCommand.h"
#include "../Controller.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

string NoneCommand::Execute ( )
{
	// Doing nothing is this command's job
	return STATUS_OK_SILENT;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

NoneCommand::NoneCommand ( )
{
#ifdef MAP
	cout << "Appel au constructeur de <NoneCommand>" << endl;
#endif
} //----- Fin de NoneCommand 

NoneCommand::~NoneCommand ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <NoneCommand>" << endl;
#endif
} //----- Fin de ~NoneCommand

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées
