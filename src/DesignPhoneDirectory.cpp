#include "DesignPhoneDirectory.hpp"

PhoneDirectory::PhoneDirectory(int maxNumbers) : used(maxNumbers, 0) {
    for (int i = 0; i < maxNumbers; i++)
        available.push_front(i);
}

int PhoneDirectory::get() {
    if (available.empty()) return -1;
    int ret = available.front();
    available.pop_front();
    used[ret] = 1;
    return ret;
}

bool PhoneDirectory::check(int number) {
    if (number < 0 || number >= used.size()) return false;
    return used[number] == 0;
}

void PhoneDirectory::release(int number) {
    if (!check(number)) {
        used[number] = 0;
        available.push_front(number);
    }
}