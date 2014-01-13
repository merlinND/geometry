#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
#include "geometricObjects/Circle.h"
#include "geometricObjects/Rectangle.h"
#include "geometricObjects/Line.h"

#include "commands/CommandInterpreter.h"
#include "commands/AllCommands.h"
#include "Controller.h"

int main ( )
{
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
