//http://www.geeksforgeeks.org/detect-cycle-in-a-graph/

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
}

bool isCyclicUtil(int u,vector<int> adj[],vector<bool> &visited,vector<bool> &recStack)
{
	int i;
	if(!visited[u])
	{
		// Mark the current node as visited and part of recursion stack
		visited[u]=true;
		recStack[u]=true;

		for(i=0;i<adj[u].size();i++)
		{
			if(!visited[adj[u][i]]&&isCyclicUtil(adj[u][i],adj,visited,recStack))
				return true;
			else if(recStack[adj[u][i]])
				return true;
		}
	}
	recStack[u]=false;  // remove the vertex from recursion stack

	return false;
}

bool isCyclic(vector<int> adj[],int v)
{
	int u;
	vector<bool> visited(v,false);
	vector<bool> recStack(v,false);

	for(u=0;u<v;u++)
		if(isCyclicUtil(u,adj,visited,recStack))
			return true;

	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int v=4;
	vector<int>adj[v];

	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,2,0);
	addEdge(adj,2,3);
	addEdge(adj,3,3);

	if(isCyclic(adj,v))
		cout << "Graph contains cycle" << endl;
	else
		cout << "Graph doesn't contain cycle" << endl;

	return 0;
}