#ifndef DESIGN_PHONE_DIRCTORY_HPP_
#define DESIGN_PHONE_DIRCTORY_HPP_

#include <vector>
#include <list>

using namespace std;

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers);

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get();

    /** Check if a number is available or not. */
    bool check(int number);

    /** Recycle or release a number. */
    void release(int number);

private:
    list<int> available;
    vector<int> used;
};

#endif // DESIGN_PHONE_DIRCTORY_HPP_