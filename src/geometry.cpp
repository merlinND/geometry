#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
#include "geometricObjects/Circle.h"
#include "geometricObjects/Rectangle.h"
#include "geometricObjects/Line.h"

int main ( )
{

	Point centre;
	centre.x = 0;
	centre.y = 1;
	Circle cercle( centre, 2 );
	cercle.GetRepresentation( );


	Point uLC;
	uLC.x = 1;
	uLC.y = 2;
	Point lRC;
	lRC.x = 0;
	lRC.y = 0;
	Rectangle rect ( uLC, lRC );
	rect.GetRepresentation ( );

	Point firstPoint;
	firstPoint.x = 1;
	firstPoint.y = 1;
	Point lastPoint;
	lastPoint.x = 2;
	lastPoint.y = 3;
	Line line ( firstPoint, lastPoint );
	line.GetRepresentation ( );
	return 0;
}
