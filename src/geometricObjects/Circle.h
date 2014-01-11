//---------- Interface de la classe <Circle> (fichier Circle.h) ------
#if ! defined ( CIRCLE_H_ )
#define CIRCLE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Point.h"
#include "GeometricObject.h"

#include <sstream>
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

	Circle ( Point theCenter, int R );
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
	int radius;
};

//--------------------------- Autres définitions dépendantes de <Circle>

#endif // CIRCLE_H_
