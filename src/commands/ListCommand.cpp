//---------- Réalisation de la classe <Command> (fichier Command.cpp) ----
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "ListCommand.h"
#include "../Controller.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void ListCommand::Execute ( )
{
	cout << "Executing the list command [TODO]" << endl;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
ListCommand::ListCommand ( )
{
#ifdef MAP
	cout << "Appel au constructeur de <ListCommand>" << endl;
#endif
} //----- Fin de ListCommand

ListCommand::~ListCommand ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <ListCommand>" << endl;
#endif
} //----- Fin de ~ListCommand

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
