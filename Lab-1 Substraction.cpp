#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int larger( string s1, string s2)
{

    int len1=s1.length(), len2=s2.length();

    if(len1<len2)
        return 1;
    if(len1>len2)
        return 0;

     for (int i=0; i<len1; i++)
    {
        if (s1[i] < s2[i])
            return 1;
        else if (s1[i] > s2[i])
            return 0;
    }
    return 0;
};

string largesubs(string s1, string s2)
{
    string final;

    if (larger(s1,s2))
    {
        swap(s1,s2);
    }

    int len1= s1.length();
    int len2=s2.length();
    int dif= len1-len2;
    int car=0;

    for (int i=len2-1; i>=0; i--)
    {
        int sub = ((s1[i+dif]-'0') -(s2[i]-'0') - car);

        if(sub < 0)
        {   sub = sub+10;
            car = 1;
        }
        else
            car = 0;

        final.push_back(sub + '0');
    }

    for (int i=len1-len2-1; i>=0; i--)
    {
        if (s1[i]=='0' && car)
        {
            final.push_back('9');
            continue;
        }
        int sub = ((s1[i]-'0') - car);
        if (i>0 || sub>0)
         {
             final.push_back(sub+'0');
         }
        car = 0;
    }
    reverse(final.begin(), final.end());

    return final;
};

int main()
{
    int n;
    cin>>n;
    string ans[100];

    for(int i= 0; i<n; i++)
    {
    string s1, s2;
    cin>>s1;
    cin>>s2;

    ans[i]=largesubs(s1,s2);
    }

    for(int i= 0; i<n; i++)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}
