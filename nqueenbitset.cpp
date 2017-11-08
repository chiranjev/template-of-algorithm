#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

bitset<100> col,d1,d2;

void solveNQueen(int r,int n,int &ans)
{
   if(r==n)
   {
      ans++;
      return;
   }
   else
   {
      for(int c=0;c<n;c++)
      {
         if(!col[c]&&!d1[r-c+n-1]&&!d2[r+c])
         {
            col[c]=d1[r-c+n-1]=d2[r+c]=1;
            solveNQueen(r+1,n,ans);
            col[c]=d1[r-c+n-1]=d2[r+c]=0;
         }
      }
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

	int n;

   cin >> n;
   int ans=0;

   solveNQueen(0,n,ans);

   cout << ans << endl;

	return 0;
}
