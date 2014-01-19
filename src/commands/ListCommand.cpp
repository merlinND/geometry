//---------- Réalisation de la classe <ListCommand> (fichier ListCommand.cpp) ----
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
string ListCommand::Execute ( )
{
	Controller * controller = Controller::GetInstance();
	vector<string> representations = controller->GetSortedRepresentations();
	for ( vector<string>::iterator it = representations.begin();
		 it != representations.end(); ++it )
	{
		cout << *it << endl;
	}
	
	return STATUS_OK_SILENT;
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
