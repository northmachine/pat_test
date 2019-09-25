#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int a [maxn];
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	double ans = a[0];
	for(int i =1;i<n;i++){
		ans = (ans+(double)a[i])/2.0;
	}
	printf("%d",(int)ans);
	return 0;
}
