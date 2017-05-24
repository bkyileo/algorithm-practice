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

bool find(TrieNode* node,string word)
{
	if(word.length()==0 && node->isleaf)
		return true;
	if(word.length()==0 && !node->isleaf)
		return false;
	if(word[0]!='.')
	{
		int index=CHAR_TO_INDEX(word[0]);
        if(!curr->ch[index])
        	return false;
        return find(curr->ch[index],word.substr(1));
	}
	if(word[0]=='.')
	{
		for(int i=0;i<26;++i)
		{
			if(curr->ch[i] && find(curr->ch[i],word.substr(1)))
				return true;
		}
		return false;
	}
}
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
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

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return find(root,word);
    }
private:
    TrieNode* root;
};

int main()
{
	return 0;
}
