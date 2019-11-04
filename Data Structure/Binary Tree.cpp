#include<bits/stdc++.h>
using namespace std;

struct tree
    {
        int key;
        tree * left;
        tree * right;
        tree * parent;
    };

struct tree *newnode(int val)
{
    tree *node = new tree;
    node = new tree;
    node->key = val;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void ins(struct tree* tmp, int val)
{
    queue<struct tree*> t;
    t.push(tmp);

    while (!t.empty())
        {
        struct tree* tmp = t.front();
        t.pop();

        if (!tmp->left)
        {
            tmp->left = newnode(val);
            break;
        }
        else
        {
             t.push(tmp->left);
        }

        if (!tmp->right)
        {
            tmp->right = newnode(val);
            break;
        }
        else
        {
            t.push(tmp->right);
        }
    }
}

void dellast(struct tree* root, struct tree* nd)
    {
        queue<struct tree*> t;
        t.push(root);
        struct tree* tmp;

        while (!t.empty())
            {

            tmp = t.front();
            t.pop();

            if (tmp == nd)
            {
                tmp = NULL;
                delete (nd);
                return;
            }

            if (tmp->right)
            {
                if (tmp->right == nd)
                {
                    tmp->right = NULL;
                    delete (nd);
                    return;
                }
                else
                {
                    t.push(tmp->right);
                }
            }

            if (tmp->left)
            {
                if (tmp->left == nd)
                {
                    tmp->left = NULL;
                    delete (nd);
                    return;
                }
                else
                {
                    t.push(tmp->left);
                }
            }
        }
    }

tree* del(struct tree* root, int key)
    {
        if(root==NULL)
            return NULL;

        if(root->left ==NULL && root->right ==NULL)
        {
            if(root->key == key)
                return NULL;
            else return root;
        }

        queue<struct tree*> t;
        t.push(root);

        struct tree* tmp;
        struct tree* nkey = NULL;
        while(!t.empty())
        {
            tmp= t.front();
            t.pop();
            if(tmp->key == key)
                nkey = tmp;
            if(tmp->left)
                t.push(tmp->left);
            if(tmp->right)
                t.push(tmp->right);
        }
        if(nkey != NULL)
        {
            int abc = tmp->key;
            dellast(root, tmp);
            nkey->key = abc;
        }
        return root;
    }

void display(struct tree* tmp)
    {
            if(!tmp)
                return;
            display(tmp->left);
            cout<<tmp->key <<" ";
            display(tmp->right);
    }


int main()
{
    struct tree* root;
    int count = 0;
    int x;
    cin >>x;
    while(x!=0)
    {
        if(x==1)
        {
            int a;
            cin>>a;
            if(count == 0)
            {
                root = newnode(a);
                count = 1;
            }
            else
            {
             ins(root, a);
            }
        }
        else if(x==2)
        {
            int a;
            cin>>a;
            root = del(root, a);
        }

       else  if(x==3)
        {
            display(root);
        }
        else
        {
            cout<<"invalid input"<<endl;
        }

        cin>>x;
    }
    return 0;
}
