//---------- Réalisation de la classe <Command> (fichier Command.cpp) ----
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "Command.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques


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
