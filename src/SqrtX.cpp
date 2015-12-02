#include "SqrtX.hpp"

int SqrtX::mySqrt(int x)
{
	if (x <= 0) return 0;
	if (x == 1) return 1;
	return mySqrt(x, 1, x);
}

int SqrtX::mySqrt(int x, int l, int h)
{
	long m = ((long) l + (long) h) / 2;
	double d_m = m * m;
	if (d_m > x) return mySqrt(x, l, m);
	else {
		double d_m_2 = (m + 1) * (m + 1);
		if (d_m_2 > x) return m;
		else return mySqrt(x, m + 1, h);
	}
}
