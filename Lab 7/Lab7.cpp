#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;
  
bool oper(string a, string b)
{
    string a1 = a.append(b);
    string a2 = b.append(a);
    return a1.compare(a2)>0 ? true:false;
}
 
int main()
{
    ll query;
    cin>>query;
    while(query--)
    {
        ll i=0;
        ll lines;
        cin>>lines;
        string nos[lines];
        while(lines--)
        {
            cin>>nos[i];
            i++;
        }
         sort(nos, nos + i, oper);
         for (ll j=0; j < i; j++ ) 
         {
              cout<<nos[j]; 
         }
         cout<<endl;
    }
return 0; 
} 