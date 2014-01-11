/*************************************************************************
                           GeometricObject  -  description
                             -------------------
    début                : 6 janv. 2014
    copyright            : (C) 2014 par rbrunat
*************************************************************************/

//---------- Interface de la classe <GeometricObject> (fichier GeometricObject.h) ------
#if ! defined ( GEOMETRICOBJECT_H_ )
#define GEOMETRICOBJECT_H_
#include <string>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <GeometricObject>
//
//
//------------------------------------------------------------------------ 

class GeometricObject
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
virtual string GetRepresentation() =0;

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    GeometricObject ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GeometricObject ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	int lastAppliedCommandId;
};

//--------------------------- Autres définitions dépendantes de <GeometricObject>

#endif // GEOMETRICOBJECT_H_
