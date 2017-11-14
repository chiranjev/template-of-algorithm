#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

int n=4;
int visited_all=(1<<n)-1;
int twopown=1<<n;
int dp[4][16];

int dist[10][10]=
{
		{0,20,42,25},
		{20,0,30,34},
		{42,30,0,10},
		{25,34,10,0}
};
int tsp(int mask,int pos)  // mask to denote set of visited cities
{												      //and pos to denote current city index
	if(mask==visited_all)
	{
		return dist[pos][0];		//return distance form last postion to A
	}
	if(dp[pos][mask]!=-1)
		return dp[pos][mask];
	// now from current city, we will try to go to every city and take min ans
	int ans=INT_MAX;
	//visit all the unvisited cities and take the best route
	for(int city=0;city<n;city++)
	{
		if(((1<<city)&mask)==0)
		{
			int newans=dist[pos][city]+tsp(mask|(1<<city),city);
			ans=min(ans,newans);
		}
	}
	return dp[pos][mask]=ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int i,j,k,len,n,sum,count;
	string s;
	int t;
	memset(dp,-1,sizeof(dp));
	cout << tsp(1,0) << endl; 	//start from A and mask for A is 0001 and its position is 0

	return 0;
}
