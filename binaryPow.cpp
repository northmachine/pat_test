#include <cstdio>
typedef long long LL;
LL binaryPow(LL a,LL b,LL m){
	LL ans = 1;
	while(b){
		if(b&1){
			ans = ans*a%m;
		}
		a=a*a%m;
		b>>=1;
	}
	return ans;
}
int main(){
	LL a,b,m;
	scanf("%lld%lld%lld",&a,&b,&m);
	printf("%lld",binaryPow(a,b,m));
	return 0;
}
