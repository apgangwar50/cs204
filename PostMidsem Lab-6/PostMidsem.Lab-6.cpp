#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::vector<string> q;
	std::vector<string> w;
	int n;
	cin>>n;
	while(n--)
	{
		string s1;
		cin>>s1;
		string s2;
		s2=s1;
		reverse(s2.begin(), s2.end());
		if(s1!=s2)
		{
			q.push_back(s1);
			w.push_back(s2);
		}
	}
	sort(q.begin(),q.end());
	for(auto i : w)
	{
		if(binary_search(q.begin(), q.end(), i))
		{
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}