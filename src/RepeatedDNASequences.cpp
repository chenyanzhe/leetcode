#include "RepeatedDNASequences.hpp"

#include <unordered_set>
using namespace std;

vector<string> RepeatedDNASequences::findRepeatedDnaSequences(string s)
{
  unordered_set<string> records;
  unordered_set<string> deduplicates;
  vector<string> result;
  int len = 10;

  for (int i = 0; i + len <= s.size(); i++) {
    string substr = s.substr(i, len);

    if (records.count(substr) && deduplicates.count(substr) == 0) {
      result.push_back(substr);
      deduplicates.insert(substr);
    } else {
      records.insert(substr);
    }
  }

  return result;
}
