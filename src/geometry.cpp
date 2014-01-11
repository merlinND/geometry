#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
#include "geometricObjects/Circle.h"
#include "geometricObjects/Rectangle.h"
#include "geometricObjects/Line.h"

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
	return 0;
}
