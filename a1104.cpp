#include <cstdio>
int n;
int main(){
	scanf("%d",&n);
	double tmp,ans=0;
	for(int i =1;i<=n;i++){
		scanf("%lf",&tmp);
		ans+=(double)i*(n+1-i)*tmp;
	}
	printf("%.2lf\n",ans);
	return 0;
}
