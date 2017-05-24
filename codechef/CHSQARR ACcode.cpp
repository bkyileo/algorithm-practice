/******************************************
*    AUTHOR:         BHUVNESH JAIN        *
*    INSTITUITION:   BITS PILANI, PILANI  *
******************************************/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL; 
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
 
const int MAX   = 1000;
const int LIM   = 10;
const int INF   = 1000000001;
const LL  INFL  = 1000000000000000001LL;
const LL  MOD   = 1000000007LL;
const double EPS = 1e-10;
const double PI = acos(-1.0);
 
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define inchar          getchar_unlocked
#define outchar(x)      putchar_unlocked(x)
#define sz(a)           int((a).size())
#define pb              push_back
#define mp              make_pair
#define fi              first
#define sec             second
#define all(c)          (c).begin(),(c).end()
#define allr(c)         (c).rbegin(),(c).rend()
#define loop(c,i)       for(typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define loopr(c,i)      for(typeof(c.end()) i = c.end(); i != c.begin(); )
#define uni(a)          sort(all(a)), (a).erase(unique(all(a)),(a).end())
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())
 
double tick(){static clock_t oldt;clock_t newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt = newt;return diff;}
template<typename T> void inPos(T &x){x=0;register T c=inchar();while((c<48)||(c>57))c=inchar();for(;c<48||c>57;c=inchar());for(;c>47&&c<58;c=inchar())x=(x<<3)+(x<<1)+(c&15);}
template<typename T> void outPos(T n){char snum[65];int i=0;do {snum[i++]=n%10+'0';n/=10;}while(n);i=i-1;while(i>=0)outchar(snum[i--]);outchar('\n');}
template<typename T> T mod(T a, T b) {return (a<b ? a : a%b);}
 
int sum[MAX+1][MAX+1], rmq[LIM][LIM][MAX][MAX], lg[MAX], p2[LIM];
 
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
    #endif
    int n, m, q, a, b;
    int ans, temp, val, u, v, w, z, chk;
    inPos(n), inPos(m);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            inPos(u);
            rmq[0][0][i][j] = u;
        }
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            sum[i][j] = sum[i][j-1] + rmq[0][0][i-1][j-1];
        }
    }
    for(int j=1; j<=m; ++j) {
        for(int i=2; i<=n; ++i) {
            sum[i][j] += sum[i-1][j];
        }
    }
    for(int i=2; i<MAX; ++i) {
        lg[i] = lg[i/2] + 1;
    }
    for(int i=0; i<LIM; ++i) {
        p2[i] = 1<<i;
    }
    for(int k=0; k<n; ++k) {
        for(int j=1; j<=lg[m]; ++j) {
            int x2 = m-p2[j], y2 = p2[j-1];
            for(int l=0; l<=x2; ++l) {
                rmq[0][j][k][l] = max(rmq[0][j-1][k][l], rmq[0][j-1][k][l+y2]);
            }
        }
    }
    for(int i=1; i<=lg[n]; ++i) {
        int x1 = n-p2[i], y1 = p2[i-1];
        for(int k=0; k<=x1; ++k) {
            for(int l=0; l<m; ++l) {
                rmq[i][0][k][l] = max(rmq[i-1][0][k][l], rmq[i-1][0][k+y1][l]);
            }
        }
    }
    for(int i=1; i<=lg[n]; ++i) {
        int x1 = n-p2[i], y1 = p2[i-1];
        for(int k=0; k<=x1; ++k) {
            for(int j=1; j<=lg[m]; ++j) {
                int x2 = m-p2[j], y2 = p2[j-1];
                for(int l=0; l<=x2; ++l) {
                    rmq[i][j][k][l] = max(max(rmq[i-1][j-1][k][l], rmq[i-1][j-1][k][l+y2]), max(rmq[i-1][j-1][k+y1][l], rmq[i-1][j-1][k+y1][l+y2]));
                }
            }
       } 
    } 
    inPos(q);
    while (q--) {
        inPos(a), inPos(b);
        ans = INF;
        int up_x = n-a, up_y = m-b;
        int A = lg[a], B = lg[b], P2A = p2[lg[a]]-1, P2B = p2[lg[b]]-1;
        for(int i=0; i<=up_x; ++i) {
            for(int j=0; j<=up_y; ++j) {
                int L1 = i, L2 = i+a-1, R1 = j, R2 = j+b-1;
                temp = sum[L2+1][R2+1] + sum[L1][R1] - sum[L1][R2+1] - sum[L2+1][R1];
                u = max(rmq[A][B][L1][R1], rmq[A][B][L2-P2A][R1]);
                v = max(rmq[A][B][L1][R2-P2B], rmq[A][B][L2-P2A][R2-P2B]);
                val = max(u, v);
                ans = min(ans, a*b*val - temp);
            }
        }
        outPos(ans);
    }
    // cerr<<tick();
    return 0;
} 
