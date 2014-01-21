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

	// Basic command prompt
	string returnText;
	Command * currentCommand = NULL;
	while ( !controller->ShouldExit() )
	{
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
