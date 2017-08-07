//http://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-1--of-unweighted-and-undirected/

//DAG...works for disconnected graph

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

void topologicalSortUtil(int u,vector<int> adj[],vector<bool>&visited,stack<int>&s)
{
	int i;

	visited[u]=true;

	for(i=0;i<adj[u].size();i++)
		if(!visited[adj[u][i]])
			topologicalSortUtil(adj[u][i],adj,visited,s);
	s.push(u);
}

void topologicalSort(vector<int> adj[],int v)
{
	int u;
	stack<int> s;

	vector<bool>visited(v,false);
	for(u=0;u<v;u++)
	{
		if(!visited[u])
			topologicalSortUtil(u,adj,visited,s);
	}

	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

}

int main()
{
	int v=6;
	vector<int>adj[v];

	addEdge(adj,5,2);
	addEdge(adj,5,0);
	addEdge(adj,4,0);
	addEdge(adj,4,1);
	addEdge(adj,2,3);
	addEdge(adj,3,1);

	cout << "Following is the topological sorting of the following DAG " << endl;
	topologicalSort(adj,v);
	return 0;
}
