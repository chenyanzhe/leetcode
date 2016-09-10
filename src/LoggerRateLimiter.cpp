#include "LoggerRateLimiter.hpp"

bool LoggerRateLimiter::shouldPrintMessage(int timestamp, string message) {
    if (log.find(message) == log.end() || log[message] <= timestamp) {
        log[message] = timestamp + 10;
        return true;
    }
    return false;
}