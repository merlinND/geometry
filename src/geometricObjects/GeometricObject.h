//---------- Interface de la classe <GeometricObject> (fichier GeometricObject.h) ------
#if ! defined ( GEOMETRICOBJECT_H_ )
#define GEOMETRICOBJECT_H_
#include <string>

//--------------------------------------------------- Interfaces utilisées
#include <set>
//------------------------------------------------------------- Constantes 
//------------------------------------------------------------------ Types
typedef long TId;
typedef set<TId> IdSet;

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
	TId GetId ( );
	string const GetInitials ( );
	virtual string GetRepresentation ( ) = 0;
	
	virtual void Move ( long dx, long dy ) = 0;

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
	string initials;
	
	static TId objectIdCounter;
	TId objectId;
	
	
	int lastAppliedCommandId;
};

//--------------------------- Autres définitions dépendantes de <GeometricObject>

#endif // GEOMETRICOBJECT_H_
