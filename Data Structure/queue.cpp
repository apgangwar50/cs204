#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
        int key;
        node* next;
};

class Queue
{
    public:
    node *front, *rear;
};

node* newNode(int k)
{
    node* temp = new node();
    temp->key = k;
    temp->next = NULL;
    return temp;
}

Queue* createQueue()
{
    Queue* q = new Queue();
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue* q, int k)
{
    node* temp = newNode(k);
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

node* deQueue(Queue* q)
{
    if (q->front == NULL)
        return NULL;
    node* temp = q->front;
    delete(temp);

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    return temp;
}

void display(Queue* q)
{
     if (q->front == NULL)
        {
            cout<<"Empty\n";
            return ;
        }

    node* a = q->front;
    while(a->next != NULL)
    {
        cout<<a->key<<" ";
        a=a->next;
        if(a->next == NULL)
            cout<<a->key;
    }
    cout<<endl;
}

int main()
{
    Queue* root = createQueue();
    int x;
    cin >>x;
    while(x!=0)
    {
        if(x==1)
        {
            int a;
            cin>>a;
            enQueue(root, a);
        }
        else if(x==2)
        {
            deQueue(root);
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
