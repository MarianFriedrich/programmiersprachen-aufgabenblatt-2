#ifndef BBOX_HPP
#define BBOX_HPP
#include "vec2.hpp"
//Cirlce class definition
class Bbox{
public:
	Bbox(Vec2 const& ctr,float r);
	Vec2 	center_;
	float 	radius_;
};
#endif // BBOX_HPP