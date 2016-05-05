#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

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

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
