#include <cstdio>
#define maxn 100010
int prime[maxn],pnum=0;
bool p[maxn] = {0};
bool isPrime(int n){
	for(int i =2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
void findPrime(int n){
	for(int i=2;i<=n;i++)
		if(isPrime(i)) prime[pnum++]=i;
}
void findPrimeT(int n){
	for(int i =2;i<=maxn;i++){
		if(!p[i]){
			prime[pnum++]=i;
			for(int j=i;j<=maxn;j+=i)
				p[j]=true;
		}
	}
}
struct factor{
	int x,cut;
}fac[10];
int main(){
	int N;
	scanf("%d",&N);
	int t=N;
	findPrimeT(N);
	/*
	for(int i =M-1;i<N;i++){
		printf("%d",prime[i]);
		if((i-M+2)%10==0&&i!=N-1)
			printf("\n");
		else if(i!=N-1)printf(" ");
	}
	*/
	int n=0;
	for(int i =0;i<pnum;i++){
		if(N%prime[i]==0){
			fac[n].x=prime[i];
			while(N%prime[i]==0){
				N/=prime[i];
				fac[n].cut++;
			}
			++n;
		}
	}
	--n;
	if(N!=1){
		++n;
		fac[n].x=N;
		fac[n].cut++;
	}
	printf("%d=",t);
	if(t==1)printf("1");
	for(int i=0;i<n+1;i++){
		if(fac[i].cut==1){
			printf("%d",fac[i].x);
		}
		else{
			printf("%d^%d",fac[i].x,fac[i].cut);
		}
		if(i!=n)printf("*");
	}
	return 0;
}
