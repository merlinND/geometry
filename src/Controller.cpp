//-- Réalisation de la classe <Controller> (fichier Controller.cpp)
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Controller.h"
#include "geometricObjects/AllGeometricObjects.h"
//------------------------------------------------------------- Constantes
// Initializing static fields
Controller * Controller::theInstance = NULL;
const TId Controller::NOT_FOUND = -1;

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

Controller * Controller::GetInstance( )
{
	if ( NULL == theInstance )
	{
		theInstance = new Controller;
	}
	else
	{
#ifdef MAP
		cout << "Accès à l'unique instance de <Controller>" << endl;
#endif
	}
	return theInstance;
} // ----- End getInstance

string Controller::ProcessCommand ( Command * command )
{
	string status = command->Execute();
	 
	if ( command->IsHistorizable() && status != Command::STATUS_ERROR )
	{
		history.AddCommand( (HistorizableCommand *) command );
	}
	
	return status;
} //----- End ProcessCommand

Circle * Controller::CreateCircle( string name, Point center, int radius)
{
	Circle * circle = new Circle( name, center, radius );
	allObjects[ circle->GetId() ] = circle;
	return circle;
} //----- End CreateCircle
Line * Controller::CreateLine( string name, Point begin, Point end)
{
	Line * line = new Line( name, begin, end );
	allObjects[ line->GetId() ] = line;
	return line;
} //----- End CreateLine
Polyline * Controller::CreatePolyline( string name )
{
	Polyline * polyline = new Polyline( name );
	allObjects[ polyline->GetId() ] = polyline;
	return polyline;
} //----- End CreatePolyline
Rectangle * Controller::CreateRectangle( string name, Point ulc, Point lrc )
{
	Rectangle * rectangle = new Rectangle( name, ulc, lrc );
	allObjects[ rectangle->GetId() ] = rectangle;
	return rectangle;
} //----- End CreateRectangle
Agregate * Controller::CreateAgregate( string name )
{
	Agregate * agregate = new Agregate ( name );
	allObjects[ agregate->GetId() ] = agregate;
	return agregate;
} //----- End CreateAgregate


void Controller::Undo()
{
	history.Undo();
}
void Controller::Redo()
{
	history.Redo();
}

IdSet Controller::GetAllIdsInDocument ( )
{
	return model.GetComponents();
}
IdSet Controller::GetAllAgregatesInDocument ( )
{
	IdSet all = GetAllIdsInDocument();
	IdSet agregatesOnly;
	for ( IdSet::iterator it = all.begin();
		 it != all.end(); ++it )
	{
		if ( GetObjectById( *it)->GetInitials() == Agregate::INITIALS )
		{
			agregatesOnly.insert( *it );
		}
	}
	return agregatesOnly;
}

vector<string> Controller::GetSortedRepresentations ( )
{
	// In order to output a sorted list of GeometricObjects representation,
	// we use a map (keys being the object's name).
	map<string, string, customAlphabeticalComparer> sortedMap;
	IdSet components = GetAllIdsInDocument();
	GeometricObject * currentObject;
	for ( IdSet::iterator it = components.begin();
		it != components.end(); ++it ) {
		currentObject = GetObjectById( *it );
		sortedMap[currentObject->GetName()] = currentObject->GetRepresentation();
	}
	vector<string> result;
	for ( map<string, string, customAlphabeticalComparer>::iterator it = sortedMap.begin();
		 it != sortedMap.end(); ++it)
	{
		result.push_back( it->second );
	}
	return result;
}

GeometricObject * Controller::GetObjectById ( TId idToFind )
{
	GeometricMap::iterator it = allObjects.find( idToFind );
	if ( it != allObjects.end() )
	{
		return it->second;
	}
	else
	{
		return NULL;
	}
} //----- End GetObjectByName

string Controller::GetNameById ( TId idToFind )
{
	GeometricMap::iterator found = allObjects.find( idToFind );
	if ( found != allObjects.end() )
	{
		return found->second->GetName();
	}
	else
	{
		return NULL;
	}
} //----- End GetNameById

TId Controller::GetIdByName( string name )
{
	IdSet components = model.GetComponents();
	for ( IdSet::iterator it = components.begin();
		 it != components.end(); ++it )
	{
		if ( GetObjectById( *it )->GetName() == name )
		{
			return *it;
		}
	}
	return NOT_FOUND;
} //----- End GetNameById


bool Controller::IsNameUsedInDocument( string name )
{
	bool found = false;
	IdSet idsInDocument = model.GetComponents();
	GeometricObject * current;
	IdSet::iterator it = idsInDocument.begin();
	while ( !found && it != idsInDocument.end() )
	{
		current = GetObjectById( *it );
		found = found || ( current->GetName() == name );
		++it;
	}
	return found;
}

void Controller::RemoveObjectFromDocument( TId idToRemove )
{
	model.RemoveComponent( idToRemove );
}
void Controller::AddIdToDocument( TId idToAdd )
{
	model.AddComponent( idToAdd );
}
IdSet Controller::ClearDocument ( )
{
	IdSet removedIds = model.GetComponents();
	model.RemoveAllComponents();
	return removedIds;
}

bool Controller::ShouldExit()
{
	return exitFlag;
}
void Controller::Exit()
{
	exitFlag = true;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

Controller::~Controller ( )
{
#ifdef MAP
	cout << "Appel au destructeur de <Controller>" << endl;
#endif
	
	for ( GeometricMap::iterator it = allObjects.begin();
		 it != allObjects.end(); ++it )
	{
		delete it->second;
	}
} //----- Fin de ~Controller

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées

Controller::Controller ( ) : model( "__document__" ), exitFlag( false )
{
#ifdef MAP
	cout << "Appel au constructeur de <Controller>" << endl;
#endif
} //----- Fin de Controller
