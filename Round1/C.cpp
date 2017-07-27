#include<cstdio>
#include<cstdlib>

const int INF = 0x7fffffff, MAXN = 100000 + 10;
const double EPS = 1e-6;

int main()
{
	int t;
	while (scanf("%d", &t) == 1)
	{
		auto sum = 0, h = 0;				//假定从编号为-1，高度为0处出发
		while (t--)
		{
			int num;
			scanf("%d", &num);				
			sum += abs(num - h) + 2;		//移动+1，吃坚果+1，再加高度差
			h = num;						//存储当前高度
		}
		printf("%d\n", sum - 1);			//减去最初从-1的树上移动的那一步
	}
	return 0;
}