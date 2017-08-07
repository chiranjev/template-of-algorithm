//http://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-1-dfs-of-unweighted-and-undirected/

//undirected graph...works for disconnected graph

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

void dfsUtil(int u,vector<int> adj[],vector<bool>&visited)
{
	int i;

	visited[u]=true;
	cout << u << endl;

	for(i=0;i<adj[u].size();i++)
		if(!visited[adj[u][i]])
			dfsUtil(adj[u][i],adj,visited);
}

void dfs(vector<int> adj[],int v)
{
	int u;

	vector<bool>visited(v,false);
	for(u=0;u<v;u++)
	{
		if(!visited[u])
			dfsUtil(u,adj,visited);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int v=5;
	vector<int>adj[v];

	addEdge(adj,0,1);
	addEdge(adj,0,4);
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,1,4);
	addEdge(adj,2,3);
	addEdge(adj,3,4);

	dfs(adj,v);

	return 0;
}