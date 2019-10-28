#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll> > graph;
vector<ll> col;
bool val[100000];
ll v, e, i, j;

bool isBi()
{
	col[0]=1;
	queue<ll> que;
	que.push(0);
	while(!que.empty())
	{
		ll tmp = que.front();
		que.pop();
		for( i= 0; i<v; i++)
		{
			if(graph[tmp][i] && col[i]== -1)
			{
				col[i] = 1-col[tmp];
				que.push(i);
			}
			else if (graph[tmp][i] && col[i]==col[tmp])
				return 0;
		}
	}
	return 1;
}

int main()
{
	ll x, y;
	cin>>v>>e;
	graph.resize(v);
	col.resize(v, -1);
	memset(val,0,sizeof(val));
	for(ll o = 0; o<v; o++)
	{
		graph[o].resize(v);
	}

	for(ll l = 0; l<e; l++)
	{
		cin>>x>>y;
		x--, y--;
		graph[x][y]=1;
		graph[y][x]=1;
	}

	if(isBi())
		cout<<"YES\n";
	else
		cout<<"NO\n";

		return 0;
}