/*************************************************************************
 Agregate  -  description
 -------------------
 début                : 6 janv. 2014
 copyright            : (C) 2014 par rbrunat
 *************************************************************************/

//---------- Interface de la classe <Agregate> (fichier Agregate.h) ------
#if ! defined ( Agregate_H_ )
#define Agregate_H_
#include "Point.h"
#include "GeometricObject.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Agregate>
//
//
//------------------------------------------------------------------------

class Agregate : public GeometricObject
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
	bool AddObject ( GeometricObject );
//------------------------------------------------- Surcharge d'opérateurs
	Agregate & operator = ( const Agregate & unAgregate );
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	Agregate ( const Agregate & unAgregate );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Agregate ( Point uLC, Point lRC );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Agregate ( );
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

//--------------------------- Autres définitions dépendantes de <Agregate>

#endif // Agregate_H_
