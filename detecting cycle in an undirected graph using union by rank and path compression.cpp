//http://www.geeksforgeeks.org/union-find/

//works for disconnected graph

// done with two methods....first is using stl and second is using structure

#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;



int find(vector<pair<int,int>> &subsets,int i)
{
	if(subsets[i].first!=i)
		subsets[i].first=find(subsets,subsets[i].first);
	return subsets[i].first;
}

void Union(vector<pair<int,int>> &subsets,int x,int y)
{
	int xroot=find(subsets,x);
	int yroot=find(subsets,y);

	if (subsets[xroot].second<subsets[yroot].second)
        subsets[xroot].first = yroot;
    else if (subsets[xroot].second>subsets[yroot].second)
        subsets[yroot].first = xroot;
    else
    {
        subsets[yroot].first = xroot;
        subsets[xroot].second++;
    }

}

bool isCycle(vector<pair<int,int>> &edges,int v,int e)
{
	int i;
	vector<pair<int,int>>subsets(v+1); // pair -> parent,rank

    for (int i=1;i<=v;i++)
    {
        subsets[i].first=i;
        subsets[i].second=0;
    }

	for(i=0;i<e;i++)
	{
		int x=find(subsets,edges[i].first);
		int y=find(subsets,edges[i].second);

		if(x==y)
			return true;

		Union(subsets,x,y);
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