//---------- Interface de la classe <GeometricObject> (fichier GeometricObject.h) ------
#if ! defined ( GEOMETRICOBJECT_H_ )
#define GEOMETRICOBJECT_H_
#include <string>

//--------------------------------------------------- Interfaces utilisées
#include <set>
//------------------------------------------------------------- Constantes 
//------------------------------------------------------------------ Types
typedef set<int> IdSet;

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

	string GetName ( );
	int GetId ( );
	virtual string GetRepresentation ( ) = 0;
	
	virtual void Move ( int dx, int dy ) = 0;

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    GeometricObject ( string );
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
	int objectId;
	static int objectIdCounter;
	string name;
};

//--------------------------- Autres définitions dépendantes de <GeometricObject>

#endif // GEOMETRICOBJECT_H_
