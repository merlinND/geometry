//---------- Réalisation de la classe <Command> (fichier Command.cpp) ----
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "ListCommand.h"
#include "../Controller.h"
#include "../geometricObjects/GeometricObject.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void ListCommand::Execute ( )
{
	Controller * controller = Controller::GetInstance();
	IdSet allIds = controller->GetAllIdsInDocument();
	GeometricObject * currentObject;
	for ( IdSet::iterator it = allIds.begin();
		 it != allIds.end(); ++it )
	{
		currentObject = controller->GetObjectById( *it );
		cout << currentObject->GetRepresentation() << endl;
	}
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
