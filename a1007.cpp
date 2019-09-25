#include <cstdio>
#define maxn 20010
int a[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i =1;i<=n;i++)scanf("%d",&a[i]);
	for(int i = n+1;i<2*n+1;i++) a[i] = a[i-n];
	int ans=0,l=0,r=0,templ=0;
	for(int i =1;i<=n;i++){
		a[i]+=a[i-1];
		if(ans<a[i]-a[templ]){
			ans = a[i]-a[templ];
			r = i;
			l = templ;
		}
		if(a[i]<=a[templ])
			templ = i;
	}
	if(ans>0)printf("%d %d %d",ans,a[l+1+n],a[r+n]);
	else printf("0 %d %d",a[n+1],a[2*n]);
	return 0;
}
