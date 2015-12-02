#include "BestTimeToBuyAndSellStockIII.hpp"

#include <algorithm>
using namespace std;

int BestTimeToBuyAndSellStockIII::maxProfit(vector<int>& prices)
{
	int sz = prices.size();

	if (sz <= 1) return 0;

	vector<int> f(sz, 0);
	vector<int> g(sz, 0);

	for (int i = 1, min_price = prices[0]; i < sz; i++) {
		f[i] = max(f[i - 1], prices[i] - min_price);
		min_price = min(min_price, prices[i]);
	}

	for (int i = sz - 2, max_price = prices[sz - 1]; i >= 0; i--) {
		g[i] = max(g[i + 1], max_price -  prices[i]);
		max_price = max(max_price, prices[i]);
	}

	int result = 0;

	for (int i = 0; i < sz; i++)
		result = max(result, f[i] + g[i]);

	return result;
}
