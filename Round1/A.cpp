#include<cstdio>

int main()
{
	int n;
	//freopen("data.in", "r", stdin);			//重定向标准输入流到data.in文件
	while (scanf("%d", &n) == 1)				//循环输入整数，直到输入到EOF
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
	//freopen("CON", "r", stdin);				//重定向标准输入流到控制台
	return 0;
}