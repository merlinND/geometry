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
const int Controller::NOT_FOUND = -1;

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
	model.AddComponent( circle->GetId() );
	return circle;
} //----- End CreateCircle
Line * Controller::CreateLine( string name, Point begin, Point end)
{
	Line * line = new Line( name, begin, end );
	allObjects[ line->GetId() ] = line;
	model.AddComponent( line->GetId() );
	return line;
} //----- End CreateLine
Polyline * Controller::CreatePolyline( string name )
{
	Polyline * polyline = new Polyline( name );
	allObjects[ polyline->GetId() ] = polyline;
	model.AddComponent( polyline->GetId() );
	return polyline;
} //----- End CreatePolyline
Rectangle * Controller::CreateRectangle( string name, Point ulc, Point lrc )
{
	Rectangle * rectangle = new Rectangle( name, ulc, lrc );
	allObjects[ rectangle->GetId() ] = rectangle;
	model.AddComponent( rectangle->GetId() );
	return rectangle;
} //----- End CreateRectangle
Agregate * Controller::CreateAgregate( string name )
{
	Agregate * agregate = new Agregate ( name );
	allObjects[ agregate->GetId() ] = agregate;
	model.AddComponent( agregate->GetId() );
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

GeometricObject * Controller::GetObjectById ( int idToFind )
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

string Controller::GetNameById ( int idToFind )
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

int Controller::GetIdByName( string name )
{
	IdSet components = model.GetComponents();
	IdSet::iterator it = components.begin();
	GeometricObject * currentObject;
	while ( it != components.end() )
	{
		currentObject = GetObjectById( *it );
		if ( currentObject->GetName() == name )
		{
			return *it;
		}
		++it;
	}
	return NOT_FOUND;
} //----- End GetNameById


bool Controller::IsNameUsedInDocument( string name )
{
	return true;
	// TODO : use the agregate's method to return the result
	//return model.HasObjectWithName( name );
}

void Controller::RemoveObjectFromDocument( int idToRemove )
{
	model.RemoveComponent( idToRemove );
}
void Controller::AddObjectBackInDocument( int idToAdd )
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
} //----- Fin de ~Controller

//------------------------------------------------------------------ PRIVÉ

//----------------------------------------------------- Méthodes protégées

Controller::Controller ( ) : model( "__document__" ), exitFlag( false )
{
#ifdef MAP
	cout << "Appel au constructeur de <Controller>" << endl;
#endif
} //----- Fin de Controller
