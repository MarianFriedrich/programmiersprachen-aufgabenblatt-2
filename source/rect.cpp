#include "rect.hpp"
#include "vec2.hpp"
#include <math.h>


//constructor
Rect::Rect()
  : center_(Vec2{0.0,0.0}), color_{0.0,0.0,0.0}, right_(5.0f), down_(5.0f)
{}
Rect::Rect(Vec2 const& ctr, Color const& clr, float r, float d)
  : center_(ctr), color_{clr}, right_(r), down_(d)
{}

//umfang
float Rect::circumference() const{
	Rect temp = *this;
	return (2 * temp.right_) + (2 * temp.down_);
}