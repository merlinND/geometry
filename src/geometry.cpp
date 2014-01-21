#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
#include "geometricObjects/Circle.h"
#include "geometricObjects/Rectangle.h"
#include "geometricObjects/Line.h"
#include "geometricObjects/Polyline.h"
#include "geometricObjects/Agregate.h"

#include "commands/CommandInterpreter.h"
#include "commands/AllCommands.h"
#include "Controller.h"

int main ( )
{
	Controller * controller = Controller::GetInstance();
	
	Point p1(1, 2);
	Point p2(3, 4);
	Point p3(-1, -5);
	Point p4(0, 0);
	
	GeometricObject * circle = controller->CreateCircle( "myCircle", p1, 3);
	controller->AddIdToDocument( circle->GetId() );
	
	GeometricObject * line = controller->CreateLine( "myLine", p1, p2);
	controller->AddIdToDocument( line->GetId() );
	
	Polyline * poly = controller->CreatePolyline( "myPoly" );
	poly->AddPoint( p1 );
	poly->AddPoint( p2 );
	poly->AddPoint( p3 );
	controller->AddIdToDocument( line->GetId() );
	
	GeometricObject * rectangle = controller->CreateRectangle( "myRectangle", p4, p3);
	controller->AddIdToDocument( rectangle->GetId() );
	
	Agregate * agregate = controller->CreateAgregate( "myAgregate" );
	agregate->AddComponent( circle->GetId() );
	agregate->AddComponent( line->GetId() );
	agregate->AddComponent( poly->GetId() );
	controller->AddIdToDocument( agregate->GetId() );

	// Basic command prompt
	string returnText;
	Command * currentCommand = NULL;
	while ( !controller->ShouldExit() )
	{
		// TODO: remove this prompt sign before delivery
		cout << "> ";
		
		currentCommand = CommandInterpreter::InterpretCommand( cin );
		
		if ( NULL != currentCommand )
		{
			returnText = controller->ProcessCommand( currentCommand );
		}
		else
		{
			returnText = Command::STATUS_ERROR;
		}
		
		if ( returnText.length() > 0 )
		{
			cout << returnText << endl;
		}
	}
	
	return 0;
}
