#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
ll powerrr(ll a, ll b)
{
    ll ans = 1;
    for(ll i = 0; i < b; i++)
    {
        ans*= a;
    }
    return ans;
}

set<char> operat;
ll flagl;
stack<char> bracket;

struct tree
{
    char a;
    ll b;
    struct tree *left;
    struct tree *right;
};

struct tree *createtree()
{
    struct tree *temp=(struct tree *)malloc(sizeof(struct tree));
    temp->a='n';
    temp->b=-1;
    return temp;
}

ll evaluate(struct tree *start)
{
    if(start->a != 'n')
    {
        if(start->a == '^')
        {
            return powerrr(evaluate(start->left), evaluate(start->right));
        } 
        else if(start->a == '*')
        {
            return evaluate(start->left)*evaluate(start->right);
        } 
        else if(start->a == '/')
        {
            return evaluate(start->left)/evaluate(start->right);
        } 
        else if(start->a=='+')
        {
            return evaluate(start->left)+evaluate(start->right);
        } 
        else 
        {
            return evaluate(start->left)-evaluate(start->right);
        }
    }
     else 
    {
        return start->b;
    }
}

void build(string s, struct tree *start)
{
    operat.insert('0');
    operat.insert('1');
    operat.insert('2');
    operat.insert('3');
    operat.insert('4');
    operat.insert('5');
    operat.insert('6');
    operat.insert('7');
    operat.insert('8');
    operat.insert('9');
    operat.insert('^');
    operat.insert('+');
    operat.insert('*');
    operat.insert('-');
    operat.insert('/');
    operat.insert('(');
    operat.insert(')');
    for(ll i=0; i<s.length(); i++)
    {
        if(operat.find(s[i]) == operat.end())
        {
            flagl=1;
            return;
        }
    }

    if(s[0]=='-')
    {
        start->b=stoll(s);
        return;
    }

    for(ll i=s.length()-1; i>=0; i--)
    {
        if(operat.find(s[i]) == operat.end())
        {
            flagl=1;
            return;
        }

        if(s[i] == ')')bracket.push(s[i]);
        if(s[i] == '(')bracket.pop();

        if(!(bracket.empty()))continue;

        if(s[i]=='+' || s[i]=='-')
        {
            start->a=s[i];
            string b=s.substr(0,i);
            string c=s.substr(i+1, s.length()-1-i);
            start->left=createtree();
            start->right=createtree();
            build(b, start->left);
            build(c, start->right);
            return;
        }
    }

    for(ll i=s.length()-1; i>=0; i--)
    {
        if(operat.find(s[i]) == operat.end()){

            flagl=1;
            return;

        }
        if(s[i] == ')') bracket.push(s[i]);
        if(s[i] == '(') bracket.pop();
        if(!(bracket.empty()))continue;
        if(s[i]=='*' || s[i]=='/')
        {
            start->a=s[i];
            string b=s.substr(0,i);
            string c=s.substr(i+1, s.length()-1-i);
            start->left=createtree();
            start->right=createtree();
            build(b, start->left);
            build(c, start->right);
            return;
        }
    }

     for(ll i=0; i<s.length(); i++)
    {
        if(operat.find(s[i]) == operat.end())
        {
            flagl=1;
            return;
        }

        if(s[i] == '(')bracket.push(s[i]);
        if(s[i] == ')')bracket.pop();
        if(!(bracket.empty()))continue;
        if(s[i]=='^'){

            start->a='^';
            string b=s.substr(0,i);
            string c=s.substr(i+1, s.length()-1-i);
            start->left=createtree();
            start->right=createtree();
            build(b, start->left);
            build(c, start->right);
            return;
        }
    }

     for(ll i=0; i<s.length(); i++)
    {

         if(operat.find(s[i]) == operat.end()){

            flagl=1;
            return;

        }

        if(s[i]=='(')
        {

            stack<char> flag;
            flag.push('(');
            for(int j=i+1; j<s.length();j++)
            {
            if(s[j]=='(')flag.push('(');
            if(s[j]==')')
            {
               flag.pop();
            }
            if(flag.empty())
             {
                string b=s.substr(i+1, j-1-i);
                build(b, start);
                return;
              }
            }
        }
    }
    start->b=stoll(s);
}

int main()
{
    ll n;
    cin>>n;

    while(n--)
    {
        ll q;
        cin>>q;
        while(q--)
        {
            flagl=0;
            string s;
            cin>>s;
            struct tree *start=createtree();
            build(s, start);
            ll x=evaluate(start);
            if(flagl)cout<<"CAN NOT BE EVALUATED"<<endl;
            else cout<<x<<endl;
        }
    }
}