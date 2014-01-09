/*************************************************************************
 Line  -  description
 -------------------
 début                : 9 janv. 2014
 copyright            : (C) 2014 par rbrunat
 *************************************************************************/

//---------- Interface de la classe <Line> (fichier Line.h) ------
#if ! defined ( LINE_H_ )
#define LINE_H_
#include "Point.h"
#include "GeometricObject.h"

//--------------------------------------------------- Interfaces utilisées

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
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//
	String GetRepresentation ( );

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

	Line ( Point , Point );
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
