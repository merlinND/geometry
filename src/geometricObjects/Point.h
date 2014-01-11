//---------- Interface de la classe <Point> (fichier Point.h) ------
#if ! defined ( POINT_H_ )
#define POINT_H_

struct Point
{
	int x;
	int y;
	
	Point ( int initialX, int initialY )
	{
		x = initialX;
		y = initialY;
	}
};

// A vector in two dimensions is simply composed of two coordinates
typedef	Point Vector2D;

#endif // POINT_H_
