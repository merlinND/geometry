/*************************************************************************
 Circle  -  description
 -------------------
 début                : 6 janv. 2014
 copyright            : (C) 2014 par rbrunat
 *************************************************************************/

//---------- Interface de la classe <Circle> (fichier Circle.h) ------
#if ! defined ( CIRCLE_H_ )
#define CIRCLE_H_
#include "Point.h"
#include "GeometricObject.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Circle>
//
//
//------------------------------------------------------------------------ 

class Circle : public GeometricObject
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
	Circle & operator = ( const Circle & unCircle );
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	Circle ( const Circle & unCircle );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Circle ( Point centre, int R );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Circle ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Point center;
	int rayon;
};

//--------------------------- Autres définitions dépendantes de <Circle>

#endif // CIRCLE_H_
