#include<bits/stdc++.h> 
using namespace std;
void addEdge(vector <pair<int, int> >adj[], int u,int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
} 

void printGraph(vector<pair<int,int> >adj[], int V)
{
    cout << endl;
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}

int minKey(vector<int>&key,vector<bool>mstSet,int V)
{
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
      {
          min = key[v];
          min_index = v;
      }
   return min_index;
}
 
void printMST(vector<int> &parent, int V,vector<int> &key)
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
       printf("%d - %d    %d \n", parent[i],i,key[i]);
}
 

void primMST(vector<pair<int,int>> adj[],int V)
{
     vector<int> parent(V);
     vector<int> key(V,INT_MAX);
     vector<bool> mstSet(V,false);
 
   
     key[0] = 0; 
     parent[0] = -1;
 

     for (int count = 0; count < V-1; count++)
     {
      
        int u = minKey(key, mstSet,V);
        
     
        mstSet[u] = true;
 
        for (int v = 0; v < adj[u].size(); v++)
 
          if ( mstSet[adj[u][v].first] == false && adj[u][v].second <  key[adj[u][v].first])
          {
              parent[adj[u][v].first]  = u;
              key[adj[u][v].first] = adj[u][v].second;
          }
     }
 /*   int i;
    for(i=0;i<V;i++)
        cout << parent[i] << " " ;
    cout << endl;
    for(i=0;i<V;i++)
        cout << mstSet[i] << " ";
    cout << endl;
    for(i=0;i<V;i++)
        cout << key[i] << " ";
    cout << endl;
  */
    printMST(parent,V,key);
}
 
 
int main()
{

  int v=9;

  vector<pair<int,int>> adj[v];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
    
  //  printGraph(adj,v);    
 primMST(adj,v);
 
    return 0;
}