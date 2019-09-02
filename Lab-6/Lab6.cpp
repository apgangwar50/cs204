
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main()
{
    ll userid;
    ll recharge;
    ll users;
    ll query;
    ll one;
    ll size = 0;
    ll distinct = 1;
    bool empty=true;

    cin>>users;
    cin>>query;

    ll a[query];
    ll b[query];
    ll temp[query];
    ll c[query];
    ll d[query]={0};

    for(int i = 0; i<query; i++)
    {
        cin>>one;

        if(one==1)
        {
            cin>>userid>>recharge;
            a[i]=userid;
            temp[i]=userid;
            size++;
            b[i]=recharge;
        }
        else 
        {
            a[i]= -1;
        }
    }

    sort(temp,temp+size);

    c[0]= temp[0];

    for(int i =1, count=0; i<size; i++)
    {
        if(temp[i]!=c[count])
        {
            c[++count]=temp[i];
            distinct++;
        }
    }

    ll max=-1, maxuser= -1;

    for(int i=0; i<query; i++)
    {
        {
            if(a[i]==-1)
            {
                if(maxuser ==-1)
                    cout<<"No data available\n";
                else 
                    cout<<maxuser<<endl;
            }
            else
            {
                int posi = lower_bound(c,c+distinct, a[i]) -c;
                d[posi] = d[posi]+b[i];
                if(d[posi]>max)
                {
                    max= d[posi];
                    maxuser= a[i];
                }
            }
        }
    }
    return 0;
}
