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
	cout << representation;
	return representation;
} //----- End GetRepresentation

void Agregate::Move(int dx, int dy)
{
	for ( int i = 0; i < ( int )agregateComponents.size (); i++)
	{
		agregateComponents [i];
		Controller * controller = Controller::GetInstance();
		controller->GetObjectByName(agregateComponents [i]);
	}
} //----- End Move

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

Agregate::Agregate ( string myAgregate, vector <string> components) : GeometricObject ( myAgregate )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Agregate>" << endl;
#endif
    //cout <<"test";
    //agregateComponents[0]=components[0];
    //cout << agregateComponents[0];
	// affectation ne fonctionne pas....
    for ( int i = 0; i < components.size(); i++)
    {
    	agregateComponents.push_back( components[i] );
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

