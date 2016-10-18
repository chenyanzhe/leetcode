#ifndef TWO_SUM_III_HPP_
#define TWO_SUM_III_HPP_

#include <unordered_map>

using namespace std;

class TwoSumIII {
public:
    // Add the number to an internal data structure.
    void add(int number);

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value);

private:
    unordered_map<int, int> lookup;
};

#endif // TWO_SUM_III_HPP_