//https://github.com/mission-peace/interview/blob/master/src/com/interview/array/LongestIncreasingSubSequenceOlogNMethod.java
//https://www.youtube.com/watch?v=S9oUiVYEq7E

#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

int arr[1000001];

void printlcs(int arr[],int r[],int index)
{
    if(index==-1)
        return;
    else
    {
        printlcs(arr,r,r[index]);
        
        cout << arr[index] << endl;
    }
}

int ceilIndex(int arr[],int t[],int end,int s)
{
    int start=0;
    int middle;
    int len=end;

    while(start<=end)
    {
        middle=(start+end)/2;

        if(middle<len&&arr[t[middle]]<s&&s<=arr[t[middle+1]])
            return middle+1;
        else if(arr[t[middle]]<s)
        {
            start=middle+1;
        }
        else
            end=middle-1;
    }

    return -1;
}

void lis(int arr[],int n)
{
    int t[n];
    int r[n];
    int i;
    fill(r,r+n,-1);

    t[0]=0;
    int len=0;
    int index;

    for(i=1;i<n;i++)
    {
        if(arr[t[0]]>arr[i]) ////if arr[i] is less than 0th value of t[] then replace it there.
            t[0]=i;
        else if(arr[t[len]]<arr[i]) //if arr[i] is greater than last value of t[] then append it in t[]
        {
            len++;
            t[len]=i;
            r[t[len]]=t[len-1];
        }
        else
        {
            index=ceilIndex(arr,t,len,arr[i]);
            t[index]=i;
            r[t[index]]=t[index-1];
        }
    }
    
     cout << len+1 << endl;  //length of lcs
        
    
            
    index=t[len];

    while(index!=-1)  //lcs in reverse order
    {
        cout << arr[index] << endl;;
        index=r[index];
    }
    
    cout << endl << endl;
    
    index=t[len];
    
    printlcs(arr,r,index); // lcs in increasing order

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