#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

const int INF = 0x7fffffff, MAXN = 100000 + 10;
const double EPS = 1e-6;

string str;												//�����ַ�������
vector<int> v;											//������̬���飨������

int main()
{
	//freopen("data.in", "r", stdin);
	while (cin >> str)									//�������ֱ���������
	{
		auto flag = false;								//�Ƿ���������flag
		auto num = 0;									//��ʼ�����ݻ���
		v.clear();										//�����������
		for (auto i = 0; i < str.length(); i++)			//�����ַ���
		{
			if (str[i] == '5')							//�����5
			{
				if (flag)								//����Ѿ���������
				{
					v.push_back(num);					//¼������
				}
				flag = false;							//�����δ��������
				num = 0;								//������ݻ���
			}
			else
			{
				num *= 10;								//���ݸ����λ
				num += str[i] - '0';					//����������
				flag = true;							//�����¼������
			}
		}
		if (flag)										//������ɺ������ڻ���
		{
			v.push_back(num);							//��¼����
		}
		sort(v.begin(), v.end());						//������������
		for (auto i = 0; i < v.size(); i++)				//�������
		{
			if (i) cout << ' ' << v[i];					//������ǵ�һ�����ݣ�ǰ�ÿո�ָ�
			else cout << v[i];							//����ǵ�һ�����ݣ�ֱ�����
		}
		cout << endl;									
	}
	//freopen("CON", "r", stdin);
	return 0;
}