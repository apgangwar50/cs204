#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct llchar
{
    bool f;
    ll x;
    char c;
};

struct tree
{
    char c;
    ll data;
    struct tree *parent,*left,*right;
};

struct tree *createtree()
{
    struct tree *temp=(struct tree *)malloc(sizeof(struct tree));
    return temp;
}

ll order(char c)
{
    switch(c)
    {
        case '+':
            return 0;
        case '-':
            return 0;
        case '*':
            return 1;
        case '/':
            return 1;
        case '^':
            return 2;
        default:
            return -1;
    }
    return -1;
}

vector<llchar> itop(string s,bool &error,ll count,string variables[],ll var_val[])
{
    stack<char> st;
    st.push('0');
    ll n = s.size();
    vector<llchar> tt;
    bool flag_num=0;
    bool flag_var=0;
    string var;
    for(ll i=0; i<n; i++)
    {
        if(flag_var==1)
        {
            while((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')&&i<n)
            {
                var+=s[i];
                i++;
            }
            bool flag_init=0;
            ll data;
            for(ll j=0; j<count; j++)
            {
                if(var==variables[j])
                {
                    data=var_val[j];
                    flag_init=1;
                    break;
                }
            }
            var.clear();
            if(flag_init==0)
            {
                error=1;
                return tt;
            }
            llchar temp;
            temp.x=data;
            temp.f=0;
            tt.push_back(temp);
            flag_var=0;
            i--;
        }
        else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
        {
            flag_var=1;
            i--;
        }
        else if(s[i]<='9'&&s[i]>='0')
        {
            if(flag_num==1)
            {
                tt[tt.size()-1].x*=10;
                tt[tt.size()-1].x+=(s[i]-'0');
            }
            else
            {
                llchar temp;
                temp.x=(s[i]-'0');
                temp.f=0;
                tt.push_back(temp);
                flag_num=1;
            }
        }
        else if(s[i] == '(')
        {
            st.push(s[i]);
            flag_num=0;
        }
        else if(s[i] == ')')
        {
            while(st.top()!='0'&&st.top()!='(')
            {
                llchar temp;
                temp.f=1;
                temp.c=st.top();
                st.pop();
                tt.push_back(temp);
            }
            if(st.top()=='(')
            {
                st.pop();
            }
            else
            {
                error=1;
                return tt;
            }
            flag_num=0;
        }
        else if(order(s[i])>=0)
        {
            while(st.top()!='0'&&order(s[i])<=order(st.top()))
            {
                if(s[i]=='^'&&st.top()=='^') break;
                llchar temp;
                temp.c=st.top();
                temp.f=1;
                st.pop();
                tt.push_back(temp);
            }
            st.push(s[i]);
            flag_num=0;
        }
        else
        {
            error=1;
            return tt;
        }

    }
    while(st.top()!='0')
    {
        llchar temp;
        temp.c=st.top();
        temp.f=1;
        st.pop();
        tt.push_back(temp);
    }
    return tt;
}

ll pow(ll x,ll y)
{
    ll t=1;
    while(y--)
    {
        t*=x;
    }
    return t;
}

ll evaluate(struct tree* root)
{
    if(root->left==NULL)
    {
        return root->data;
    }
    else
    {
        switch (root->c)
        {
            case '+':
                return evaluate(root->right)+evaluate(root->left);
            case '-':
                return evaluate(root->right)-evaluate(root->left);
            case '*':
                return evaluate(root->right)*evaluate(root->left);
            case '/':
                return evaluate(root->right)/evaluate(root->left);
            case '^':
                return pow(evaluate(root->right),evaluate(root->left));
        }
    }
    return -1;
}

int main()
{
    ll q;
    cin>>q;
    while(q--)
    {
        ll n;
        cin>>n;
        ll count=0;
        string variables[n];
        ll var_val[n];
        while(n--)
        {
            string s2;
            cin>>s2;
            ll flag_assgn=0;
            ll var_size;
            string s1;
            string uninit_var;

            for(ll i=0; i<s2.size(); i++)
            {
                if(s2[i]=='=')
                {
                    flag_assgn++;
                    var_size=i;
                }
            }
            if(flag_assgn>1)
            {
                cout<<"CANT BE EVALUATED\n";
                continue;
            }
            else if(flag_assgn==1)
            {
                s1=s2.substr(var_size+1,s2.size()-var_size-1);
                uninit_var=s2.substr(0,var_size);
                bool flag_variables_correct=0;

                for(ll i=0; i<var_size; i++)
                {
                    if(!((uninit_var[i]>='a'&&uninit_var[i]<='z')||(uninit_var[i]>='A'&&uninit_var[i]<='Z'))) flag_variables_correct=1;
                }
                if(flag_variables_correct==1)
                {
                    cout<<"CANT BE EVALUATED\n";
                    continue;
                }
            }
            else
            {
                s1=s2;
            }
            ll flag_unary=1;
            string s;
            for(ll i=0; i<s1.size(); i++)
            {
                  if(flag_unary==1&&s1[i]=='-') s+="0";
                  else if((s1[i]>='0'&&s1[i]<='9')||(s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z')) flag_unary=0;
                  else flag_unary=1;
                  s+=s1[i];
            }
            struct tree *root;
            struct tree *cur;
            bool error=0;
            vector<llchar> postfix=itop(s,error,count,variables,var_val);
            if(error==1)
            {
                cout<<"CANT BE EVALUATED\n";
                continue;
            }

            for(ll i=postfix.size(); i>=0; i--)
            {
                if(postfix[i].f==0&&i==postfix.size()-1)
                {
                    struct tree *temp=createtree();
                    temp->data=postfix[i].x;
                    temp->left=temp->right=temp->parent=NULL;
                    cur=root=temp;
                }
                else if(postfix[i].f==1&&i==postfix.size()-1)
                {
                    struct tree *temp=createtree();
                    temp->c=postfix[i].c;
                    temp->left=temp->right=temp->parent=NULL;
                    cur=root=temp;
                }
                else if(postfix[i].f==0)
                {
                    if(cur->left==NULL)
                    {
                        struct tree *temp=createtree();
                        temp->data=postfix[i].x;
                        temp->left=temp->right=NULL;
                        temp->parent=cur;
                        cur->left=temp;
                    }
                    else
                    {
                        struct tree *temp=createtree();
                        temp->data=postfix[i].x;
                        temp->left=temp->right=NULL;
                        temp->parent=cur;
                        cur->right=temp;
                        while(cur->right!=NULL)
                        {
                            if(cur->parent==NULL) break;
                            cur=cur->parent;
                        }
                    }
                }
                else
                {
                    if(cur->left==NULL)
                    {
                        struct tree *temp=createtree();
                        temp->c=postfix[i].c;
                        temp->left=temp->right=NULL;
                        temp->parent=cur;
                        cur->left=temp;
                        cur=temp;
                    }
                    else
                    {
                        struct tree *temp=createtree();
                        temp->c=postfix[i].c;
                        temp->left=temp->right=NULL;
                        temp->parent=cur;
                        cur->right=temp;
                        cur=temp;
                    }
                }
            }
            if(flag_assgn==1)
            {
                bool flag_init=0;

                for(ll j=0; j<count; j++)
                {
                    if(uninit_var==variables[j])
                    {
                        var_val[j]=evaluate(root);
                        flag_init=1;
                        break;
                    }
                }
                if(flag_init==0)
                {
                    variables[count]=uninit_var;
                    var_val[count]=evaluate(root);
                    count++;
                }
            }
            else
            {
                cout<<evaluate(root)<<'\n';
            }
        }
    }
    return 0;
}
