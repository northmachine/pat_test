#include <cstdio>
const int maxn = 10010;
int a[maxn];
int dp[maxn];
int s[maxn];
int n;
int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d",&a[i]);
	}
	dp[0] = a[0];
	int ans = dp[0];
	s[0] = 0;
	for(int i =1;i<n;i++){
		if(dp[i-1]>0){
			dp[i] = dp[i-1] + a[i];
			s[i] = s[i-1];
		}
		else{
			dp[i] = a[i];
			s[i] = i;
		}
	}
	int i=0;
	for(int j=0;j<n;j++){
		if(dp[i]<dp[j]) i=j;
	}
	ans = dp[i];
	if(ans>=0) printf("%d %d %d",ans,a[s[i]],a[i]);
	else printf("0 %d %d",a[0],a[n-1]);
	return 0;
}
