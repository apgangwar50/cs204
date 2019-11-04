#include<bits/stdc++.h>
using namespace std;

struct tree
    {
        int key;
        tree * left;
        tree * right;
    };

struct tree *newnode(int val)
{
    tree *node = new tree;
    node->key = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct tree* ins(struct tree* tmp, int val)
{
        if (tmp == NULL)
            return newnode(val);

        if (val < tmp->key)
        {
            tmp->left = ins(tmp->left, val);
        }
        else if  (val > tmp->key)
        {
             tmp->right = ins(tmp->right,val);
        }
    return tmp;
}

struct tree* minn(struct tree* root)
    {
       struct tree* curr = root;
       while(curr && curr->left !=NULL)
            curr = curr -> left;
       return curr;
    }

tree* del(struct tree* root, int key)
    {
        if(root==NULL)
            return root;
        if(key< root->key)
        {
            root->left = del(root->left, key);
        }

        else if(key >root->key)
        {
            root->right = del(root->right, key);
        }

        else
        {
            if(root->left == NULL)
            {
                struct tree *tmp = root->right;
                free(root);
                return tmp;
            }
            else if (root->right == NULL)
            {
                struct tree *tmp = root->left;
                free(root);
                return tmp;
            }

            struct tree* tmp  = minn(root->right);
            root->key = tmp->key;
            root->right = del(root->right, tmp->key);
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
