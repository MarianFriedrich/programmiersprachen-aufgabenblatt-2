#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "bbox.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"

/*
 *	Vector
 */
TEST_CASE("describe_struct","[struct]")
{
	Vec2 origin;
	REQUIRE(origin.x == 0.0f);
	REQUIRE(origin.y == 0.0f);
}
TEST_CASE("describe_user_constructor","[user_constructor]")
{
	Vec2 user_constructor{1.2f,1.5f};
	REQUIRE(user_constructor.x == Approx(1.2f));
	REQUIRE(user_constructor.y == Approx(1.5f));
}
TEST_CASE("describe_addition","[addition]")
{
	Vec2 one{5.5f,3.5f};
	Vec2 two{2.5f,1.0f};
	one += two;
	REQUIRE(one.x == Approx(8.0f));
	REQUIRE(one.y == Approx(4.5f));
}
TEST_CASE("describe_subtraction","[subtraction]")
{
	Vec2 one{4.5f,4.5f};
	Vec2 two{1.5f,1.5f};
	one -= two;
	REQUIRE(one.x == Approx(3.0f));
	REQUIRE(one.y == Approx(3.0f));
}
TEST_CASE("describe_multiplication","[multiplication]")
{
	Vec2 vec{1.5f,1.5f};
	float multiplicator = 2.0;
	vec *= multiplicator;
	REQUIRE(vec.x == Approx(3.0f));
}
TEST_CASE("describe_division","[division]")
{
	Vec2 vec{10.0f,25.0f};
	float divident = 5.0;
	vec / divident;
	REQUIRE(vec.x == Approx(2.0f));
	REQUIRE(vec.y == Approx(5.0f));
}
TEST_CASE("describe_free_addition","[free_addition]")
{
	Vec2 one{5.0f,5.0f};
	Vec2 two{2.5f,3.5f};
	Vec2 result = one + two;
	REQUIRE(result.x == Approx(7.5f));
	REQUIRE(result.y == Approx(8.5f));
}
TEST_CASE("describe_free_subtraction","[free_subtraction]")
{
	Vec2 one{5.0f,5.0f};
	Vec2 two{2.5f,3.5f};
	Vec2 result = one - two;
	REQUIRE(result.x == Approx(2.5f));
	REQUIRE(result.y == Approx(1.5f));
}
TEST_CASE("describe_free_multiplication","[free_multiplication]")
{
	Vec2 one{5.0f,6.0f};
	float x = 2.0f;
	Vec2 result = one * x;
	REQUIRE(result.x == Approx(10.0f));
	REQUIRE(result.y == Approx(12.0f));
}
TEST_CASE("describe_free_multiplication_rev","[free_multiplication_rev]")
{
	Vec2 one{5.0f,6.0f};
	float x = 2.0f;
	Vec2 result = x * one;
	REQUIRE(result.x == Approx(10.0f));
	REQUIRE(result.y == Approx(12.0f));
}
TEST_CASE("describe_free_division","[free_division]")
{
	Vec2 one{5.0f,6.0f};
	float x = 2.0f;
	Vec2 result = one / x;
	REQUIRE(result.x == Approx(2.5f));
	REQUIRE(result.y == Approx(3.0f));
}
/*
 *	Matrix
 */
TEST_CASE("describe_struct_mat","[struct_mat]")
{
	Mat2 origin{};
	REQUIRE(origin.x1 == 1.0f);
	REQUIRE(origin.x2 == 0.0f);
	REQUIRE(origin.y1 == 0.0f);
	REQUIRE(origin.y2 == 1.0f);
}
TEST_CASE("describe_user_constructor_mat","[user_constructor_mat]")
{
	Mat2 user_constructor{1.0f,1.5f,2.0f,2.5f};
	REQUIRE(user_constructor.x1 == Approx(1.0f));
	REQUIRE(user_constructor.x2 == Approx(1.5f));
	REQUIRE(user_constructor.y1 == Approx(2.0f));
	REQUIRE(user_constructor.y2 == Approx(2.5f));
}
TEST_CASE("describe_mat_multiplication","[mat_multiplication]")
{
	Mat2 one{5.0f,3.0f,2.0f,4.0f};
	Mat2 two{1.0f,6.0f,4.0f,3.0f};
	one *= two;
	REQUIRE(one.x1 == Approx(17.0f));
	REQUIRE(one.x2 == Approx(39.0f));
	REQUIRE(one.y1 == Approx(18.0f));
	REQUIRE(one.y2 == Approx(24.0f));
}
TEST_CASE("describe_mat_multiplication_free","[mat_multiplication_free]")
{
	Mat2 one{5.0f,3.0f,2.0f,4.0f};
	Mat2 two{1.0f,6.0f,4.0f,3.0f};
	Mat2 result;
	result = one * two;
	REQUIRE(result.x1 == Approx(17.0f));
	REQUIRE(result.x2 == Approx(39.0f));
	REQUIRE(result.y1 == Approx(18.0f));
	REQUIRE(result.y2 == Approx(24.0f));
}
TEST_CASE("describe_multiplication_vec_mat","[multiplication_vec_mat]")
{
	Mat2 one{1.0f,2.0f,3.0f,4.0f};
	Vec2 two{1.0f,2.0f};
	Vec2 result;
	result = one * two;
	REQUIRE(result.x == Approx(5.0f));
	REQUIRE(result.y == Approx(11.0f));
}
TEST_CASE("describe_multiplication_vec_mat_rev","[multiplication_vec_mat_rev]")
{
	Mat2 one{1.0f,2.0f,3.0f,4.0f};
	Vec2 two{1.0f,2.0f};
	Vec2 result;
	result = two * one;
	REQUIRE(result.x == Approx(5.0f));
	REQUIRE(result.y == Approx(11.0f));
}
TEST_CASE("describe_mat_inverse","[mat_inverse]")
{
	Mat2 regular{1.0f,2.0f,3.0f,4.0f};
	Mat2 inv;
	inv = inverse(regular);
	REQUIRE(inv.x1 == Approx(-2.0f));
	REQUIRE(inv.x2 == Approx(1.0f));
	REQUIRE(inv.y1 == Approx(1.5f));
	REQUIRE(inv.y2 == Approx(-0.5f));
}
TEST_CASE("describe_mat_transpose","[mat_transpose]")
{
	Mat2 regular{1.0f,2.0f,3.0f,4.0f};
	Mat2 trans;
	trans = transpose(regular);
	REQUIRE(trans.x1 == Approx(1.0f));
	REQUIRE(trans.x2 == Approx(3.0f));
	REQUIRE(trans.y1 == Approx(2.0f));
	REQUIRE(trans.y2 == Approx(4.0f));
}
TEST_CASE("describe_mat_rotation","[mat_rotation]")
{
	Mat2 regular{1.0f,2.0f,3.0f,4.0f};
	Mat2 rotation = make_rotation_mat2(180);
	regular *= rotation;
	REQUIRE(regular.x1 == Approx(-2.20077f));
	REQUIRE(regular.x2 == Approx(-0.395768f));
	REQUIRE(regular.y1 == Approx(-4.99999f));
	REQUIRE(regular.y2 == Approx( 0.009618f));
}
TEST_CASE("describe_mat_determinante","[mat_determinante]")
{
	Mat2 regular{1.0f,2.0f,3.0f,4.0f};
	float dete = regular.det();
	REQUIRE(dete == Approx(-2.0f));
}
/*
 * COLOR
 */
TEST_CASE("describe_color_black","[color_black]")
{
	Color black{0.0f};
	REQUIRE(black.r == Approx(0.0f));
	REQUIRE(black.g == Approx(0.0f));
	REQUIRE(black.b == Approx(0.0f));
}
TEST_CASE("describe_color_red","[color_red]")
{
	Color red{1.0f,0.0f,0.0f};
	REQUIRE(red.r == Approx(1.0f));
	REQUIRE(red.g == Approx(0.0f));
	REQUIRE(red.b == Approx(0.0f));
}
TEST_CASE("describe_color_white","[color_red]")
{
	Color white{};
	REQUIRE(white.r == Approx(1.0f));
	REQUIRE(white.g == Approx(1.0f));
	REQUIRE(white.b == Approx(1.0f));
}
/*
 *	Circle
 */
//Get Area
TEST_CASE("describe_circle_get_area","[circle_get_area]")
{
	float radius = 10.0;
	Vec2 point{5.0,5.0};
	Color farbe{1.0,1.0,0.0};

	Circle kreis{point,radius,farbe};
	REQUIRE(kreis.area() == Approx(314.159f));
}
//Get Radius
TEST_CASE("describe_circle_get_radius","[circle_get_radius]")
{
	float radius = 10.0;
	Vec2 point{5.0,5.0};
	Color farbe{1.0,1.0,0.0};
	Circle kreis{point,radius,farbe};
	REQUIRE(kreis.radius() == Approx(10.0f));
}
//Get Color
TEST_CASE("describe_circle_get_color","[circle_get_color]")
{
	float radius = 10.0;
	Vec2 point{5.0,5.0};
	Color farbe{1.0,1.0,0.0};
	Circle kreis{point,radius,farbe};
	Color test;
	test = kreis.color();
	REQUIRE(test.r == farbe.r);
	REQUIRE(test.g == farbe.g);
	REQUIRE(test.b == farbe.b);
}
//Get Center
TEST_CASE("describe_circle_get_center","[circle_get_center]")
{
	float radius = 10.0;
	Vec2 point{5.0,5.0};
	Color farbe{1.0,1.0,0.0};
	Circle kreis{point,radius,farbe};
	Vec2 test;
	test = kreis.center();
	REQUIRE(test.x == point.x);
	REQUIRE(test.y == point.y);
}
//Bounding box constructor
TEST_CASE("describe_bbox_const","[bbox_const]")
{
	float radius = 10.0;
	Vec2 point{5.0,5.0};
	Bbox test{point,radius};
	REQUIRE(test.center_.x == point.x);
	REQUIRE(test.center_.y == point.y);
	REQUIRE(test.radius_ == 10.0);
}
TEST_CASE("describe_circle_get_bbox","[circle_get_bbox]")
{
	float radius = 10.0;
	Vec2 point{5.0,5.0};
	Color farbe{1.0,1.0,0.0};
	Circle kreis{point,radius,farbe};

	Bbox test{point,radius};
	Bbox get = kreis.bounding_box();
	REQUIRE(get.center_.x == test.center_.x);
	REQUIRE(get.center_.y == test.center_.x);
	REQUIRE(get.radius_   == test.radius_);
}
//SET RADIUS
TEST_CASE("describe_circle_set_radius","[circle_set_radius]")
{
	float radius = 10.0;
	Vec2 point{5.0,5.0};
	Color farbe{1.0,1.0,0.0};
	Circle kreis{point,radius,farbe};
	kreis.radius(50.0);
	REQUIRE(kreis.radius() == Approx(50.0f));
}
//set Color
TEST_CASE("describe_circle_set_color","[circle_set_color]")
{
	float radius = 10.0;
	Vec2 point{5.0,5.0};
	Color farbe{1.0,1.0,0.0};
	Circle kreis{point,radius,farbe};
	Color farbe2{0.5,1.0,0.5};
	kreis.color(farbe2);
	REQUIRE(kreis.color().r == farbe2.r);
	REQUIRE(kreis.color().g == farbe2.g);
	REQUIRE(kreis.color().b == farbe2.b);
}
//set Center
TEST_CASE("describe_circle_set_center","[circle_set_center]")
{
	float radius = 10.0;
	Vec2 point{5.0,5.0};
	Color farbe{1.0,1.0,0.0};
	Circle kreis{point,radius,farbe};
	Vec2 point2{1.0,1.0};
	REQUIRE(kreis.center().x == point.x);
	REQUIRE(kreis.center().y == point.y);
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
