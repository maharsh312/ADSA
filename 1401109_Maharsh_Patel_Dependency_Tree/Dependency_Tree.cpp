#include<iostream>
#include <list>
#include <stack>
using namespace std;
 
 class cell
 {
 	public:	
 	string formula;
 	int value;
 };
class Graph
{
    int V;    
 	list<cell> *adj;
 	void topologicalSortUtil(cell v, bool visited[], stack<cell> &Stack);
 	stack FormulaStack
public:
    Graph(int V);   
 	void addEdge(cell v, cell w);
 	void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<cell>[V];
}
 
void Graph::addEdge(cell v, cell w)
{
    adj[v.index].push_back(w); 
}
 

void Graph::topologicalSortUtil(cell v, bool visited[], stack<cell> &Stack)  // it uses dfs
{
    
    visited[v.index] = true;
    
 	list<int>::iterator i;
    for (i = adj[v.index].begin(); i != adj[v.index].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    if(v.formula)
    Stack.push(v.formula);
    else
    Stack.push(v.value);
}
 

void Graph::topologicalSort()  // for topological sorting
{
    stack<cell> Stack;
 
    
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
   
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);
 
  
    while (Stack.empty() == false)
    {
        cout << Stack.top().index << " ";
        Stack.pop();
    }
}
 

int main()      // main method implement by hand for 2x2 matrix
{
    Graph g(4);       //for 2x2 matrix
    g.addEdge(0, 3);  //A1
    g.addEdge(0, 2);  //A2=A1
    g.addEdge(2, 3);  //B1=A1+A2
 
    cout << "Following is a Topological Ordering of the given graph \n";
    g.topologicalSort();
 
    return 0;
}
