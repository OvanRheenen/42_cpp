#include "Point.hpp"

Point::Point() :
	x(0),
	y(0)
{
}

Point::Point(const float x, const float y) :
	x(x),
	y(y)
{
}

Point::Point(const Point &pointObject)
{
	*this = pointObject;
}

Point::~Point()
{

}

// getters and setters

Fixed	Point::getX() const
{
	return (x);
}

Fixed	Point::getY() const
{
	return (y);
}