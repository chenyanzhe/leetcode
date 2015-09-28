#include "catch.hpp"

#include "Combinations.hpp"

TEST_CASE("Combinations") {
	Combinations s;

	SECTION("Sample test") {
		vector<vector<int>> expected {
			{2, 4}, {3, 4}, {2, 3},
			{1, 2}, {1, 3}, {1, 4}
		};

		vector<vector<int>> results = s.combine(4, 2);

		REQUIRE(results.size() == expected.size());

		for (auto &r : results)
			sort(r.begin(), r.end());
		
		for (auto comb : expected)
			REQUIRE_FALSE(find(results.begin(), results.end(), comb) == results.end());
	}
}