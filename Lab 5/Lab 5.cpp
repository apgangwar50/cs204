#include <bits/stdc++.h>
using namespace std;
#define INF std::numeric_limits<ll>::max()
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
set<char> abt;
map<string, ll> wrd;
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

ll powerrr(ll a, ll b)
{
    ll ans = 1;
    for(ll i = 0; i < b; i++)
    {
        ans*= a;
    }
    return ans;
}

ll evaluate(struct tree *start)
{
    if(start->a != 'n')
    {
        if(start->a == '^')
        {
            return powerrr(evaluate(start->left),evaluate(start->right));
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
   
    
    for(ll i=0; i<s.length(); i++)
    {
        ll colm=0;
        if(abt.find(s[i]) != abt.end())
        {
            string temp;
            ll j=i;
            while(j < s.length() && abt.find(s[j]) != abt.end())
            {
                temp+=s[j];
                j++;
            }

            if(wrd.find(temp) == wrd.end() || wrd[temp] == INF)
            {
                flagl=1;
                return;
            }
            else
            {
                string temp2="("+to_string(wrd[temp])+")";
                colm=temp2.length();
                if(j<s.length())
                    s=s.substr(0, i) +  temp2 + s.substr(j);
                else 
                    s=s.substr(0, i) + temp2;
            }
            i=i+colm-1;
        }
    }

    if(s[0]=='-')
    {
        if(s[1]!='(')
            {
                start->b=stoll(s);
                return;
            }
        else 
            {
                if(s[2]=='-')
                    s="("+s.substr(3);
                else 
                    swap(s[0], s[1]);
            }
    }

    for(ll i=s.length()-1; i>=0; i--)
    {
       
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
        if(s[i] == ')') bracket.push(s[i]);
        if(s[i] == '(') bracket.pop();
        if(!(bracket.empty())) continue;
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
        if(s[i] == '(') bracket.push(s[i]);
        if(s[i] == ')') bracket.pop();

        if(!(bracket.empty()))continue;
        if(s[i]=='^')
        {
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
    const char numb[] = "0123456789^+*-/()";
    for (int i = 0; i < 17 ; ++i)
        operat.insert(numb[i]);
    
    const char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 52; ++i)
        abt.insert(alpha[i]);


    while(n--)
    {
        ll q;
        cin>>q;
        while(q--)
        {
            flagl=0;
            string s;
            cin>>s;
            ll flag2=0;

            for (int i = 0; i < s.length(); ++i)
            {
                if(s[i] == '=')
                {
                    flag2=1;
                    struct tree *start=createtree();
                    build(s.substr(i+1), start);
                    if(flagl==1)
                        {
                            wrd[s.substr(0,i)]=INF;
                            break;
                        }
                    wrd[s.substr(0,i)] = evaluate(start);
                    break;
                }
            }

            if(flag2)
                continue;

            struct tree *start=createtree();
            build(s, start);
            if(flagl)
                {
                    cout<<"CANT BE EVALUATED"<<endl;
                    continue;
                }
            ll x=evaluate(start);
            cout<<x<<endl;
        }
        wrd.clear();
    }
}