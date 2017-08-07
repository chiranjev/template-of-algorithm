#include<bits/stdc++.h>

using namespace std;
 
struct TrieNode
{
    struct TrieNode *children[26];
    bool isLeaf; // isLeaf is true if the node represents end of a word
};
 
struct TrieNode *newNode()  // Returns new trie node (initialized to NULLs)
{
    struct TrieNode *pNode = NULL;
 
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
 
    if (pNode)
    {
        int i;
 
        pNode->isLeaf = false;
 
        for (i = 0; i < 26; i++)
            pNode->children[i] = NULL;
    }
 
    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root,string key)
{
    int level;
    int length = key.length();
    int index;
 
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = (int)key[level]-(int)'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = newNode();
 
        pCrawl = pCrawl->children[index];
    }
    
    // mark last node as leaf
    pCrawl->isLeaf = true;
}

// Returns true if key presents in trie, else false 
bool search(struct TrieNode *root, string key)
{
    int level;
    int length = key.length();
    int index;
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = (int)key[level]-(int)'a';
 
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl != NULL && pCrawl->isLeaf);
}


int leafNode(struct TrieNode *root)
{
    return (root->isLeaf != false);
}
 
int isItFreeNode(struct TrieNode *pNode)
{
    int i;
    for(i = 0; i < 26; i++)
    {
        if( pNode->children[i] )
            return 0;
    }
 
    return 1;
}

bool deleteKey(struct TrieNode *root,string key,int level,int len)
{
    struct TrieNode *pCrawl = root;

    if(pCrawl)
    {
        // Base case
        if( level == len )
        {
            if(pCrawl->isLeaf)
            {
                // Unmark leaf node
               pCrawl->isLeaf=false;
                
                // If empty, node to be deleted
                if( isItFreeNode(pCrawl) )
                {
                    return true;
                }
 
                return false;
            }
        }
        else // Recursive case
        {
            int index = (int)key[level]-(int)'a';
 
            if( deleteKey(pCrawl->children[index], key, level+1, len) )
            {
                // last node marked, delete it
                free(pCrawl->children[index]);    \
                pCrawl->children[index] = NULL;
    
                // recursively climb up, and delete eligible nodes
                return ( !leafNode(pCrawl) && isItFreeNode(pCrawl) );
            }
        }
    }
 
    return false;
}

 
int main()
{
    // input keys should contain 'a' to 'z' in lower case
    vector<string> keys = {"the", "a", "there", "answer", "any",
                     "hello", "bye", "their","b"};
 
    vector<string> output = {"Not present in trie", "Present in trie"};

    struct TrieNode *root = newNode();
 
    int i;
    
    // Construct trie
    for(i = 0; i <keys.size(); i++)
        insert(root, keys[i]);
        
    cout <<  "bye --- " << output[search(root, "bye")] << endl;
    cout <<  "b --- " << output[search(root, "b")] << endl;
    
    deleteKey(root, keys[6],0,keys[6].length());
 
    cout <<  "the --- " << output[search(root, "the")] << endl;
    cout <<  "these --- " << output[search(root, "these")] << endl;
    cout <<  "their --- " << output[search(root, "their")] << endl;
    cout <<  "thaw --- " << output[search(root, "thaw")] << endl;
    cout <<  "any --- " << output[search(root, "any")] << endl;
    cout <<  "answer --- " << output[search(root, "answer")] << endl;
    cout <<  "byee --- " << output[search(root, "byee")] << endl;
    cout <<  "bye --- " << output[search(root, "bye")] << endl;
    cout <<  "b --- " << output[search(root, "b")] << endl;
    return 0;
}