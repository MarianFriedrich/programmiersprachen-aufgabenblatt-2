#include "bbox.hpp"
#include "vec2.hpp"
#include <math.h>


//constructor
Bbox::Bbox(Vec2 const& ctr, float r)
  : center_(ctr), radius_(r)
{}
