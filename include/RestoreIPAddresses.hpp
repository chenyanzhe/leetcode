#ifndef RESTORE_IP_ADDRESSES_HPP_
#define RESTORE_IP_ADDRESSES_HPP_

#include <vector>
#include <string>

using namespace std;

class RestoreIPAddresses {
private:
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s);

private:
    void bt(string s, int i, int segment, string addr);

    bool valid(string segment);
};

#endif // RESTORE_IP_ADDRESSES_HPP_
