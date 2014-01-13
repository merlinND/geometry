/*************************************************************************
                           Agregate  -  description
                             -------------------
    début                : Jan 13, 2014
    copyright            : (C) 2014 par rbrunat
*************************************************************************/

//---------- Interface de la classe <Agregate> (fichier Agregate.h) ------
#if ! defined ( AGREGATE_H_ )
#define AGREGATE_H_
#include "GeometricObject.h"
using namespace std;
#include <vector>
#include <sstream>

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

//------------------------------------------------- Surcharge d'opérateurs
    Agregate & operator = ( const Agregate & unAgregate );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    /* Agregate ( const Agregate & unAgregate );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
*/
    Agregate (string ,vector <string>);
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
vector <string> agregateComponents;

};

//--------------------------- Autres définitions dépendantes de <Agregate>

#endif // AGREGATE_H_
