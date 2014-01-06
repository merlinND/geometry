#include <iostream>
#include <vector>
using namespace std;
#include "Circle.h"
#include "Rectangle.h"
int main ( )
{

	Point centre;
	centre.x = 0;
	centre.y = 1;
	Circle cercle( centre, 2 );
	cercle.GetRepresentation( );


	Point uLC;
	uLC.x=1;
	uLC.y=2;
	Point lRC;
	lRC.x=0;
	lRC.y=0;
	Rectangle rect (uLC, lRC);
	rect.GetRepresentation ( );


	return 0;
}
