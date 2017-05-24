#include<bots/stdc++.h>
using namespace std;
bool wordBreak(string s, unordered_set<string>& wordDict) {
    s = "!" + s;
    vector<bool> dpArray(s.size());
    dpArray[0] = true;
    for(int i=0; i<s.size(); i++){
        for(int j=i+1; j<s.size(); j++) {
            if(dpArray[j]) continue;
            if(wordDict.find(s.substr(i+1, j-i))!=wordDict.end() && dpArray[i])
                dpArray[j] = true;
        }
    }
    return dpArray[dpArray.size()-1];
}
int main()
{
	return 0;
}
