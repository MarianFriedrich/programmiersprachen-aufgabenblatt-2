#ifndef RECT_HPP
#define RECT_HPP
#include "vec2.hpp"
#include "color.hpp"
//Cirlce class definition
class Rect{
public:
	Rect();
	Rect(Vec2 const& ctr, Color const& clr, float r,float d);

	float	circumference() const;

	Vec2 	center_;
	Color 	color_;
	float 	right_;
	float 	down_;
};
#endif // RECT_HPP