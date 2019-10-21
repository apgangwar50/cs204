#include<bits/stdc++.h>
using namespace std;
typedef int ll;

int x[] = { -1,  0, 0, 1}; 
int y[] = { 0, -1, 1, 0}; 
ll fin=0;

void dfs(ll r, ll s, vector<vector <int>> &arr, vector<vector <int>> &ext)
{
	ext[r][s]=1;
	fin++;
	for(int q=0; q<4; q++)
	{
		if(ext[x[q]+r][y[q]+s]) continue;
		if(arr[x[q]+r][y[q]+s]==0) continue;
		dfs(x[q]+r, y[q]+s, arr, ext);
	}
}

int main()
{
	ll m,n;
	cin>>m>>n;
	vector<vector <int>>  arr(m+1, vector<int> (n+1));
	vector<vector <int>>  ext(m+1, vector<int> (n+1));
	ll ans=0;
	ll k;
	cin>>k;
	ll ab, ac;

	for(ll i=0; i<k; i++)
	{
		cin>>ab>>ac;
		arr[ab][ac]=1;
	}

	for(ll i=1; i<=m; i++)
	{
		for(ll j=1; j<=n; j++)
		{
			if (ext[i][j]) continue;
			if (arr[i][j]==0) continue;
			fin=0;
			dfs(i,j, arr, ext);
			ans=max(ans,fin);
		}
	}
	cout<<ans;
	return 0;
}