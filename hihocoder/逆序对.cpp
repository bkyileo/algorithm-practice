#include<cstdio>
#include<iostream>

using namespace std;

void merge(int a[], int n);
void msort(int a[], int temp[], int left, int right);
void sort(int a[], int temp[], int left, int center, int right);

long long sum = 0;
//归并排序中，交换的数字对数就是逆序数
int main(void) {
	int n = 0;
	int num[100010];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	merge(num, n);

	cout << sum<<endl;
	return 0;
}
void merge(int a[], int n) {

	int temp[100010];
	msort(a, temp, 0, n - 1);

}

void msort(int a[], int temp[], int left, int right) {
	int center;
	if (left < right) {
		center = (left + right) / 2;
		msort(a, temp, left, center);
		msort(a, temp, center + 1, right);
		sort(a, temp, left, center + 1, right);

	}
}
void sort(int a[], int temp[], int left, int right, int rightend) {
	int i, leftend, num, temppos;

	leftend = right - 1;
	temppos = left;
	num = rightend - left + 1;

	while (left<=leftend&&right<=rightend)
	{
		if (a[left] <= a[right]) {
			temp[temppos++] = a[left++];
		}
		else
		{
			temp[temppos++] = a[right++];
			sum += leftend - left + 1;
		}
	}
	while (left<=leftend)
	{
		temp[temppos++] = a[left++];
	}
	while (right <= rightend)
	{
		temp[temppos++] = a[right++];
	}

	for (i = 0; i < num; i++,rightend--) {
		a[rightend] = temp[rightend];
	}

}

