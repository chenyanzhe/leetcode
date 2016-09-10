#ifndef LOGGER_RATE_LIMITER_HPP_
#define LOGGER_RATE_LIMITER_HPP_

#include <string>
#include <unordered_map>

using namespace std;

class LoggerRateLimiter {
public:
    /** Initialize your data structure here. */
    LoggerRateLimiter() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message);

private:
    unordered_map<string, int> log;
};

#endif // LOGGER_RATE_LIMITER_HPP_