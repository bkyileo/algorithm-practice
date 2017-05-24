#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 120;
ll arr[maxn];
ll cnt[maxn];
ll n;
ll gcd(ll a, ll b) {
    if (b == (ll)0)
        return a;
    else
        return gcd(b, a % b);
}
int main() {
    cin >> n;
    for (ll i = 1; i <= n; ++i)
        cin >> arr[i], cnt[i] = 1;
    ll num = 0; 
    ll cur = 1;
    ll i, j;
    for (i = 1; i <= n; ++i) {
        if (arr[i] == i) {
            cnt[i] = 1;
            continue;
        }
        cur = i;
        for (j = 1; j <= 101; ++j) {
            cur = arr[cur];
            if (cur == i) {
                cnt[i] = j;
                break;
            }
        }
    }
    ll res = cnt[1];
    ll tmp;
    for (ll i = 2; i <= n; ++i) {
        tmp = gcd(res, cnt[i]);
        res = (res / tmp)*cnt[i];
    }
    cout << res << endl;
}
