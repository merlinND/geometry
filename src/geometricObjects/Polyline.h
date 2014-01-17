//---------- Interface de la classe <Polyline> (fichier Polyline.h) ------
#if ! defined ( POLYLINE_H_ )
#define POLYLINE_H_

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <sstream>
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
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	string GetRepresentation ( );
	void Move (int dx, int dy);
	void AddPoint (Point);

//------------------------------------------------- Surcharge d'opérateurs
    Polyline & operator = ( const Polyline & unPolyline );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Polyline ( const Polyline & unPolyline );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

	Polyline ( string name );
    // Mode d'emploi :
    //
    // Contrat :
    //
	
    Polyline ( string name, vector<Point> points );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Polyline ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
vector <Point> points;
};

//--------------------------- Autres définitions dépendantes de <Polyline>

#endif // POLYLINE_H_
