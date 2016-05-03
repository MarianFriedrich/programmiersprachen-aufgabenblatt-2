#include "vec2.hpp"
//default constructor
Vec2::Vec2()
  : x(0.0), y(0.0)
{}
//user constructor
Vec2::Vec2(float a,float b)
  : x(a), y(b)
{}
//addition
Vec2& Vec2::operator+=(Vec2 const& v){
    this -> x += v.x;
    this -> y += v.y;
    return  *this;
}
//subtraction
Vec2& Vec2::operator-=(Vec2 const& v){
    this -> x -= v.x;
    this -> y -= v.y;
    return  *this;
}
//multiplication
Vec2& Vec2::operator*=(float v){
    this -> x *= v;
    this -> y *= v;
    return  *this;
}
//division
Vec2& Vec2::operator/(float v){
    this -> x /= v;
    this -> y /= v;
    return  *this;
}
