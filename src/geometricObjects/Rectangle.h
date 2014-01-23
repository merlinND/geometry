//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if ! defined ( RECTANGLE_H_ )
#define RECTANGLE_H_

//--------------------------------------------------- Interfaces utilisées
#include "GeometricObject.h"
#include "Point.h"

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
	
//--------------------------------------------------- Constantes de classe
	static const std::string INITIALS;
//----------------------------------------------------- Méthodes publiques
	std::string GetRepresentation ( );
	void Move ( long dx, long dy );

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	Rectangle ( std::string myRectangle, Point uLC, Point lRC );

	virtual ~Rectangle ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Point upperLeftCorner;
	Point lowerRightCorner;
};

//--------------------------- Autres définitions dépendantes de <Rectangle>

#endif // RECTANGLE_H_
