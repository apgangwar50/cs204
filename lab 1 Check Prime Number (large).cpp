#include <iostream>
#include<bits/stdc++.h>

using namespace std;

#define long long ll

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

int lenZero(string s)
{
	int i=0;
	while(s[i]-'0' == 0){
		i++;
	}
	return i;
}

bool equal(string str1, string str2)
{

    int flag1=0;
    int flag2=0;
    int x1=lenZero(str1);
    int x2=lenZero(str2);
    int n1 = str1.length()-x1, n2 = str2.length()-x2;

    if (n1 < n2)
    return true;
    if (n2 < n1)
    return false;

    for (int i=0; i<n1-x1; i++){
    	if(str1[i+x1]-'0'!=0){
    		flag1=1;
    	}
    	if(str2[i+x2]-'0'!=0){
    		flag2=1;
    	}
    	if(flag1>flag2){
    		return false;
    	}else if(flag2>flag1){
    		return true;
    	}

		if (str1[i+x1] < str2[i+x2] && flag1 && flag2)
        	return true;
    	else if (str1[i+x1] > str2[i+x2] &&flag2 &&flag1)
        	return false;

    }
    return true;
}

string modify(string str){
	int l2=lenZero(str);
	int l1=str.length();
	string stt="";
	for(int i=l2;i<l1;i++){
		stt.push_back(str[i]);
	}
	return stt;
}

string getquo(string str1,string str2){

	int x=0;
	while(larger(str2,str1))
        {str1=largesubs(str1,str2);
		x++;
	}
	return to_string(x);
}

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

string longdiv(string s1, string s2, string q)
{
    if (larger(s1,s2))
    {
        swap(s1,s2);
    }

    int n = s1.size()-lenZero(s1);
    int m = s2.size()-lenZero(s2);

    string s="1";
    int x = n-m-1;
	while(x>0){
		s.push_back('0');
		x--;
	}
	if(n-m-1 > 0){
		string temp1=s1;
		string dat=s1;
		string temp2=s2;
		string tt=getquo(temp1,multi(temp2,s));
		q=multi(s,tt);
		temp2=largesubs(dat,multi(temp2,q));
		temp2=modify(temp2);
		 return longdiv(temp2,s2,q);
	}else{
		return q;
	}
}

bool smaller(string str1, string str2)
{
    // Calculate lengths of both string
    int flag1=0;
    int flag2=0;
    int x1=lenZero(str1);
    int x2=lenZero(str2);
    int n1 = str1.length()-x1, n2 = str2.length()-x2;

    if (n1 < n2)
    return true;
    if (n2 < n1)
    return false;

    for (int i=0; i<n1-x1; i++){
    	if(str1[i+x1]-'0'!=0){
    		flag1=1;
    	}
    	if(str2[i+x2]-'0'!=0){
    		flag2=1;
    	}
    	if(flag1>flag2){
    		return false;
    	}else if(flag2>flag1){
    		return true;
    	}

		if (str1[i+x1] < str2[i+x2] && flag1 && flag2)
        	return true;
    	else if (str1[i+x1] > str2[i+x2] &&flag2 &&flag1)
        	return false;

    }
    return false;
}

int remainder(string str1,string str2)
{
	string stri=str2;
	int l1=str1.length();
	int l2=str2.length();
	string q="0";
	q=longdiv(str1,str2,q);
	str2=multi(str2,q);
	int x=0;
	if(larger(str2,str1)){
		str1=largesubs(str1,str2);
		str1=modify(str1);

	}
	while(larger(stri,str1)){

		str1=largesubs(str1,stri);
		str1=modify(str1);
		x++;
	}
	str1=modify(str1);
	q=largesum(q,to_string(x));

	if(str1.length() >0){
		return 0;
	}else if(str1.length()==1 && str1[0]-'0'!=0){
		return 0;
	}else{
		return 1;
	}

}

void prime(string str)
    {
	string tp="2";
	if(remainder(str,tp))
    {
		cout<<"Not a prime"<<endl;
		return;
	}
	string i="3";
	while(smaller(i,str))
        {
		string temp=str;
		if(remainder(temp,i))
            {
			cout<<"Not a Prime"<<endl;
			return;
            }
		i=largesum(i,tp);
	}
	cout<<"Prime"<<endl;
}



int main()
{
    int n;
    cin>>n;
    string ans[100];

    for(int i= 0; i<n; i++)
    {
    string s1;
    cin>>s1;
    prime(s1);
    }
    return 0;
}
