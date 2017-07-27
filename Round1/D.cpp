#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int INF = 0x7fffffff, MAXN = 100000 + 10;
const double EPS = 1e-6;

int num[MAXN];

bool cmp(int n1, int n2)					//���尴����ֵ�����������
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
			if (num[i] < 0)					//����Ϊ����ʱ
			{
				cnt++;						//����+1
			}
		}
		auto sum = 0;
		if (cnt > k)						//���������ڲ�����ʱ
		{
			sort(num, num + n);				//����������
			for (auto i = 0; i < n; i++)
			{
				if (i < k)
				{							
					sum += abs(num[i]);		//�þ���ֵ��ĸ������
				}
				else
				{
					sum += num[i];
				}
			}
		}
		else
		{
			sort(num, num + n, cmp);		//�����������ڸ�������ʱ
			for (auto i = 0; i < n; i++)
			{
				if (i == 0 && k - cnt & 1)	//�����������Ϊ����
				{
					sum -= abs(num[i]);		//������ֵ��С������Ϊ����
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