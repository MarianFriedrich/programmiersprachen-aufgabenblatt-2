#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "bbox.hpp"
#include "vec2.hpp"
#include "color.hpp"
//Cirlce class definition
class Circle {
public:
	Circle(Vec2 const& ctr,float r,Color const& clr);
	//getter:
	float 	area() const;
	float	circumference() const;
	float 	radius() const;
	Color 	color() const;
	Vec2 	center() const;
	Bbox 	bounding_box() const;
	//setter:
	void 	color(Color const& clr);
	void 	center(Vec2 const& ctr);
	void 	radius(float r);
	//Functions:
	//void 	draw() const;
private:
	Vec2 	center_;
	float 	radius_;
	Color 	color_;
};
#endif // CIRCLE_HPP