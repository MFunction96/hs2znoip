#include<cstdio>

int main()
{
	int n;
	//freopen("data.in", "r", stdin);			//�ض����׼��������data.in�ļ�
	while (scanf("%d", &n) == 1)				//ѭ������������ֱ�����뵽EOF
	{
		if (n >= 90 && n <= 100)
		{
			printf("A\n");
		}
		else if (n >= 80 && n < 90)
		{
			printf("B\n");
		}
		else if (n >= 70 && n < 80)
		{
			printf("C\n");
		}
		else if (n >= 60 && n < 70)
		{
			printf("D\n");
		}
		else if (n >= 0 && n < 60)
		{
			printf("E\n");
		}
		else
		{
			printf("Score is error!\n");
		}
	}
	//freopen("CON", "r", stdin);				//�ض����׼������������̨
	return 0;
}