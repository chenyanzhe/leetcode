#include "MinimumWindowSubstring.hpp"

string MinimumWindowSubstring::minWindow(string s, string t)
{
	int slen = s.size();
	int tlen = t.size();
	int winStart = -1;
	int winEnd = slen;

	// fast path
	if (slen == 0 || tlen == 0 || slen < tlen)
		return "";

	int tCnt[256] = {0};
	int fCnt[256] = {0};
	int cnt = 0;

	for (int i = 0; i < tlen; i++)
		tCnt[t[i]]++;

	for (int start = 0, i = 0; i < slen; i++) {
		char ci = s[i];
		if (tCnt[ci] != 0) {
			fCnt[ci]++;
			if (fCnt[ci] <= tCnt[ci])
				cnt++;
		}
		if (cnt == tlen) {
			// find an valid window [start, i]
			// 1. shrink it
			while (start < i) {
				char cs = s[start];
				if (tCnt[cs] == 0) {
					start++;
				} else if (fCnt[cs] > tCnt[cs]) {
					start++;
					fCnt[cs]--;
				} else {
					break;
				}
			}
			// 2. update minimum window
			if (winEnd - winStart > i - start) {
				winStart = start;
				winEnd = i;
			}
			// 3. update start
			fCnt[s[start]]--;
			start++;
			cnt--;
		}
	}

	return winStart == -1 ? "" : s.substr(winStart, winEnd - winStart + 1);
}