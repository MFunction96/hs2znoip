#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int INF = 0x7fffffff, MAXN = 100000 + 10;
const double EPS = 1e-6;

int num[MAXN];

bool cmp(int n1, int n2)					//定义按绝对值升序排序规则
{
	return abs(n1) < abs(n2);
}

int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) == 2)
	{
		auto cnt = 0;
		for (auto i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
			if (num[i] < 0)					//当数为负数时
			{
				cnt++;						//计数+1
			}
		}
		auto sum = 0;
		if (cnt > k)						//当负数多于操作数时
		{
			sort(num, num + n);				//按升序排序
			for (auto i = 0; i < n; i++)
			{
				if (i < k)
				{							
					sum += abs(num[i]);		//让绝对值大的负数变号
				}
				else
				{
					sum += num[i];
				}
			}
		}
		else
		{
			sort(num, num + n, cmp);		//当操作数大于负数个数时
			for (auto i = 0; i < n; i++)
			{
				if (i == 0 && k - cnt & 1)	//若多余操作数为奇数
				{
					sum -= abs(num[i]);		//将绝对值最小的数变为负数
				}
				else
				{
					sum += abs(num[i]);
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}