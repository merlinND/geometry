//-- Réalisation de la classe <ExitCommand> (fichier ExitCommand.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "ExitCommand.h"
#include "../Controller.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

void ExitCommand::Execute ( )
{
	Controller * c = Controller::GetInstance();
	c->Exit();
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

ExitCommand::ExitCommand ( )
{
#ifdef MAP
	cout << "Appel au constructeur de <ExitCommand>" << endl;
#endif
} //----- Fin de ExitCommand 

ExitCommand::~ExitCommand ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <ExitCommand>" << endl;
#endif
} //----- Fin de ~ExitCommand

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées
