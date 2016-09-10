#include "catch.hpp"

#include "LoggerRateLimiter.hpp"

TEST_CASE("Logger Rate Limiter") {
    LoggerRateLimiter logger;
    SECTION("Sample test") {
        REQUIRE(logger.shouldPrintMessage(1, "foo"));
        REQUIRE(logger.shouldPrintMessage(2, "bar"));
        REQUIRE_FALSE(logger.shouldPrintMessage(3, "foo"));
        REQUIRE_FALSE(logger.shouldPrintMessage(8, "bar"));
        REQUIRE_FALSE(logger.shouldPrintMessage(10, "foo"));
        REQUIRE(logger.shouldPrintMessage(11, "foo"));
    }
}
