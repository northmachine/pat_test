#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n;
int a[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	scanf("%d",&n);
	for(int i =1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	int i=0;
	for(;i<n;i++){
		if(a[i+1]<=i+1)break;
	}
	printf("%d",i);
	return 0;
}
