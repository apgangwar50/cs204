#include<bits/stdc++.h>

using namespace std;

class graph
{
    private:
        int V;
        list<int> * adj;
    public:
        graph(int);
        void add_edge(int, int);
        void DFS(int);
        void BFS(int);
        void print_adj();
};

graph::graph(int n)
{
    V = n;
    adj =  new list<int>[V];
}

void graph::add_edge(int v, int u)
{
    adj[v].push_back(u);
}

void graph::print_adj()
{
    for(int i = 0; i < V; i++)
    {
        cout << i << " : ";
        for(auto x = adj[i].begin(); x != adj[i].end(); x++)
            cout << *x <<  ' ';
        cout << '\n';
    }
}
void graph::DFS(int v)
{
    static vector<bool> visited(V, false);
    if(!visited[v])
    {
        visited[v] = true;
        cout << v << ' ';
        for(auto x = adj[v].begin(); x != adj[v].end(); x++)
            DFS(*x);
    }
}

void graph::BFS(int s)
{
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 

    list<int> queue; 
    visited[s] = true; 
    queue.push_back(s); 
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    {
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 

        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    }
}

int main()
{ 
    graph g(4); 
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(1, 2); 
    g.add_edge(2, 0); 
    g.add_edge(2, 3); 
    g.add_edge(3, 3); 

    g.BFS(2);
    cout<<endl;
    g.DFS(2);
    cout<<endl;
}