//---------- Interface de la classe <Point> (fichier Point.h) ------
#if ! defined ( POINT_H_ )
#define POINT_H_

#include <sstream>

struct Point
{
	long x;
	long y;
	
	Point ( long initialX, long initialY )
	{
		x = initialX;
		y = initialY;
	}

	Point ( )
	{
		x = 0;
		y = 0;
	}
	
	std::string GetRepresentation ( )
	{
		ostringstream os;
		os << x;
		os << " ";
		os << y;
		return os.str();
	}
	
	void Reverse ( )
	{
		x = -x;
		y = -y;
	}
};

// A vector in two dimensions is simply composed of two coordinates
typedef	Point Vector2D;

#endif // POINT_H_
