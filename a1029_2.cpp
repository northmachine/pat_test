#include <iostream>
using namespace std;
int location(int *a, int *b, int n, int i, int j) {
	if (i >= 0 && i < n - 1) {
		if (a[i] <= b[j + 1] && b[j] <= a[i + 1])
			return i;
		else {
			if (n > 1) {
				if (a[i] > b[j + 1])
					return location(a, b, n / 2, i - n / 2, j + n / 2);
				else
					return location(a, b, n / 2, i + n / 2, j - n / 2);
			}
			else {
				if (a[i] > b[j + 1])
					return location(a, b, n / 2, i - 1, j + 1);
				else
					return location(a, b, n / 2, i + 1, j - 1);
			}
		}
	}
	else
		return i + 1;
}
double zhongweishu(int *a, int *b,int n,int m) {
	if (a[0] >= b[m - 1] || a[n - 1] <= b[0]) {
		int k = (n + m - 1) / 2-n;
		if ((n + m) % 2 == 0)
			return (b[k] + b[k + 1]) / 2.0;
		else
			return b[k];
	}
	else {
		if (n % 2 != 0 && m % 2 != 0) {
			int loc = location(a, b, n, n / 2 - 1, (m - 1) / 2);
			int i = loc;
			int j = (m - 1) / 2 - (i - (n / 2 - 1));
			if (j < m - 1 && i < n - 1)
				return (((a[i] >= b[j] )? a[i]:b[j]) + ((a[i + 1] <= b[j + 1] )? a[i + 1] :b[j + 1])) / 2.0;
			else if (i == n - 1)
				return ((a[i]>=b[j]?a[i]:b[j]) + b[j+1]) / 2.0;
			else
				return ((a[i+1]<=b[j+1]?a[i+1]:b[j+1]) + b[j]) / 2.0;
		}
		else {
			int loc = location(a, b, n, (n - 1) / 2, (m - 1) / 2);
			int i = loc;
			int j = (m - 1) / 2 - (i - (n - 1) / 2);
			if (n % 2 != 0 || m % 2 != 0) {
				if (n % 2 != 0)
					return a[i];
				else
					return b[j];
			}
			else
				if (j < m - 1 && i < n - 1)
					return ((a[i] >= b[j] ? a[i] : b[j]) + (a[i + 1] <= b[j + 1]) ? a[i + 1] : b[j + 1]) / 2.0;
				else if (j == m - 1)
					return (a[i + 1] + b[j]) / 2.0;
				else
					return (a[i] + b[j + 1]) / 2.0;
		}
	}
}
int main() {
	cout << "输入两个数组：" << endl;
	cout << "	第一个数组的个数：";
	int n, m;
	cin >> n;
	int *a = new int[n];
	cout << "	从小到大输入" << n << "个数：";
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "	第二个数组的个数：";
	cin >> m;
	int *b = new int[m];
	cout << "	从小到大输入" << m << "个数：";
	for (int i = 0; i < m; i++)
		cin >> b[i];
	cout << "这两个数组合并后的中位数是：" << zhongweishu(a, b, n, m) << endl;
	system("pause");
}
