#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define M 1000000007

ll v, e;
const ll MAX = 1e4+5;
ll id[MAX], nodes, edges;
pair<ll, pair<ll, ll> > points[MAX];

ll root(ll x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void uni(ll x, ll y)
{
    ll p = root(x);
    ll q = root(y);
    id[p] = id[q];
}

ll mst(pair<ll, pair<ll, ll> >  p[])
{
    ll x, y;
    ll cost, maxcost = 1;
    for(ll i = 0;i < e;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y))
        {
            maxcost *= cost;
            uni(x, y);
        }    
        maxcost = maxcost%M;
    }
    return maxcost;
}

bool oper(pair<ll,pair<ll,ll>> a,pair<ll,pair<ll,ll>> b)
{
	return a.first>b.first;
}

int main()
{
	ll x, y;
	ll w;
	ll cost, maxcost;
	 for(ll i = 0;i < MAX;++i)
        id[i] = i;
	cin>>v>>e;

	for(ll l = 0; l<e; ++l)
	{
		cin>>x>>y>>w;
		points[l] = make_pair(w, make_pair(x,y));
	}
	sort(points, points+e, oper);
	maxcost = mst(points);
	cout<<maxcost<<endl;
	return 0;
}