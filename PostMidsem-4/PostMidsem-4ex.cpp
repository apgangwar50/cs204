#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v, e;

class graph
{
	int v;
	list <int> *adjlist;

public:
	graph(int v)
	{
		v = v+1;
		adjlist =  new list <int> [v];
	}

	~graph()
	{
		delete[] adjlist;
	}

	void addedge(ll x, ll y)
	{
		adjlist[x].push_back(y);
		adjlist[y].push_back(x);	
	}

	bool isBi(ll no, ll vis[])
	{
	queue<ll> que;
	que.push(no);
	
	while(!que.empty())
	{
		ll tmp = que.front();
		que.pop();
		for(auto i: adjlist[tmp])
		{
			if(!vis[i])
			{
				vis[i] = (vis[tmp]==1 ? 2 : 1);
				que.push(i);
			}
			else 
			{ 
				ll num = (vis[tmp]==1 ? 2 : 1);
				if(vis[i]!= num)
				return 0;
			}
		}
	}
	return 1;
	}
};



int main()
{
	ll x, y, w;
	cin>>v>>e;
	graph gra(v + e);
	ll dum = v+1;

	for(ll l = 0; l<e; l++)
	{
		cin>>x>>y>>w;
		if(w%2)
		{
			gra.addedge(x,dum);
			gra.addedge(dum,y);
			dum++;
		}
		else
			gra.addedge(x, y);
	}

	ll *vis = new ll[v+e+1]{0};
	bool isbi =true;
	bool odc = false;
	for(ll i = 0 ; i<=v+e && isbi; i++)
	{
		if(!vis[i])
		{
			isbi = gra.isBi(i, vis);
			if(!isbi)
			{
				odc = true;
				break;
			}
		}
	}

	if(odc)
		cout<<"YES\n";
	else
		cout<<"NO\n";

	delete[] vis;
		return 0;
}