#include <cstdio>
typedef long long ll;
ll n;
ll fac[30];
ll fn;
int main(){
	scanf("%d",&n);
	ll x = n;
	ll b=2,e=2,tb=2,te=2;
	for(ll i =2;i*i<=n;i++){
		tb = te = i;
		x=n;
		while(x%te==0){
			x/=te;
			te++;
		}
		if(te-tb>e-b){
			e =te;
			b = tb;
		}
	}
	if(e-b==0){
		printf("1\n%lld",n);
	}
	else{
		printf("%d\n",e-b);
		for(ll i =b;i<e;i++){
			printf("%d",i);
			if(i!=e-1) printf("*"); 
		}
	}
	return 0;
}
