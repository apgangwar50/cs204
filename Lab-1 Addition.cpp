#include <iostream>
#include<bits/stdc++.h>

using namespace std;

string largesum(string s1, string s2)
{
    string final;

    if (s1.length()>s2.length())
    {
        swap(s1,s2);
    }

    int len1= s1.length();
    int len2=s2.length();
    int dif= len2-len1;
    int car=0;

    for (int i=len1-1; i>=0; i--)
    {
        int sum = ((s1[i]-'0') +(s2[i+dif]-'0') + car);
        final.push_back(sum%10 + '0');
        car = sum/10;
    }

    for (int i=len2-len1-1; i>=0; i--)
    {
        int sum = ((s2[i]-'0')+car);
        final.push_back(sum%10 + '0');
        car= sum/10;
    }

    if (car)
        final.push_back(car+'0');

    reverse(final.begin(), final.end());

    return final;
}

int main()
{
    string s1, s2;
    cin>>s1;
    cin>>s2;

    cout<<largesum(s1,s2);

    return 0;
}
