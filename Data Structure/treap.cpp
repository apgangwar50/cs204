#include<iostream>
#include<time.h>
using namespace std; 

struct treap_node 
{ 
    int key, priority; 
    struct treap_node *left, *right; 
};

struct treap_node *rightRotate(struct treap_node *y) 
{ 
    struct treap_node *x = y->left,  *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

struct treap_node *leftRotate(struct treap_node *x) 
{
    struct treap_node *y = x->right, *T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

struct treap_node* newNode(int key) 
{ 
    struct treap_node* temp = new struct treap_node;
    temp->key = key;
    temp->priority = rand()%100;
    temp->left = temp->right = NULL;
    return temp;
}

struct treap_node* search(struct treap_node* root, int key) 
{
    if (root == NULL || root->key == key)
       return root;
    if (root->key < key)
       return search(root->right, key);
    return search(root->left, key);
} 

struct treap_node* insert(struct treap_node* root, int key) 
{
    if (!root)
        return newNode(key);
    if (key <= root->key) 
    {
        root->left = insert(root->left, key);
        if (root->left->priority > root->priority) 
            root = rightRotate(root); 
    } 
    else
    {
        root->right = insert(root->right, key);
        if (root->right->priority > root->priority) 
            root = leftRotate(root); 
    } 
    return root; 
}
struct treap_node* deleteNode(struct treap_node* root, int key) 
{ 
    if (root == NULL) 
        return root; 
  
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key);

    else if (root->left == NULL) 
    { 
        struct treap_node *temp = root->right; 
        delete(root); 
        root = temp;
    }
    else if (root->right == NULL) 
    { 
        struct treap_node *temp = root->left; 
        delete(root); 
        root = temp;
    } 

    else if (root->left->priority < root->right->priority) 
    { 
        root = leftRotate(root); 
        root->left = deleteNode(root->left, key); 
    } 
    else
    { 
        root = rightRotate(root); 
        root->right = deleteNode(root->right, key); 
    } 
  
    return root; 
} 

void inorder(struct treap_node* root) 
{ 
    if (root) 
    { 
        inorder(root->left); 
        cout << "key: "<< root->key << " | priority: "
            << root->priority; 
        if (root->left) 
            cout << " | left child: " << root->left->key; 
        if (root->right) 
            cout << " | right child: " << root->right->key; 
        cout << endl; 
        inorder(root->right); 
    } 
} 

int main() 
{ 
    srand(time(NULL)); 
  
    struct treap_node *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20);
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
    cout << "Inorder traversal of the given tree \n"; 
    inorder(root); 
  
    cout << "\nDelete 20\n"; 
    root = deleteNode(root, 20); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout << "\nDelete 30\n"; 
    root = deleteNode(root, 30); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    cout << "\nDelete 50\n"; 
    root = deleteNode(root, 50); 
    cout << "Inorder traversal of the modified tree \n"; 
    inorder(root); 
  
    struct treap_node *res = search(root, 50); 
    (res == NULL)? cout << "\n50 Not Found ": 
                   cout << "\n50 found"; 
  
    return 0; 
}