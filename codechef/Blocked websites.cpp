#include<bits/stdc++.h>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
		memset(ch,0,sizeof(ch));
        isleaf=false;
    }
    TrieNode* ch[26];
	bool isleaf;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        res.clear();
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
			curr=curr->ch[index];
		}
		curr->isleaf=true;
    }

    void block(string word) {
    	//cout<<word<<endl;
    	int index;
    	int num=0;
    	TrieNode* curr=root;
    	for(int i=0;i<word.length();++i)
    	{
    		index=CHAR_TO_INDEX(word[i]);
    		if(!curr->ch[index])
    		{
    			num++;
    			res.insert(word.substr(0,num));
    			return ;
			}
			num++;
			curr=curr->ch[index];
		}
    }

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
	
	void print()
	{
		cout<<res.size()<<endl;
		for(auto i:res)cout<<i<<endl;
	}
private:
    TrieNode* root;
    set<string> res;
};


int main()
{
	int t;cin>>t;
	vector<string> ss1;
	vector<string> ss2;
	char ch;string curr;
	while(t--)
	{
		cin>>ch>>curr;
		if(ch=='+')ss1.push_back(curr);
		if(ch=='-')ss2.push_back(curr);
	}
	Trie trie;
	for(auto i:ss1)
	{
		trie.insert(i);
	}
	for(auto i:ss2)
	{
		if(trie.startsWith(i))
		{
			cout<<-1<<endl;
			return 0;
		}
		else
		{
			trie.block(i);
		}
	}
	trie.print();
	return 0;
	
}

