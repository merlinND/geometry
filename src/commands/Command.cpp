//---------- Réalisation de la classe <Command> (fichier Command.cpp) ----
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Command.h"
//------------------------------------------------------------- Constantes
// Initializing static field
int Command::commandCounter = 0;

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

void Command::AddTarget( int targetId )
{
	targets.insert( targetId );
}

int Command::GetCommandId ( )
{
	return commandId;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
Command::Command ( )
{
#ifdef MAP
	cout << "Appel au constructeur de <Command>" << endl;
#endif
	
	// Increment the command counter so that each new command can
	// have a unique id number
	commandId = commandCounter;
	commandCounter++;
} //----- Fin de Command

Command::~Command ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <Command>" << endl;
#endif
} //----- Fin de ~Command

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
