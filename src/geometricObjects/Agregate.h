//---------- Interface de la classe <Agregate> (fichier Agregate.h) ------
#if ! defined ( AGREGATE_H_ )
#define AGREGATE_H_

//--------------------------------------------------- Interfaces utilisées
#include <vector>

#include "GeometricObject.h"
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
	
//--------------------------------------------------- Constantes de classe
	static const std::string INITIALS;
//----------------------------------------------------- Méthodes publiques
	
	string GetRepresentation ( );
	// Mode d'emploi :
    //
    // Contrat :
    //
	
	void Move ( int dx, int dy );
	
	void AddComponent( TId idToAdd );
	IdSet GetComponents ( );
	bool Contains ( TId idToFind );
	
	void RemoveComponent( TId idToRemove );
	void RemoveAllComponents ( );
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

	Agregate ( std::string name );
    // Mode d'emploi :
    // Creates an empty agregate object with the given name.
	
    virtual ~Agregate ( );

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	// A set of all the ids contained in this agregate object
	IdSet agregateComponents;

};
//--------------------------- Autres définitions dépendantes de <Agregate>

#endif // AGREGATE_H_
