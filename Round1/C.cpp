#include<cstdio>
#include<cstdlib>

const int INF = 0x7fffffff, MAXN = 100000 + 10;
const double EPS = 1e-6;

int main()
{
	int t;
	while (scanf("%d", &t) == 1)
	{
		auto sum = 0, h = 0;				//�ٶ��ӱ��Ϊ-1���߶�Ϊ0������
		while (t--)
		{
			int num;
			scanf("%d", &num);				
			sum += abs(num - h) + 2;		//�ƶ�+1���Լ��+1���ټӸ߶Ȳ�
			h = num;						//�洢��ǰ�߶�
		}
		printf("%d\n", sum - 1);			//��ȥ�����-1�������ƶ�����һ��
	}
	return 0;
}