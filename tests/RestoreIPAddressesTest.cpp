#include "catch.hpp"

#include "RestoreIPAddresses.hpp"

#include <algorithm>
using namespace std;

TEST_CASE("Restore IP Addresses") {
	RestoreIPAddresses s;

	SECTION("Sample test") {
		vector<string> expected {"255.255.11.135", "255.255.111.35"};
		vector<string> result = s.restoreIpAddresses("25525511135");
		REQUIRE(result.size() == expected.size());
		for (int i = 0; i < result.size(); i++)
			REQUIRE_FALSE(find(expected.begin(), expected.end(), result[i]) == expected.end());
	}

	SECTION("Corner case") {
		vector<string> expected {"0.10.0.10", "0.100.1.0"};
		vector<string> result = s.restoreIpAddresses("010010");
		REQUIRE(result.size() == expected.size());
		for (int i = 0; i < result.size(); i++)
			REQUIRE_FALSE(find(expected.begin(), expected.end(), result[i]) == expected.end());
	}
}
