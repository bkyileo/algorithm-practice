/*
Implement a trie with insert, search, and startsWith methods.
Note:
You may assume that all inputs are consist of lowercase letters a-z.
Subscribe to see which companies asked this question
*/
#include<bits/stdc++.h>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
		memset(ch,0,sizeof(ch));
        isleaf=false;
        count=0;
    }
    TrieNode* ch[26];
	bool isleaf;
	int count;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
    	int index;
    	TrieNode* curr=root;
    	for(int i=0;i<word.length();++i)
    	{
    		index=CHAR_TO_INDEX(word[i]);
    		if(!curr->ch[index])
    		{
    			curr->ch[index] = new TrieNode();
			}
			curr->count++;
			curr=curr->ch[index];

		}
		curr->count++;
		curr->isleaf=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
    	int index;
    	TrieNode* curr=root;
        for(int i=0;i<word.size();++i)
        {
        	index=CHAR_TO_INDEX(word[i]);
        	if(!curr->ch[index])
        		return false;
        	curr=curr->ch[index];
		}
		if(curr->isleaf)
			return true;
		else
			return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int index;
        TrieNode* curr=root;
        for(int i=0;i<prefix.size();++i)
        {
        	index=CHAR_TO_INDEX(prefix[i]);
        	if(!curr->ch[index])
        		return false;
        	curr=curr->ch[index];
		}
		return true;
	}
		
    int startsCount(string prefix) {
        int index;
        TrieNode* curr=root;
        for(int i=0;i<prefix.size();++i)
        {
        	index=CHAR_TO_INDEX(prefix[i]);
        	if(!curr->ch[index])
        		return 0;
        	curr=curr->ch[index];
		}
		return curr->count;	
    }
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
int main()
{
	Trie trie;
	int n,m;
	cin>>n;
	string s;
	while(n--)
	{
		cin>>s;
		trie.insert(s);
	}
	cin>>m;
	while(m--)
	{
		cin>>s;
		cout<<trie.startsCount(s)<<endl;
	}
	return 0;
}
// Trie trie;
// trie.insert("somestring");
// trie.search("key"); 
