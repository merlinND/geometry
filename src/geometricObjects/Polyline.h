//---------- Interface de la classe <Polyline> (fichier Polyline.h) ------
#if ! defined ( POLYLINE_H_ )
#define POLYLINE_H_

//--------------------------------------------------- Interfaces utilisées
#include <vector>
using namespace std;

#include "GeometricObject.h"
#include "Point.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Polyline>
//
//
//------------------------------------------------------------------------ 

class Polyline : public GeometricObject
{
//----------------------------------------------------------------- PUBLIC
public:
	
//--------------------------------------------------- Constantes de classe
	static const std::string INITIALS;
//----------------------------------------------------- Méthodes publiques

	string GetRepresentation ( );
	
	void Move ( int dx, int dy );
	void AddPoint ( Point extraPoint );

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
	
	Polyline ( string name );

    virtual ~Polyline ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
	vector <Point> points;
};

//--------------------------- Autres définitions dépendantes de <Polyline>

#endif // POLYLINE_H_
