#ifndef RECT_HPP
#define RECT_HPP
#include "vec2.hpp"
//Cirlce class definition
class Rect{
public:
	Rect();
	Rect(Vec2 const& ctr,float r,float d);
	Vec2 	center_;
	float 	right;
	float 	down;
};
#endif // RECT_HPP