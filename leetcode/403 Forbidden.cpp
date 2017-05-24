#include<bits/stdc++.h> 


using namespace std;

struct Rule {
    bool allow;
    unsigned int ip;
    int mask;
    Rule () : allow(false), ip(0), mask(32) {}
};

inline unsigned int getIp()
{
    unsigned int a, b, c, d;
    char t;
    cin >> a >> t >> b >> t >> c >> t >> d;
    return (a << 24) | (b << 16) | (c << 8) | d;
}

bool solve(vector<Rule> &rules, unsigned int ip)
{
    for (int i=0;i<rules.size();++i) {
        if (rules[i].mask == 0 || (ip ^ rules[i].ip) >> (32-rules[i].mask) == 0)
        	{
        	cout<<(ip>>29)<<" "<<(rules[i].ip>>29)<<endl;
        	cout<<(ip ^ rules[i].ip)<<endl;
            return rules[i].allow;
        }
    }
    return true;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<Rule> rules(n);
    string cmd;
    char t;
    for (int i = 0; i < n; ++i) {
        cin >> cmd;
        rules[i].allow = cmd == "allow";
        rules[i].ip = getIp();
        cin >> t;
        if (t == '/')
            cin >> rules[i].mask;
        else
            cin.putback(t);
    }
    for (int i = 0; i < m; ++i) {
        unsigned int ip = getIp();
        cout << (solve(rules, ip) ? "YES" : "NO") << endl;
    }
    return 0;
}
