#include "CompareVersionNumbers.hpp"

#include <algorithm>
using namespace std;

int CompareVersionNumbers::compareVersion(string version1, string version2)
{
  vector<string> versions1;
  vector<string> versions2;
  tokenize(version1, versions1);
  tokenize(version2, versions2);
  size_t len1 = versions1.size();
  size_t len2 = versions2.size();
  size_t i;

  for (i = 0; i < min(len1, len2); i++) {
    int result = compareDigitsString(versions1[i], versions2[i]);

    if (result != 0) {
      return result;
    }
  }

  if (len1 == len2) {
    return 0;
  }

  // resolve cases like "1.0.0" vs "1.0"
  if (i < len1) {
    for (; i < len1; i++)
      if (versions1[i] != "0") {
        return 1;
      }

    return 0;
  } else {
    for (; i < len2; i++)
      if (versions2[i] != "0") {
        return -1;
      }

    return 0;
  }
}

int CompareVersionNumbers::compareDigitsString(string num1, string num2)
{
  if (num1.size() < num2.size()) {
    return -1;
  }

  if (num1.size() > num2.size()) {
    return 1;
  }

  for (size_t i = 0, sz = num1.size(); i < sz; i++) {
    if (num1[sz - i - 1] > num2[sz - i - 1]) {
      return 1;
    }

    if (num1[sz - i - 1] < num2[sz - i - 1]) {
      return -1;
    }
  }

  return 0;
}

void CompareVersionNumbers::tokenize(const string& version,
                                     vector<string>& versions)
{
  size_t i = 0;

  while (i < version.size() && version[i] == '.') {
    i++;
  }

  size_t j = i + 1;

  while (j < version.size()) {
    if (version[j] == '.') {
      // strip leading zeros but keep "0"
      while (i + 1 < j && version[i] == '0') {
        i++;
      }

      versions.push_back(version.substr(i, j - i));
      i = j + 1;

      while (i < version.size() && version[i] == '.') {
        i++;
      }

      j = i + 1;
    } else {
      j++;
    }
  }

  if (i < version.size()) {
    // strip leading zeros but keep "0"
    while (i + 1 < j && version[i] == '0') {
      i++;
    }

    versions.push_back(version.substr(i, j - i));
  }
}
