/*************************************************************************
                           Agregate  -  description
                             -------------------
    début                : Jan 13, 2014
    copyright            : (C) 2014 par rbrunat
*************************************************************************/

//---------- Réalisation de la classe <Agregate> (fichier Agregate.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Agregate.h"
#include "../Controller.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Agregate::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Agregate::GetRepresentation()
{//

	string temp;
	/*for ( int i = 0; i < ( int )agregateComponents.size (); i++)
	{
		os << agregateComponents[i] << " " ;
		temp += os.str();
	}*/

		ostringstream os;
		os << name << " " ;
		for ( int i = 0; i < ( int )agregateComponents.size (); i++)
			{
				os << agregateComponents.at(i) << " " ;

			}
		string representation;
		representation = "OA " + os.str( );
		cout << representation;
		return representation;

}
void Agregate::Move(int dx, int dy)
{
	for ( int i = 0; i < ( int )agregateComponents.size (); i++)
	{
		agregateComponents [i];
		Controller * controller = Controller::GetInstance();
		controller->GetObjectByName(agregateComponents [i]);
	}
}
//------------------------------------------------- Surcharge d'opérateurs
Agregate & Agregate::operator = ( const Agregate & unAgregate )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*Agregate::Agregate ( const Agregate & unAgregate )
// Algorithme :
//
{// TODO: throw exception if used
#ifdef MAP
    cout << "Appel au constructeur de copie de <Agregate>" << endl;
#endif
} //----- Fin de Agregate (constructeur de copie)

*/
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
// affectation ne fonctionne pas....[i] =
    for ( int i = 0; i < components.size(); i++)
    {
    	agregateComponents.push_back( components[i]);
    }
} //----- Fin de Agregate



Agregate::~Agregate ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Agregate>" << endl;
#endif
} //----- Fin de ~Agregate


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

