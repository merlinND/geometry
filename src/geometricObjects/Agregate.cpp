//---------- Réalisation de la classe <Agregate> (fichier Agregate.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Agregate.h"
#include "../Controller.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Agregate::GetRepresentation()

{
	string representation = "OA " + name;
	for ( int i = 0; i < ( int )agregateComponents.size (); i++)
	{
		representation += " " + agregateComponents[i];
	}
	cout << representation << endl;
	return representation;
} //----- End GetRepresentation


void Agregate::Move(int dx, int dy)
{
	for ( int i = 0; i < ( int )agregateComponents.size (); i++)
	{

		Controller * controller = Controller::GetInstance();
		controller->GetObjectByName(agregateComponents [i]);

	}

} //----- End Move

void Agregate::AddComponent(string idToAdd)
{
	for ( int i = 0; i < ( int )agregateComponents.size (); i++)
	{

		if (agregateComponents[i] == idToAdd)
		{
			cout << "ERROR: cannot have duplicates in an agregate" << endl;
			return ;
		}
	}
	agregateComponents.push_back(idToAdd);
}

vector<string> Agregate::GetComponents ( )
{
	return agregateComponents;
}

void Agregate::RemoveComponent( string name )
{
	
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

Agregate::Agregate ( std::string name ) : GeometricObject ( name )
{
#ifdef MAP
    cout << "Appel au constructeur de <Agregate>" << endl;
#endif
} //----- Fin de Agregate

Agregate::Agregate ( std::string name,
					vector <std::string> contained)
	: GeometricObject ( name )
{
#ifdef MAP
    cout << "Appel au constructeur de <Agregate>" << endl;
#endif

    for( int i = 0; i < contained.size(); i++ )
    {
    	agregateComponents.push_back(contained[i]);
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

