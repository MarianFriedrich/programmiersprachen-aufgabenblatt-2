#include "vec2.hpp"
#include "mat2.hpp"
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
//get new vector from addition
Vec2 operator+(Vec2 const& u,Vec2 const& v){
	Vec2 temp = u;
    temp += v;
	return temp;
}
Vec2 operator-(Vec2 const& u,Vec2 const & v){
    Vec2 temp = u;
    temp -= v;
    return temp;
}
Vec2 operator*(Vec2 const& v,float s){
    Vec2 temp = v;
    temp *= s;
    return temp;
}
Vec2 operator/(Vec2 const& v,float s){
    Vec2 temp = v;
    temp = temp / s;
    return temp;
}
Vec2 operator*(float s ,Vec2 const& v){
    Vec2 temp = v;
    temp *= s;
    return temp;
}
//multiplicate with matrix
Vec2 operator*(Mat2 const& m,Vec2 const& v){
    Vec2 result;
    result.x = m.x1 * v.x + m.x2 * v.y;
    result.y = m.y1 * v.x + m.y2 * v.y;
    return result;
}
Vec2 operator*(Vec2 const& v,Mat2 const& m){
    Vec2 result;
    result.x = m.x1 * v.x + m.x2 * v.y;
    result.y = m.y1 * v.x + m.y2 * v.y;
    return result;
}