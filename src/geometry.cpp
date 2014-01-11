#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
#include "geometricObjects/Circle.h"
#include "geometricObjects/Rectangle.h"
#include "geometricObjects/Line.h"

#include "commands/CommandFactory.h"
#include "commands/AllCommands.h"

int main ( )
{
	// Testing geometric objects representation
	Point center ( 0, 1 );
	Circle cercle( center, 2 );
	cercle.GetRepresentation( );

	Point uLC ( 1, 2 );
	Point lRC ( 0, 2 );
	Rectangle rect ( uLC, lRC );
	rect.GetRepresentation ( );

	Point firstPoint ( 1, 1 );
	Point lastPoint ( 2, 3 );
	Line line ( firstPoint, lastPoint );
	line.GetRepresentation ( );
	
	// Testing CommandFactory & command id auto-increment
	Command & mc = CommandFactory::getInstance()->getCommandFromText("MOVE");
	Command & mc2 = CommandFactory::getInstance()->getCommandFromText("MOVE");
	Command & mc3 = CommandFactory::getInstance()->getCommandFromText("MOVE");
	cout << "Instanciated three commands. Their IDs : "
		<< mc.getCommandId() << ", "
		<< mc2.getCommandId() << ", "
		<< mc3.getCommandId() << "." << endl;
	
	mc.execute();
	
	return 0;
}
