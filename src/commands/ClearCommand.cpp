//-- Réalisation de la classe <ClearCommand> (fichier ClearCommand.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "ClearCommand.h"
#include "../Controller.h"
#include "../geometricObjects/Agregate.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

string ClearCommand::Execute ( )
{
	executionCounter++;
	
	Controller * controller = Controller::GetInstance();
	documentContent = controller->ClearDocument();
	
	return STATUS_OK;
}
string ClearCommand::Undo ( )
{
	executionCounter++;
	
	Controller * controller = Controller::GetInstance();
	for ( IdSet::iterator it = documentContent.begin();
		 it != documentContent.end(); ++it )
	{
		controller->AddIdToDocument( *it );
	}
	return STATUS_OK;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

ClearCommand::ClearCommand ( )
{
#ifdef MAP
	cout << "Appel au constructeur de <ClearCommand>" << endl;
#endif
} //----- Fin de ClearCommand 

ClearCommand::~ClearCommand ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <ClearCommand>" << endl;
#endif
} //----- Fin de ~ClearCommand

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées
