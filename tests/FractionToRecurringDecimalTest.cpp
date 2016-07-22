#include "catch.hpp"

#include "FractionToRecurringDecimal.hpp"

TEST_CASE("Fraction to Recurring Decimal") {
    FractionToRecurringDecimal s;
    SECTION("Sample tests") {
        REQUIRE(s.fractionToDecimal(1, 1) == "1");
        REQUIRE(s.fractionToDecimal(1, 2) == "0.5");
        REQUIRE(s.fractionToDecimal(1, 3) == "0.(3)");
        REQUIRE(s.fractionToDecimal(1, 4) == "0.25");
        REQUIRE(s.fractionToDecimal(1, 5) == "0.2");
        REQUIRE(s.fractionToDecimal(1, 6) == "0.1(6)");
        REQUIRE(s.fractionToDecimal(1, 7) == "0.(142857)");
        REQUIRE(s.fractionToDecimal(1, 8) == "0.125");
        REQUIRE(s.fractionToDecimal(1, 9) == "0.(1)");
        REQUIRE(s.fractionToDecimal(1, 10) == "0.1");
        REQUIRE(s.fractionToDecimal(1, 11) == "0.(09)");
        REQUIRE(s.fractionToDecimal(1, 12) == "0.08(3)");
        REQUIRE(s.fractionToDecimal(1, 13) == "0.(076923)");
    }
    SECTION("Special tests") {
        REQUIRE(s.fractionToDecimal(1, 90) == "0.0(1)");
        REQUIRE(s.fractionToDecimal(-1,
                                    -2147483648) == "0.0000000004656612873077392578125");
        string long_string = "0.00";
        long_string +=
                "(000000465661289042462740251655654056577585848337359161441621040707904997124";
        long_string +=
                "9140691940265491382276607238786694551954770654271433704612529667513555539822";
        long_string +=
                "4128031075477715862831904973208550263973140209813193268378053860284588710533";
        long_string +=
                "7854867197032523144157689601770377165713821223802198558308923834223016478952";
        long_string += "081795603341592860749337303449725)";
        REQUIRE(s.fractionToDecimal(1, 214748364) == long_string);
    }
}
