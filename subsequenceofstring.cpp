#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

void filterChar(string s,int no,set<string>&subseqset)
{
   int i=0;
   string subseq="";
   while(no>0)
   {
      if(no&1)
      {
         subseq+=s[i];
      }
      i++;
      no=no>>1;
   }

   cout << subseq << endl;
   subseqset.insert(subseq);

}

void generateSubsequence(string s,int len)
{
   set<string> subseqset;
   int range=(1<<len)-1;

   for(int i=0;i<=range;i++)
   {
      filterChar(s,i,subseqset);
   }

   // for(int i=0;i<subseqset.size();i++)
   // {
   //    cout << subseqset.at(i) << endl;
   // }
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
   int len;
   string s;

	cin >> t;

	while(t--)
	{
      cin >> len;
      cin >> s;

      generateSubsequence(s,len);
	}


	return 0;
}
