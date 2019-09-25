#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int a[maxn];
int n,m,ms;
bool isPrime(int x){
	if(x<2)return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}
int main(){
	fill(a,a+maxn,-1);
	scanf("%d %d %d",&ms,&n,&m);
	while(!isPrime(ms))ms++;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		int j=0;
		while(a[(x+j*j)%ms]!=-1&&j<ms) j++;
		if(a[(x+j*j)%ms]==-1&&j<ms) a[(x+j*j)%ms]=x;
		else printf("%d cannot be inserted.\n",x);
	}
	double ans = 0;
	for(int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		int j=0;
		while(a[(x+j*j)%ms]!=-1&&a[(x+j*j)%ms]!=x&&j<ms) j++;
		ans+=(j+1);
	}
	printf("%.1f",ceil(ans/m*10)/10);
	return 0;
} 
