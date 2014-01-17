//---------- Réalisation de la classe <Command> (fichier Command.cpp) ----
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Command.h"
//------------------------------------------------------------- Constantes
// Initializing static field
int Command::executionCounter = 0;

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

void Command::AddTarget( int targetId )
{
	targets.insert( targetId );
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
Command::Command ( )
{
#ifdef MAP
	cout << "Appel au constructeur de <Command>" << endl;
#endif
} //----- Fin de Command

Command::~Command ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <Command>" << endl;
#endif
} //----- Fin de ~Command

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
