//   using suffix trie...........
//there are 2 programs in it.........
//2nd one is more efficient



#include<bits/stdc++.h>

using namespace std;

struct trienode
{
	struct trienode* children[26];
};

struct trienode *newNode()
{
	struct trienode *pNode=NULL;
	pNode=(struct trienode*)malloc(sizeof(struct trienode));

	if(pNode)
	{
		int i;

		for(i=0;i<26;i++)
			pNode->children[i]=NULL;
		// or we can use   memset(children,0,sizeof(children));
	}

	return pNode;
}

void insertSuffix(struct trienode *root,string s)
{
	if(s.length()>0)
	{
		int cIndex=s.at(0)-'A';
		if(root->children[cIndex]==NULL)
			root->children[cIndex]=newNode();
		insertSuffix(root->children[cIndex],s.substr(1));
	}
}

int countNodesInTrie(struct trienode *pNode)
{
	if(pNode==NULL)
		return 0;

	int count=0;
	for(int i=0;i<26;i++)
	{
		if(pNode->children[i]!=NULL)
			count+=countNodesInTrie(pNode->children[i]);
	}

	return 1+count;
}

void insertInTrie(struct trienode *root,string s)
{
	int i;
	for(i=0;i<s.length();i++)
		insertSuffix(root,s.substr(i));
}

int main()
{
	string str="ABABA";

	struct trienode *root=newNode();

	insertInTrie(root,str);

	cout << "count of distinct substrings is " << countNodesInTrie(root) << endl;   // also includes empty string as substring

	return 0;
}












/*





#include<iostream>
#include<cstdio>
using namespace std;

struct trienode
{
	struct trienode* children[52];
};

struct trienode *newNode()
{
	struct trienode *pNode=NULL;
	pNode=(struct trienode*)malloc(sizeof(struct trienode));

	if(pNode)
	{
		int i;

		for(i=0;i<52;i++)
			pNode->children[i]=NULL;
		// or we can use   memset(children,0,sizeof(children));
	}

	return pNode;
}

void insertSuffix(struct trienode *root,string s)
{
    int i,index;
    
    for(i=0;i<s.length();i++)
    {
        if(s.at(i)>='a'&&s.at(i)<='z')
            index=s.at(i)-'a';
        else
            index=s.at(i)-'A'+26;
        if(root->children[index]==NULL)
            root->children[index]=newNode();
        root=root->children[index];
    }
// 	if(s.length()>0)
// 	{
// 	    int cIndex=s.at(0);
// 		if(root->children[cIndex]==NULL)
// 			root->children[cIndex]=newNode();
//     	insertSuffix(root->children[cIndex],s.substr(1));
// 	}
}

int countNodesInTrie(struct trienode *pNode)
{
	if(pNode==NULL)
		return 0;

	int count=0;
	for(int i=0;i<52;i++)
	{
		if(pNode->children[i]!=NULL)
			count+=countNodesInTrie(pNode->children[i]);
	}

	return 1+count;
}

void insertInTrie(struct trienode *root,string s)
{
	int i;
	for(i=0;i<s.length();i++)
		insertSuffix(root,s.substr(i));
}

int main()
{
    
    int t;
    string str;
    
    scanf("%d",&t);
    while(t--)
    {
        cin >> str;
    	struct trienode *root=newNode();
    
    	insertInTrie(root,str);
    
    	printf("%d\n",countNodesInTrie(root)-1);   // also includes empty string as substring
    }
	return 0;
}



*/