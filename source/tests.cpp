#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

//struct


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
	Vec2 vec{10.0f,10.0f};
	float divident = 5.0;
	vec / divident;
	REQUIRE(vec.x == Approx(2.0f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
