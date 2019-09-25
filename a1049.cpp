#include <cstdio>
long long n;
int main(){
	scanf("%lld",&n);
	long long i=1;
	long long j=0;
	while(n/i!=0){
		i*=10;
		j++;
	}
	long long ans=0;
	i/=10;
	j--;
	while(i>0){
		if(n/i>1){
			ans+=(n/i)*i/10*j+i;
		}
		else if(n/i==1){
			ans+=(n%i+1)+i/10*j;
		}
		n%=i;
		i/=10;
		j--;
	}
	printf("%lld",ans);
	return 0;
}
