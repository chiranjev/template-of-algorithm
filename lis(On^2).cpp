#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

int arr[1000001];

void lis(int arr[],int n)
{
    int i,j;
    int temp;
    int dp[n];
    int ans[n];
    fill(dp,dp+n,1);
    
    int maxm=1;
    
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
            if(arr[i]>arr[j]&&dp[i]<=dp[j]+1)
            {
                dp[i]=dp[j]+1;
            }
    }
    for(i=0;i<n;i++)
        if(dp[i]>maxm)
            maxm=dp[i];
    
    temp = maxm;
    vector<int> lisvalues;
    for( i = n - 1; i >= 0; i-- )
    if( dp[ i ] == temp )
    {
        lisvalues.push_back( arr[i] );
        temp--;
    }
    reverse(lisvalues.begin(),lisvalues.end());
   
   cout<< maxm << endl;
   
   for(i=0;i<maxm;i++)
        cout << lisvalues[i] << endl;
            
}

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int t;
	int n;
	int i;

	cin >> t;

	while(t--)
	{
		cin >> n;
		
		for(i=0;i<n;i++)
		    cin >> arr[i];
		    
	lis(arr,n);
	}


	return 0;
}