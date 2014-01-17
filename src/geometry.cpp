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
	Point p2(3, 4);
	Circle cercle("myCircle", p1, 3);
	cercle.GetRepresentation();

	vector <Point> v;
	v.push_back(p1);
	v.push_back(p2);
	Polyline myPoly ("myPoly", v);
	myPoly.GetRepresentation();
	myPoly.AddPoint(p1);
	myPoly.GetRepresentation();
	
	vector <string> ag;
	ag.push_back("myCircle");
	ag.push_back("myPoly");
	ag.push_back("myPoly2");
	Agregate agregat("myFirstAgregate", ag);
	agregat.AddComponent("myCyrcle");
	agregat.GetRepresentation();
	agregat.Move(1,1);
	agregat.GetRepresentation();

	myPoly.GetRepresentation();
	myPoly.AddPoint(p1);
	
	cout << endl << endl;
	
	Controller * controller = Controller::GetInstance();
	// Basic command prompt
	string text, returnText;
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
			returnText = "ERR";
		}
		
		// When the application exits, it mustn't output anything
		// TODO : suppress output for NoneCommand as well
		if ( !controller->ShouldExit() )
		{
			cout << returnText << endl;
		}
	}
	
	return 0;
}
