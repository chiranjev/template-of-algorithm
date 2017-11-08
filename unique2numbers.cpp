#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

void unique2numbers(int arr[],int n)
{
   int res=0;
   for(int i=0;i<n;i++)
   {
      res=res^arr[i];
   }

   int temp=res;
   int i=0;

   while(temp>0)
   {
      if(temp&1)
         break;
      i++;
      temp=temp>>1;
   }

   int mask=1<<i;
   int num1=0;
   int num2=0;
   for(int i=0;i<n;i++)
   {
      if(arr[i]&mask)
      {
         num1=num1^arr[i];
      }
      else
      num2=num2^arr[i];
   }

   cout << min(num1,num2) << " " << max(num1,num2) << endl;

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
	cin >> t;

	while(t--)
	{
		cin >> n;
      int arr[n];
      for(int i=0;i<n;i++)
         cin >> arr[i];

      unique2numbers(arr,n);
	}


	return 0;
}
