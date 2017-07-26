#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

const int INF = 0x7fffffff, MAXN = 100000 + 10;
const double EPS = 1e-6;

string str;												//声明字符串类型
vector<int> v;											//声明动态数组（容器）

int main()
{
	//freopen("data.in", "r", stdin);
	while (cin >> str)									//输入多组直到输入结束
	{
		auto flag = false;								//是否输入数据flag
		auto num = 0;									//初始化数据缓存
		v.clear();										//清除容器内容
		for (auto i = 0; i < str.length(); i++)			//遍历字符串
		{
			if (str[i] == '5')							//如果是5
			{
				if (flag)								//如果已经输入数据
				{
					v.push_back(num);					//录入数据
				}
				flag = false;							//标记暂未输入数据
				num = 0;								//清除数据缓存
			}
			else
			{
				num *= 10;								//数据各项进位
				num += str[i] - '0';					//加入新数据
				flag = true;							//标记已录入数据
			}
		}
		if (flag)										//遍历完成后若存在缓存
		{
			v.push_back(num);							//补录数据
		}
		sort(v.begin(), v.end());						//数据升序排序
		for (auto i = 0; i < v.size(); i++)				//遍历结果
		{
			if (i) cout << ' ' << v[i];					//如果不是第一个数据，前置空格分隔
			else cout << v[i];							//如果是第一个数据，直接输出
		}
		cout << endl;									
	}
	//freopen("CON", "r", stdin);
	return 0;
}