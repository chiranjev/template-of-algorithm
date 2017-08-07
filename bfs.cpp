//http://www.geeksforgeeks.org/bfs-disconnected-graph/
//gfg have used directed graph...so results will be different
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

void bfsUtil(int u,vector<int> adj[],vector<bool>&visited)
{
	int i;

	queue<int> q;

	visited[u]=true;
	q.push(u);

	while(!q.empty())
	{
		u=q.front();

		cout << u << endl;

		q.pop();

		for(i=0;i<adj[u].size();i++)
		{
			if(!visited[adj[u][i]])
			{
				visited[adj[u][i]]=true;
				q.push(adj[u][i]);
			}
		}
	}
}

void bfs(vector<int> adj[],int v)
{
	int u;

	vector<bool>visited(v,false);
	for(u=0;u<v;u++)
	{
		if(!visited[u])
			bfsUtil(u,adj,visited);
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

	addEdge(adj,0,4);
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,1,4);
	addEdge(adj,2,3);
	addEdge(adj,3,4);

	bfs(adj,v);

	return 0;
}