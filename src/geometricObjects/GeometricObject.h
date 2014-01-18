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
	
//--------------------------------------------------- Constantes de classe
//----------------------------------------------------- Méthodes publiques

	string GetName ( );
	int GetId ( );
	string const GetInitials ( );
	virtual string GetRepresentation ( ) = 0;
	
	virtual void Move ( int dx, int dy ) = 0;

	int GetLastAppliedCommandId ( );
	void SetLastAppliedCommandId ( int commandId );
	
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    GeometricObject ( string name, string initials );
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
	
	string name;
	int objectId;
	string initials;
	
	static int objectIdCounter;
	int lastAppliedCommandId;
};

//--------------------------- Autres définitions dépendantes de <GeometricObject>

#endif // GEOMETRICOBJECT_H_
