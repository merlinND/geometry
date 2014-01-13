//-- Réalisation de la classe <UndoCommand> (fichier UndoCommand.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "UndoCommand.h"
#include "../Controller.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

void UndoCommand::Execute ( )
{
	cout << "Executing UndoCommand" << endl;
	Controller::GetInstance()->Undo();
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

UndoCommand::UndoCommand ( )
{
#ifdef MAP
	cout << "Appel au constructeur de <UndoCommand>" << endl;
#endif
} //----- Fin de UndoCommand 

UndoCommand::~UndoCommand ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <UndoCommand>" << endl;
#endif
} //----- Fin de ~UndoCommand

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées
