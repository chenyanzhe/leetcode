#include "AddBinary.hpp"

string AddBinary::addBinary(string a, string b)
{
	if (a.size() == 0) return b;
	if (b.size() == 0) return a;

	if (a.size() < b.size()) return addBinary(b, a);

	int sza = a.size();
	int szb = b.size();
	string c = "";
	int carry = 0;
	int i, j;
	for (i = sza - 1, j = szb - 1; j >= 0; i--, j--) {
		int val = a[i] - '0' + b[j] - '0' + carry;
		carry = val / 2;
		c = to_string(val % 2) + c;
	}
	for (; i >= 0; i--) {
		int val = a[i] - '0' + carry;
		carry = val / 2;
		c = to_string(val % 2) + c;
	}
	if (carry) c = to_string(carry) + c;

	return c;
}