 
#include<iostream>
using namespace std;

template<typename data_type>

class linked_list
{
    private:
        int linked_list_size;
        struct linked_list_node
        {
            data_type value;
            linked_list_node* next_node;
            linked_list_node* prev_node;
        };
        linked_list_node* head;
        linked_list_node* tail;
        linked_list_node* make_node()
        {
            return (linked_list_node*)(malloc(sizeof(linked_list_node)));
        }
        struct linked_list_node* find(data_type key)
        {
            struct linked_list_node* pointer=head;
            while(pointer!=NULL)
            {
                if(pointer->value==key)
                    return pointer;
                pointer=pointer->next_node;
            }
            return NULL;
        }
    public:
        linked_list()
        {
            linked_list_size=0;
            head=NULL;
            tail=NULL;
        }
        bool push_after(data_type data,linked_list_node* pointer)
        {
            if(pointer==NULL) 
                return false;
            linked_list_node* new_node=make_node();
            new_node->value=data;
            new_node->prev_node=pointer;
            new_node->next_node=pointer->next_node;
            pointer->next_node=new_node;
            if(new_node->next_node!=NULL)
                (new_node->next_node)->prev_node=new_node;
            linked_list_size++;
            if(head==pointer)
                head=new_node;
            return true;
        }
        bool push_before(data_type data,linked_list_node* pointer)
        {
            if(pointer==NULL) 
                return false;
            linked_list_node* new_node=make_node();
            new_node->value=data;
            new_node->next_node=pointer;
            new_node->prev_node=pointer->prev_node;
            pointer->prev_node=new_node;
            if(new_node->prev_node!=NULL)
                (new_node->prev_node)->next_node=new_node;
            linked_list_size++;
            if(tail==pointer)
                tail=new_node;
            return true;
        }
        bool push_back(data_type data)
        {
            if(linked_list_size==0)
            {
                linked_list_node* new_node=make_node();
                new_node->value=data;
                new_node->prev_node=NULL;
                new_node->next_node=NULL;
                head=tail=new_node;
                linked_list_size++;
            }
            else
            {
                push_after(data,head);
            }
            return true;
        }
        bool push_front(data_type data)
        {
            if(linked_list_size==0)
            {
                linked_list_node* new_node=make_node();
                new_node->value=data;
                new_node->prev_node=NULL;
                new_node->next_node=NULL;
                head=tail=new_node;
                linked_list_size++;
            }
            else
            {
                push_before(data,tail);
            }
            return true;
        }
        bool pop_this(linked_list_node* pointer)
        {
            if(pointer==NULL)
                return false;
            if(pointer->prev_node!=NULL)
                (pointer->prev_node)->next_node=pointer->next_node;
            if(pointer->next_node!=NULL)
                (pointer->next_node)->prev_node=pointer->prev_node;
            if(head==pointer)
                head=pointer->prev_node;
            if(tail==pointer)
                tail=pointer->next_node;
            free(pointer);
            linked_list_size--;
            return true;
        }
        bool pop_back()
        {
            if(linked_list_size==0)
                return false;
            else
            {
                pop_this(head);
            }
            return true;
        }
        bool pop_front()
        {
            if(linked_list_size==0)
                return false;
            else
            {
                pop_this(tail);
            }
            return true;
        }
        data_type front()
        {
            return tail->value;
        }
        data_type back()
        {
            return head->value;
        }
        bool count(data_type key)
        {
            struct linked_list_node* pointer=head;
            while(pointer!=NULL)
            {
                if(pointer->value==key)
                    return true;
                pointer=pointer->next_node;
            }
            return false;
        }
        bool pop_key(data_type key)
        {
            struct linked_list_node* pointer;
            while((pointer=find(key))!=NULL)
            {
                pop_this(pointer);
            }
            return true;
        }
        bool empty()
        {
            if(linked_list_size==0) 
                return true;
            else 
                return false;
        }
        int size()
        {
            return linked_list_size;
        }
};

class unordered_set
{
    private:
        linked_list<int> **hash_table;
        int unordered_set_size;
        int hash_table_size;
        int hash_function(int data)
        {
            return data%hash_table_size;
        }
    public:
        unordered_set(int size)
        {
            hash_table=(linked_list<int> **)(malloc(size*sizeof(linked_list<int>*)));
            for(int i=0;i<size;i++)
            {
                hash_table[i]=new linked_list<int>;
            }
            unordered_set_size=0;
            hash_table_size=size;
        }
        bool count(int data)
        {
            return hash_table[hash_function(data)]->count(data);
        }
        bool insert(int data)
        {
            if(count(data))
                return false;
            unordered_set_size++;
            return hash_table[hash_function(data)]->push_back(data);
        }
        bool pop(int data)
        {
            if(!count(data))
                return false;
            unordered_set_size--;
            return hash_table[hash_function(data)]->pop_key(data);
        }
        int size()
        {
            return unordered_set_size;
        }
};

int main()
{
    unordered_set v(10);
    v.insert(2);
    v.insert(12);
    v.insert(22);
    v.insert(22);
    cout<<v.size()<<endl;
    cout<<v.count(22)<<endl;
    v.pop(22);
    cout<<v.count(22)<<endl;
}