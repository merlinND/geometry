#if ! defined ( LINE_H_ )
#define LINE_H_


//--------------------------------------------------- Interfaces utilisées
#include "Point.h"
#include "GeometricObject.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Line>
//
//
//------------------------------------------------------------------------ 

class Line : public GeometricObject
{
//----------------------------------------------------------------- PUBLIC
public:
	
//--------------------------------------------------- Constantes de classe
	static const std::string INITIALS;
//----------------------------------------------------- Méthodes publiques
	
	std::string GetRepresentation ( );
	void Move (long dx, long dy);

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	Line ( std::string name, Point begin, Point end );

	virtual ~Line ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Point first;
	Point last;
};

//--------------------------- Autres définitions dépendantes de <Line>

#endif // Line_H_
