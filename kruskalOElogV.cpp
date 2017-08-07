#include<bits/stdc++.h> 

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

void addEdge(vector <pair<int, pair<int,int>>>&edges, int u,int v, int wt)
{
	edges.pb(mp(wt,mp(u,v)));
} 

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



int kruskalMST(vector<pair<int,pair<int,int>>>&edges,int V)
{
	int mstwt=0;

	vector<pair<int,int>>subsets(V+1); // pair -> parent,rank

    for (int i=1;i<=V;i++)
    {
        subsets[i].first=i;
        subsets[i].second=0;
    }

	sort(edges.begin(),edges.end());

	for(auto it=edges.begin();it!=edges.end();it++)
	{
		int u=it->second.first;
		int v=it->second.second;

		int setu=find(subsets,u);
		int setv=find(subsets,v);

		if(setu!=setv)
		{
			cout << u << " - " << v << endl;

			mstwt+=it->first;

			Union(subsets,setu,setv);
		}
	}

	return mstwt;
}
 
int main()
{

    int v=9;
    int e=14;
    vector<pair<int,pair<int,int>>> edges;

    addEdge(edges, 0, 1, 4);
    addEdge(edges, 0, 7, 8);
    addEdge(edges, 1, 2, 8);
    addEdge(edges, 1, 7, 11);
    addEdge(edges, 2, 3, 7);
    addEdge(edges, 2, 8, 2);
    addEdge(edges, 2, 5, 4);
    addEdge(edges, 3, 4, 9);
    addEdge(edges, 3, 5, 14);
    addEdge(edges, 4, 5, 10);
    addEdge(edges, 5, 6, 2);
    addEdge(edges, 6, 7, 1);
    addEdge(edges, 6, 8, 6);
    addEdge(edges, 7, 8, 7);
    
  //  printGraph(adj,v);    
 	int mstwt=kruskalMST(edges,v);
 	cout << "weight of MST is " << mstwt << endl;
    return 0;
}