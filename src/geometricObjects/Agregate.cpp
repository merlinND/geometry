//---------- Réalisation de la classe <Agregate> (fichier Agregate.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Agregate.h"
#include "../Controller.h"

//------------------------------------------------------------- Constantes
const string Agregate::INITIALS = "OA";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Agregate::GetRepresentation()

{
	string representation = GetInitials() + " " + name;
	
	Controller * controller = Controller::GetInstance();
	for ( IdSet::iterator it = agregateComponents.begin();
		 it != agregateComponents.end(); ++it )
	{
		representation += " " + controller->GetNameById( *it );
	}
	return representation;
} //----- End GetRepresentation


void Agregate::Move( int dx, int dy )
{
	Controller * controller = Controller::GetInstance();
	GeometricObject * currentObject;
	for ( IdSet::iterator it = agregateComponents.begin();
		 it != agregateComponents.end(); ++it )
	{
		currentObject = controller->GetObjectById( *it );
		currentObject->Move( dx, dy );
	}

} //----- End Move

void Agregate::AddComponent( int idToAdd )
{
	agregateComponents.insert( idToAdd );
}

IdSet Agregate::GetComponents ( )
{
	return agregateComponents;
}

void Agregate::RemoveComponent( int idToRemove )
{
	agregateComponents.erase(agregateComponents.find( idToRemove ));
}

void Agregate::RemoveAllComponents ( )
{
	agregateComponents.clear();
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

Agregate::Agregate ( std::string name )
	: GeometricObject ( name, INITIALS )
{
#ifdef MAP
    cout << "Appel au constructeur de <Agregate>" << endl;
#endif
} //----- Fin de Agregate

Agregate::Agregate ( std::string name, vector<int> contained)
	: GeometricObject ( name, INITIALS )
{
#ifdef MAP
    cout << "Appel au constructeur de <Agregate>" << endl;
#endif

    for( int i = 0; i < contained.size(); i++ )
    {
    	agregateComponents.insert( contained[i] );
    }
} //----- Fin de Agregate

Agregate::~Agregate ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Agregate>" << endl;
#endif
} //----- Fin de ~Agregate


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

