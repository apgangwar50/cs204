#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll m,n,k;
ll fin=-1;
ll ans =0;
ll col= 0;

void dfs(ll x, ll y, vector<vector <bool>> &ext, vector<vector <int>> &arr, ll color)
{
	ext[x][y]=1;
	ans++;

	if ((x<n) && (x>=0) && (y+1<m) && (y+1>=0) && (arr[x][y+1]==color))
	{
		if (!ext[x][y+1]) {
			dfs(x,y+1,ext,arr,color);
		}
	}

	if ((x<n) && (x>=0) && (y-1<m) && (y-1>=0) && (arr[x][y-1]==color))
	{
		if (!ext[x][y-1]) {
			dfs(x,y-1,ext,arr,color);
		}
	}

	if ((x+1<n) && (x+1>=0) && (y<m) && (y>=0) && (arr[x+1][y]==color))
	{
		if (!ext[x+1][y]) {
			dfs(x+1,y,ext,arr,color);
		}
	}

	if ((x-1<n) && (x-1>=0) && (y<m) && (y>=0) && (arr[x-1][y]==color))
	{
		if (!ext[x-1][y]) {
			dfs(x-1,y,ext,arr,color);
		}
	}
	if (ans > fin)
    {
		fin = ans;
		col = color;
	}
}

int main()
{

	cin>>n>>m>>k;
	vector<vector <bool>>  ext(n, vector<bool> (m));
	vector<vector <int>>  arr(n, vector<int> (m));
	ll c;

    for (int i=0; i<n; i++)
        {
		for (int j=0; j<m; j++)
		 {
			ext[i][j]=0;
			arr[i][j]=0;
		}
	}
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			cin >> c;
			arr[i][j] = c;
		}
	}

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			if (!ext[i][j])
            {
                ans = 0;
				dfs(i,j, ext, arr, arr[i][j]);
			}
		}
	}
	cout<<"\nSize: "<<fin<<" Colour: "<<col<<endl;
	return 0;
}
