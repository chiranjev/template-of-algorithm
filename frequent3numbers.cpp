#include<bits/stdc++.h>

using namespace std;

bool sortinrev(const pair<int,int> &a, 
               const pair<int,int> &b)
{
        if (a.first != b.first) {
      return a.first > b.first;
    }
    return a.second > b.second;
}

void mostFreq3(int *a, int n, int b[3]) 
{

// Write your code here
// hint: sort a, find biggest 3 blocks
  
  sort(a,a+n);
  int i;
  vector<pair<int,int>> v;
  int count=1;
  for(i=1;i<n;i++)
  {
      
      if(a[i-1]==a[i])
      {
          count++;
          continue;
      }
      v.push_back(make_pair(count,a[i-1]));
      count=1;
      
  }
    v.push_back(make_pair(count,a[n-1]));
 sort(v.begin(),v.end(),sortinrev);

 int sz=v.size();
  b[0]=v[0].second;
  b[1]=v[1].second;
  b[2]=v[2].second;
}


int main()
{
	int n;
	int a[100];
	int b[3];
	int i=0;

	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}

	mostFreq3(a,n,b);
        for(i=0; i<3; i++)
            cout << b[i] << " ";

	return 0;
}