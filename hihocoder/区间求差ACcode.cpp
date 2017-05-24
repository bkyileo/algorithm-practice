#include <stdio.h>
#include <algorithm>
using namespace std;

struct interval {
	int b;
	int e;
};

int cmp(const interval &it1, const interval &it2) {
	return it1.b < it2.b;
}

void merge(interval *a, int n, long long *l, int *nn) {
	long long al = 0;
	int j = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i].b > a[j].e) {
			al += a[j].e - a[j].b;
			j += 1;
			a[j].b = a[i].b;
			a[j].e = a[i].e;
		} else if (a[i].e > a[j].e)
			a[j].e = a[i].e;
	}
	al += a[j].e - a[j].b;
	*l = al;
	*nn = j + 1;
}

long long intersect(interval *a, int an, interval *b, int bn) {
	int i = 0, j = 0;
	long long il = 0;
	while (i < an && j < bn) {
		if (a[i].e >= b[j].e) {
			if (a[i].b <= b[j].e)
				il += b[j].e - (a[i].b > b[j].b ? a[i].b : b[j].b);// b[j].e-max(b[j].b,a[i].b)
			j++;
		} else {
			if (b[j].b <= a[i].e)
				il += a[i].e - (a[i].b > b[j].b ? a[i].b : b[j].b);// a[i].e-max(a[i].b,b[j].b)
			i++;
		}
	}
	return il;
}

interval a[100000], b[100000];

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%d%d", &(a[i].b), &(a[i].e));
	for (int i = 0; i < M; ++i)
		scanf("%d%d", &(b[i].b), &(b[i].e));
	sort(a, a + N, cmp);
	sort(b, b + M, cmp);
	long long al, bl;
	int an, bn;
	merge(a, N, &al, &an);
	merge(b, M, &bl, &bn);
	printf("%lld\n", al - intersect(a, an, b, bn));
	return 0;
}
