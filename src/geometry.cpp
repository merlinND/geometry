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

	Point p1(1, 2);
	Circle cercle("myCircle", p1, 3);
	cercle.GetRepresentation();
	vector <Point> v;
	v.push_back(p1);
	v.push_back(p1);
	vector <string>ag;

	ag.push_back("myCircle");
	Agregate agregat("myFirstAgregate", ag);
	cout << "hu" << v[0].x << endl;
	agregat.GetRepresentation();

	Polyline myPoly ("myPoly", v);

	myPoly.GetRepresentation();
	myPoly.AddPoint(p1);

	Controller * controller = Controller::GetInstance();
	// Basic command prompt
	string text, returnText;
	Command * currentCommand = NULL;
	while ( !controller->ShouldExit() )
	{
		cout << "> ";
		
		currentCommand = CommandInterpreter::InterpretCommand( cin );
		if ( NULL != currentCommand )
		{
			returnText = controller->ProcessCommand( currentCommand );
		}
		else
		{
			returnText = "ERR";
		}
		
		// When the application exits, it mustn't output anything
		if ( !controller->ShouldExit() )
		{
			cout << returnText << endl;
		}
	}
	
	return 0;
}
