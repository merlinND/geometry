//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if ! defined ( RECTANGLE_H_ )
#define RECTANGLE_H_
#include "Point.h"
#include "GeometricObject.h"
#include <string>
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Rectangle>
//
//
//------------------------------------------------------------------------ 

class Rectangle : public GeometricObject
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//
	string GetRepresentation ( );

//------------------------------------------------- Surcharge d'opérateurs
	Rectangle & operator = ( const Rectangle & unRectangle );
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	Rectangle ( const Rectangle & unRectangle );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Rectangle ( string myRectangle, Point uLC, Point lRC );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Rectangle ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Point upperLeftCorner;
	Point lowerRightCorner;
};

//--------------------------- Autres définitions dépendantes de <Rectangle>

#endif // RECTANGLE_H_
