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

int minDistance(vector<int>&dist,vector<bool>&sptSet,int V)
{
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] < min)
      {
          min = dist[v];
          min_index = v;
      }
   return min_index;
}
 
void printSPT(vector<int> &dist,int V)
{
   printf("Vertex Distance from Source\n");
   for (int i = 0; i < V; i++)
       printf("%d\t\t%d \n",i,dist[i]);
}
 

void dijkstra(vector<pair<int,int>> adj[],int V,int src)
{
     vector<int> dist(V,INT_MAX);
     vector<bool> sptSet(V,false);
 
   
     dist[src] = 0;

     for (int count = 0; count < V-1; count++)
     {
      
        int u = minDistance(dist, sptSet,V);
        
     
        sptSet[u] = true;
 
        for (int v = 0; v < adj[u].size(); v++)
 
          if ( sptSet[adj[u][v].first] == false && adj[u][v].second+dist[u] <  dist[adj[u][v].first])
          {
              dist[adj[u][v].first]=dist[u]+ adj[u][v].second;
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
    printSPT(dist,V);
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
    dijkstra(adj,v,0);//0 is source vertex
    
    return 0;
}