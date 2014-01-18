//---------- Interface de la classe <Circle> (fichier Circle.h) ------
#if ! defined ( CIRCLE_H_ )
#define CIRCLE_H_

//--------------------------------------------------- Interfaces utilisées
#include <sstream>

#include "Point.h"
#include "GeometricObject.h"
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
	
//--------------------------------------------------- Constantes de classe
	static const std::string INITIALS;
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	string GetRepresentation ( );
	void Move (int dx, int dy);
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

	Circle ( string myCircle, Point theCenter, int R );
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
