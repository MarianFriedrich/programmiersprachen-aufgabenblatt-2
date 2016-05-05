#include "mat2.hpp"
//default constructor
Mat2::Mat2()
  : x1(1.0), x2(0.0), y1(0.0), y2(1.0)
{}
//user constructor
Mat2::Mat2(float a,float b,float c,float d)
  : x1(a), x2(b), y1(c), y2(d)
{}

//Multiplication
Mat2& Mat2::operator*=(Mat2 const& m){
	Mat2 temp = *this;
	this -> x1 = (temp.x1 * m.x1 + temp.x2 *m.y1);
	this -> x2 = (temp.x1 * m.x2 + temp.x2 *m.y2);
	this -> y1 = (temp.y1 * m.x1 + temp.y2 *m.y1);
	this -> y2 = (temp.y1 * m.x2 + temp.y2 *m.y2);
	return *this;
}

Mat2 operator*(Mat2 const& m1,Mat2 const& m2){
	Mat2 temp = m1;
	temp *= m2;
	return temp;
}