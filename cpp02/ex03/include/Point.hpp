#ifndef	POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point
{
private:

	Fixed const	x;
	Fixed const	y;

public:

	Point();
	Point(const float x, const float y);
	Point(const Point &pointObject);
	~Point();

	Point	&operator=(const Point &pointObject);

	Fixed	getX() const;
	Fixed	getY() const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif