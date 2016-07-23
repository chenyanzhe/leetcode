#ifndef H_INDEX_HPP_
#define H_INDEX_HPP_

#include <vector>

using namespace std;

class HIndex {
public:
    int hIndex(vector<int> &citations);

private:
    int hIndexSort(vector<int> &citations);

    int hIndexHashTable(vector<int> &citations);
};

#endif // H_INDEX_HPP_
