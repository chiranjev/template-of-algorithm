//http://www.geeksforgeeks.org/iterative-depth-first-traversal/

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

	stack<int> s;

	s.push(u);

	while(!s.empty())
	{
		u=s.top();
		s.pop();

		if(!visited[u]) //Stack may contain same vertex twice. So we need to print the popped item only if it is not visited.
		{
			cout << u << endl;
			visited[u]=true;
		}

		for(i=0;i<adj[u].size();i++)
		{
			if(!visited[adj[u][i]])
			{
				s.push(adj[u][i]);
			}
		}
	}
	
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