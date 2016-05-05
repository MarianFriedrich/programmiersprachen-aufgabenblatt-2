#ifndef MAT2_HPP
#define MAT2_HPP

//mat2 class definition
class Mat2 {
public:
	Mat2();
	Mat2(float x1, float x2, float y1, float y2);

	Mat2& operator*=(Mat2 const& m);
	float det() const{return (x1 * y2) - (y1 * x2);}

	float x1;
	float x2;
	float y1;
	float y2;
};
#endif // MAT2_HPP

Mat2 operator*(Mat2 const& m1,Mat2 const& m2);
Mat2 inverse(Mat2 const& m);
Mat2 transpose(Mat2 const& m);
Mat2 make_rotation_mat2(float phi);