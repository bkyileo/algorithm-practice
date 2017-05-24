//code chef Chef and cities
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define complex complexa
//需要问题在于第一位如何追踪
const double pi = acos(-1.0);
struct complex { 
    double x, y; 
    complex(): x(0), y(0) {} 
    complex(double _x, double _y): x(_x), y(_y) {} 

    friend complex operator +(const complex &a, const complex &b) { 
        return complex(a.x + b.x, a.y + b.y); 
    } 
    friend complex operator -(const complex &a, const complex &b) { 
        return complex(a.x - b.x, a.y - b.y); 
    } 
    friend complex operator *(const complex &a, const complex &b) { 
        return complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); 
    } 
    friend complex operator /(const complex &a, const double &b) { 
        return complex(a.x / b, a.y / b); 
    }
};
inline complex conj(const complex &a) { 
    return complex(a.x, -a.y); 
}
void fft(complex *a, int n, bool inv) {
    complex *w=new complex[n+1];
    int *rv=new int[n+1];
    int bits=-1;
    int _bit = 0; 
    for(int i = 0; i < 30; ++i) if (n & 1 << i) _bit = i; 
    if (_bit != bits) { 
        bits = _bit; 
        rv[0] = 0; 
        rv[1] = 1; 
        for(int st = 1; st < bits; ++st) { 
            int k = 1 << st; 
            for(int i = 0; i < k; ++i) { 
                rv[i+(1<<st)] = rv[i] << 1 | 1; 
                rv[i] <<= 1; 
            } 
        } 
        for(int i = 0; i < 1 << bits; ++i) 
            w[i] = complex(cos(2.0 * pi * i / n), sin(2.0 * pi * i / n)); 
    } 
    for(int i = 0; i < n; i++) 
        if (rv[i] <= i) swap(a[i], a[rv[i]]); 
    for(int d = n >> 1, st = 2; d > 0; d >>= 1, st <<= 1) { 
        int o = st >> 1; 
        for (int j = 0; j < o; ++j) { 
            complex wi = (inv ? conj(w[j*d]) : w[j*d]); 
            for (int i = j; i < n; i += st) { 
                int k = i + o; 
                complex u = a[i], v = a[k] * wi; 
                a[i] = u + v; 
                a[k] = u - v; 
            } 
        } 
    } 
    if (inv) for(int i = 0; i < n; ++i) a[i] = a[i] / n;

    delete[] w;
    delete[] rv;
}
string multiply(string num1, string num2) {

    int l1 = num1.size(), l2 = num2.size(); 
    int d = max(l1, l2) / 5 + 1; 
    int m = 1; 
    while (m < d) m <<= 1; 
    m <<= 1;

    complex *a=new complex[m+1];
    complex *b=new complex[m+1];

    memset(a, 0, (m + 1)*sizeof(complex)); 
    memset(b, 0, (m + 1)*sizeof(complex)); 
    int la = 0; 
    for (int i = l1 - 1; i >= 0; i -= 5) { 
        int tmp = 0; 
        for (int j = i - 4; j <= i; ++j) { 
            if (j < 0) continue; 
            tmp = tmp * 10 + num1[j] - '0'; 
        } 
        a[la++] = complex(tmp, 0); 
    } 

    int lb = 0; 
    for (int i = l2 - 1; i >= 0; i -= 5) { 
        int tmp = 0; 
        for (int j = i - 4; j <= i; ++j) {
            if (j < 0) continue; 
            tmp = tmp * 10 + num2[j] - '0'; 
        } 
        b[lb++] = complex(tmp, 0);
    } 

    int l = max(la, lb);
    int n = 1; 
    while (n < l) n <<= 1; 
    n <<= 1;

    long long *ans=new long long[n+10];

    fft(a, n, 0); 
    fft(b, n, 0); 
    for(int i = 0; i < n; i++) a[i] = a[i] * b[i]; 
    fft(a, n, 1); 

    ans[0] = 0; 
    for (int i = 0; i < n; ++i) { 
        ans[i+1] = 0; 
        ans[i] += (long long)(a[i].x + 0.5); 
        ans[i+1] += ans[i] / 100000; 
        ans[i] %= 100000; 
    } 
    while (ans[n]) {
        ans[n+1] = ans[n] / 100000; 
        ans[n] %= 100000; 
        ++n; 
    } 
    while (n > 1 && ans[n-1] == 0) --n; 


    stringstream s;
    for(int i = n - 1; i >= 0; --i){
        s << (int)ans[i];
        s << setw(5) << setfill('0');
    }

    delete[] a;
    delete[] b;
    delete[] ans;
    return s.str();
}
int main()
{
	int n;cin>>n;
	vector<int> citys(n);
	for(int i=0;i<n;++i)
	{
		cin>>citys[i];
	}
	int q;cin>>q;
	while(q--)
	{
		int order;cin>>order;
		if(order==1)
		{
			int a,b;cin>>a>>b;
			citys[a-1]=b;
		}
		if(order==2)
		{
			int r;cin>>r;
			long long res=1;
			int index=0;
			string first="1";
			while(1+index*r<=n)
			{
				res*=citys[1+index*r-1];
				first = multiply(first,to_string(citys[1+index*r-1]));
				//first*=citys[1+index*r-1];
				res=res%mod;
				index++;
			}
			cout<<first[0]<<" "<<res<<endl;
		}
	}
	return 0;
}
