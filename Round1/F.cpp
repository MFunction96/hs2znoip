#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
//手动扩栈，防止栈溢出
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

const int INF = 0x7fffffff, MAXN = 100000 + 10;
const double EPS = 1e-6;

//定义有向邻接表边结构
struct Edge
{
	int from, to, dist;			//定义边起点、终点、边权
	//边结构构造函数
	Edge(int from, int to, int dist) :from(from), to(to), dist(dist) {}
};

//优先队列堆节点结构
struct HeapNode
{
	int d, u;
	HeapNode(int d, int u) :d(d), u(u) {}
	//定义优先队列堆权，即点权小堆权大，即点权小优先出队
	bool operator< (const HeapNode & rhs) const
	{
		return rhs.d < d;
	}
};

bool vis[MAXN];					//点访问标记
int p[MAXN];					//点权记录
vector<Edge> edges;				//邻接表边信息
vector<int> v[MAXN];			//邻接表点索引表
priority_queue<HeapNode> q;		//点权优先优先队列

//定义包含堆优化的Dijkstra算法类，时间复杂度期望从O(n^2)优化至O(nlogn)
struct Dijkstra
{
	int n, m;					//定义点数、边数
	//Dijkstra类构造函数
	Dijkstra(int n = 0, int m = 0) :n(n), m(m)
	{
		edges.clear();			//清空边信息
		//清空点索引表
		for (auto i = 0; i < n; i++)
		{
			v[i].clear();
		}
	}
	//向邻接表中进行加边操作
	void AddEdge(int from, int to, int dist)
	{
		edges.push_back(Edge(from, to, dist));
		v[from].push_back(edges.size() - 1);
		//由于邻接表为有向邻接表，因此反向输入以达到双向连通效果
		edges.push_back(Edge(to, from, dist));
		v[to].push_back(edges.size() - 1);
	}
	//Dijkstra核心算法，输入起点终点，返回结果
	int Solve(int s, int t)
	{
		//初始化优先队列
		while (!q.empty()) q.pop();
		//初始化点标记为所有点可访问
		memset(vis, -1, sizeof(vis));
		//初始化所有点权为正无穷
		for (auto i = 0; i < n; i++)
		{
			p[i] = INF;
		}
		p[s] = 0;				//将起点点权设置为0
		q.push(HeapNode(0, s));	//将起点推入优先队列
		while (!q.empty())		//当队列为空时即证明结束
		{
			auto tmp = q.top();	//取当前权值最小的点
			q.pop();
			auto u = tmp.u;
			if (vis[u])			//当该点未曾访问时
			{
				vis[u] = false;	//标记该点已访问
				//以该点为起点，搜索所有以该点为起点的边
				for (auto i = 0; i < v[u].size(); i++)
				{
					//取以该点为起点的边
					auto e = edges[v[u][i]];
					//当该边终点的权值大于起点点权与边权和时
					if (p[e.to] > p[u] + e.dist)
					{
						//更新终点点权
						p[e.to] = p[u] + e.dist;
						//将终点推入优先队列
						q.push(HeapNode(p[e.to], e.to));
					}
				}
			}
		}
		//若终点权值依旧为正无穷，则证明终点无法访问，否则输出结果
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