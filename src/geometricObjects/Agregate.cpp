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
void Agregate::AddObject(string objectAdded)
{


	for ( int i = 0; i < ( int )agregateComponents.size (); i++)
	{

		if (agregateComponents[i] == objectAdded)
		{
			cout << "cannot have twins in an agregate" << endl;
				return ;
		}
	}
	agregateComponents.push_back(objectAdded);
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

Agregate::Agregate ( std::string myAgregate, vector <std::string> contained) : GeometricObject ( myAgregate )
// Algorithme :
//
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

