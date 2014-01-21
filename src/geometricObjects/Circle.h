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
	string GetRepresentation ( );
	void Move (int dx, int dy);

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

	Circle ( string myCircle, Point theCenter, int R );

	virtual ~Circle ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Point center;
	int radius;
};

//--------------------------- Autres définitions dépendantes de <Circle>

#endif // CIRCLE_H_
