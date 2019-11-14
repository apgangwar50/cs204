#include <bits/stdc++.h>
using namespace std;

int k1 = 44701;
int k2 = 47701;
int k3 = 90709;
int k4 = 78487;
int k5 = 65537;
int p1 = 18143;
int p2 = 20749;
int p3 = 17419;
int p4 = 22853;
int p5 = 19949;

bool hashfn1[44701];
bool hashfn2[47701];
bool hashfn3[90709];
bool hashfn4[78487];
bool hashfn5[65537];

bool hashfunc(string s, bool change=0)
{
	int len = s.length();
	long long f1=0, f2=0, f3=0, f4=0, f5=0;
	int ctr = 0;

	for (int i=0; i<len; i++)
	{
		f1 = (f1 * p1 + (s[i]-'a')) % k1 ; 
		f2 = (f2 * p2 + (s[i]-'a')) % k2 ; 
		f3 = (f3 * p3 + (s[i]-'a')) % k3 ; 
		f4 = (f4 * p4 + (s[i]-'a')) % k4 ; 
		f5 = (f5 * p5 + (s[i]-'a')) % k5 ; 
	}

	if (hashfn1[f1])
		ctr++;
	else if (change) 
		hashfn1[f1]=1;

	if (hashfn2[f2])
		ctr++;
	else if (change) 
		hashfn2[f2]=1;

	if (hashfn3[f3])
		ctr++;
	else if (change) 
		hashfn3[f3]=1;

	if (hashfn4[f4])
		ctr++;
	else if (change) 
		hashfn4[f4]=1;

	if (hashfn5[f5])
		ctr++;
	else if (change) 
		hashfn5[f5]=1;

	return (ctr==5)?1:0;
}

int main()
{
	int n;
	cin >> n;

	for (int i=0; i<n; i++)
	{
		string s, srev;
		cin >> s;
		srev = s;
		reverse(s.begin(), s.end());

		if (s == srev)
			continue;

		hashfunc(s,1);

		if (hashfunc(srev,0))
		{
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}