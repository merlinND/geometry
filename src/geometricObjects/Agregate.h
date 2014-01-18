//---------- Interface de la classe <Agregate> (fichier Agregate.h) ------
#if ! defined ( AGREGATE_H_ )
#define AGREGATE_H_

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <sstream>

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
	
	void AddComponent( int idToAdd );
	IdSet GetComponents ( );
	void RemoveComponent( int idToRemove );
	void RemoveAllComponents ( );
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

	Agregate ( std::string name );
    // Mode d'emploi :
    // Creates an empty agregate object with the given name.
	
    Agregate ( std::string name, vector<int> contained );
    // Mode d'emploi :
    // Creates an agregate with the given name
	// and containing the given ids.

    virtual ~Agregate ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	// A set of all the ids contained in this agregate object
	IdSet agregateComponents;

};

//--------------------------- Autres définitions dépendantes de <Agregate>

#endif // AGREGATE_H_
