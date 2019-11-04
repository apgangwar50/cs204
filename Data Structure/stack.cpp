#include<bits/stdc++.h>
using namespace std;
class stacks
{
    int stack[1000];
    int n= 1000;
    int top = -1;

    public:

        void pop()
        {
            if(top<=-1)
            {
                cout<<"Stack Underflow";
                return ;
            }
            stack[top]=-1;
            top--;
            cout<<"deleted"<<endl;
        }

        void push(int val)
        {
            top++;
            if(top>n)
            {
                cout<<"Stack Overflow";
                return ;
            }
            stack[top]=val;
            cout<<"inserted"<<endl;
        }

        void display()
        {
            if(top>=0)
            {

            for(int i=0; i<=top; i++)
            {
                cout<<stack[i]<<" ";
            }
            cout<<endl;
            }
        }
};

int main()
{
    stacks s;
    int x;
    cin >>x;
    while(x!=0)
    {
        if(x==1)
        {
            int a;
            cin>>a;
            s.push(a);
        }
        else if(x==2)
        {
            s.pop();
        }

       else  if(x==3)
        {
            s.display();
        }
        else
        {
            cout<<"invalid input"<<endl;
        }

        cin>>x;
    }
    return 0;
}
