#include <iostream>
#include<bits/stdc++.h>

using namespace std;

string multi(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    if(l1 == 0 || l2 == 0)
        return "0";

    vector<int> final(l1+l2,0);
    string fin = "";
    int m1=0;
    int m2=0;
    for(int i=l1-1; i>=0; i--)
    {
        int car=0;
        int n1 = s1[i]-'0';
        m2 = 0;

        for (int j=l2-1; j>=0; j--)
        {
            int n2 = s2[j] - '0';

            int sum = n1*n2 + final[m1 + m2] + car;

            car = sum/10;

            final[m1 + m2] = sum%10;
            m2++;
        }
        if (car > 0)
            final[m1 + m2] += car;
        m1++;
    }

    int i =  final.size() - 1;
    while (i>=0 && final[i] == 0)
    i--;
    if (i == -1)
    return "0";

    while (i >= 0)
        fin += std:: to_string(final[i--]);

  return fin;

}
int main()
{
    string s1;
    string s2 ;
    cin>>s1;
    cin>>s2;

    if((s1.at(0) == '-' || s2.at(0) == '-') && (s1.at(0) != '-' || s2.at(0) != '-' ))
        cout<<"-";


    if(s1.at(0) == '-' && s2.at(0)!='-')
        {
            s1 = s1.substr(1);
        }
    else if(s1.at(0) != '-' && s2.at(0) == '-')
        {
            s2 = s2.substr(1);
        }
    else if(s1.at(0) == '-' && s2.at(0) == '-')
        {
            s1 = s1.substr(1);
            s2 = s2.substr(1);
        }
    cout << multi(s1, s2);
    return 0;
}
