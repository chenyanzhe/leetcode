#include "catch.hpp"

#include "AddBinary.hpp"

TEST_CASE("Add Binary") {
	AddBinary s;

	SECTION("Sample test") {
		REQUIRE(s.addBinary("11", "1") == "100");
	}

	SECTION("Basic addition") {
		REQUIRE(s.addBinary("0", "1") == "1");
	}
}