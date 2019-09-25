#include <cstdio>
const ll maxn = 10010;
bool hash_table[maxn];
ll m,n;
bool isPrime(ll a){
	if(a==1) return false;
	for(ll i =2;i*i<=a;i++){
		if(a%i==0) return false;
	}
	return true;
}
ll main(){
	scanf("%d %d",&m,&n);
	while(!isPrime(m))++m;
	ll x;
	for(ll i =0;i<n;i++){
		scanf("%d",&x);
		for(ll j =0;j<m;j++){
			if(hash_table[(j*j+x)%m]==false){
				hash_table[(j*j+x)%m]=true;
				prllf("%d",(j*j+x)%m);
				break;
			}
			if(j == m-1) prllf("-");
		}
		if(i!=n-1) prllf(" ");
	}
	return 0;
}
