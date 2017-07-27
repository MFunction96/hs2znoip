#include<cstdio>
#include<algorithm>
using namespace std;

const int INF = 0x7fffffff, MAXN = 100000 + 10;
const double EPS = 1e-6;

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		auto ans = -INF;
		for (auto i = 0; i < n; i++)
		{
			auto tmp = INF;
			for (auto j = 0; j < m; j++)
			{
				auto num = 0;
				scanf("%d", &num);
				tmp = min(num, tmp);		//Jack要选择每一条街最便宜的
			}
			ans = max(ans, tmp);			//Emma要选择所有最便宜中最贵的
		}
		printf("%d\n", ans);
	}
	return 0;
}