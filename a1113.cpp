#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int a[maxn];
int n;
int main(){
	scanf("%d",&n);
	int l = n/2;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	int i=0;
	int s1=0,s2=0;
	for(;i<l;i++)s1+=a[i];
	for(;i<n;i++)s2+=a[i];
	if(n%2==0)printf("0 ");
	else printf("1 ");
	printf("%d",s2-s1);
	return 0;
}
