//http://www.geeksforgeeks.org/union-find/

//works for disconnected graph

// done with two methods....first is using stl and second is using structure

#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;



int find(vector<int>&parent,int i)
{
	if(parent[i]==-1)
		return i;
	return find(parent,parent[i]);
}

void Union(vector<int>&parent,int x,int y)
{
	int xset=find(parent,x);
	int yset=find(parent,y);

	parent[xset]=yset;
}

bool isCycle(vector<pair<int,int>> &edges,int v,int e)
{
	int i;
	vector<int>parent(v,-1);

	for(i=0;i<e;i++)
	{
		int x=find(parent,edges[i].first);
		int y=find(parent,edges[i].second);

		if(x==y)
			return true;

		Union(parent,x,y);
	}
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

	
	int v,e,x,y,i;

	vector<pair<int,int>> edges;

	cin >> v >> e; // v=number of vertices e=number of edges

	for(i=0;i<e;i++)
	{
		cin >> x >> y;
		edges.pb(mp(x,y));
	}
 
    if (isCycle(edges,v,e))
        printf( "Graph contains cycle" );
    else
        printf( "Graph doesn't contain cycle" ); 


	return 0;
}

















#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;


typedef struct EDGE
{
	int src,dest;
}Edge;

typedef struct GRAPH
{
	int v,e; // v=number of vertices    e=number of edges

	Edge *edge;
}Graph;

Graph* createGraph(int v,int e)
{
	Graph* graph=(Graph*)malloc(sizeof(Graph));

	graph->v=v;
	graph->e=e;

	graph->edge=(Edge*)malloc(graph->e*sizeof(Edge));

	return graph;
}

int find(vector<int>&parent,int i)
{
	if(parent[i]==-1)
		return i;
	return find(parent,parent[i]);
}

void Union(vector<int>&parent,int x,int y)
{
	int xset=find(parent,x);
	int yset=find(parent,y);

	parent[xset]=yset;
}

bool isCycle(Graph *graph)
{
	int i;
	vector<int>parent(graph->v,-1);

	for(i=0;i<graph->e;i++)
	{
		int x=find(parent,graph->edge[i].src);
		int y=find(parent,graph->edge[i].dest);

		if(x==y)
			return true;

		Union(parent,x,y);
	}
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

	
    int v=3, e=3;
  	Graph* graph = createGraph(v,e);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
 
    if (isCycle(graph))
        printf( "Graph contains cycle" );
    else
        printf( "Graph doesn't contain cycle" ); 


	return 0;
}