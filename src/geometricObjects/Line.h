#if ! defined ( LINE_H_ )
#define LINE_H_


//--------------------------------------------------- Interfaces utilisées
#include <sstream>

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
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//
	string GetRepresentation ( );
	void Move (int dx, int dy);

//------------------------------------------------- Surcharge d'opérateurs
	Line & operator = ( const Line & unLine );
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	Line ( const Line & unLine );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Line ( string , Point , Point );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Line ( );
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

	Point first;
	Point last;
};

//--------------------------- Autres définitions dépendantes de <Line>

#endif // Line_H_
