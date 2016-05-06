#include "rect.hpp"
#include "vec2.hpp"
#include <math.h>


//constructor
Rect::Rect()
  : center_(Vec2{0.0,0.0}), right(5.0f), down(5.0f)
{}
Rect::Rect(Vec2 const& ctr, float r, float d)
  : center_(ctr), right(r), down(d)
{}
