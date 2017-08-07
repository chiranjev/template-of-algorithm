//http://www.geeksforgeeks.org/union-find/

//works for disconnected graph
#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}

bool isCycleUtil(vector<int> adj[],int v,vector<bool> &visited,int parent)
{
    int i;
    visited[v]=true;

    for(i=0;i<adj[v].size();i++)
    {
        if(!visited[adj[v][i]])
            if(isCycleUtil(adj,adj[v][i],visited,v))
                return true;
        else if(adj[v][i]!=parent)
            return true;
    }
    return false;
}

bool isCyclic(vector<int> adj[],int v)
{
    int u;
    vector<bool> visited(v,false);

    for(u=0;u<v;u++)
        if(!visited[u])
            if(isCycleUtil(adj,u,visited,-1))  //is1 is parent of starting node in each disconnected graph
                return true;
    return false;

}


int main()
{
	int v=5;
	vector<int>adj[v];

	addEdge(adj,1,0);
	addEdge(adj,0,2);
	addEdge(adj,2,0);
	addEdge(adj,0,3);
	addEdge(adj,3,4);
	

	if(isCyclic(adj,v))
		cout << "Graph contains cycle" << endl;
	else
		cout << "Graph doesn't contain cycle" << endl;



	return 0;
}
