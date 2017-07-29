#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
//�ֶ���ջ����ֹջ���
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

const int INF = 0x7fffffff, MAXN = 100000 + 10;
const double EPS = 1e-6;

//���������ڽӱ�߽ṹ
struct Edge
{
	int from, to, dist;			//�������㡢�յ㡢��Ȩ
	//�߽ṹ���캯��
	Edge(int from, int to, int dist) :from(from), to(to), dist(dist) {}
};

//���ȶ��жѽڵ�ṹ
struct HeapNode
{
	int d, u;
	HeapNode(int d, int u) :d(d), u(u) {}
	//�������ȶ��ж�Ȩ������ȨС��Ȩ�󣬼���ȨС���ȳ���
	bool operator< (const HeapNode & rhs) const
	{
		return rhs.d < d;
	}
};

bool vis[MAXN];					//����ʱ��
int p[MAXN];					//��Ȩ��¼
vector<Edge> edges;				//�ڽӱ����Ϣ
vector<int> v[MAXN];			//�ڽӱ��������
priority_queue<HeapNode> q;		//��Ȩ�������ȶ���

//����������Ż���Dijkstra�㷨�࣬ʱ�临�Ӷ�������O(n^2)�Ż���O(nlogn)
struct Dijkstra
{
	int n, m;					//�������������
	//Dijkstra�๹�캯��
	Dijkstra(int n = 0, int m = 0) :n(n), m(m)
	{
		edges.clear();			//��ձ���Ϣ
		//��յ�������
		for (auto i = 0; i < n; i++)
		{
			v[i].clear();
		}
	}
	//���ڽӱ��н��мӱ߲���
	void AddEdge(int from, int to, int dist)
	{
		edges.push_back(Edge(from, to, dist));
		v[from].push_back(edges.size() - 1);
		//�����ڽӱ�Ϊ�����ڽӱ���˷��������Դﵽ˫����ͨЧ��
		edges.push_back(Edge(to, from, dist));
		v[to].push_back(edges.size() - 1);
	}
	//Dijkstra�����㷨����������յ㣬���ؽ��
	int Solve(int s, int t)
	{
		//��ʼ�����ȶ���
		while (!q.empty()) q.pop();
		//��ʼ������Ϊ���е�ɷ���
		memset(vis, -1, sizeof(vis));
		//��ʼ�����е�ȨΪ������
		for (auto i = 0; i < n; i++)
		{
			p[i] = INF;
		}
		p[s] = 0;				//������Ȩ����Ϊ0
		q.push(HeapNode(0, s));	//������������ȶ���
		while (!q.empty())		//������Ϊ��ʱ��֤������
		{
			auto tmp = q.top();	//ȡ��ǰȨֵ��С�ĵ�
			q.pop();
			auto u = tmp.u;
			if (vis[u])			//���õ�δ������ʱ
			{
				vis[u] = false;	//��Ǹõ��ѷ���
				//�Ըõ�Ϊ��㣬���������Ըõ�Ϊ���ı�
				for (auto i = 0; i < v[u].size(); i++)
				{
					//ȡ�Ըõ�Ϊ���ı�
					auto e = edges[v[u][i]];
					//���ñ��յ��Ȩֵ��������Ȩ���Ȩ��ʱ
					if (p[e.to] > p[u] + e.dist)
					{
						//�����յ��Ȩ
						p[e.to] = p[u] + e.dist;
						//���յ��������ȶ���
						q.push(HeapNode(p[e.to], e.to));
					}
				}
			}
		}
		//���յ�Ȩֵ����Ϊ�������֤���յ��޷����ʣ�����������
		return p[t] == INF ? -1 : p[t];
	}
};

Dijkstra dij;

int main()
{
	int n, m;
	//freopen("data.in", "r", stdin);
	while (scanf("%d%d", &n, &m) == 2)
	{
		dij = Dijkstra(n, m);
		while (m--)
		{
			int from, to, dist;
			scanf("%d%d%d", &from, &to, &dist);
			dij.AddEdge(from, to, dist);
		}
		int s, t;
		scanf("%d%d", &s, &t);
		printf("%d\n", dij.Solve(s, t));
	}
	//freopen("CON", "r", stdin);
	return 0;
}