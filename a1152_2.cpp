#define LOCAL
#include <bits/stdc++.h>
using namespace std;
int n,k;
bool isPrime(int x){
	if(x<2)return false;
	for(int i =2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}
int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
//	freopen("output.tet","w",stdout);
	#endif
	scanf("%d %d",&n,&k);
	string str;
	cin>>str;
	for(int  i=0;i<=n-k;i++){
		string tmp = str.substr(i,k);
		int num = stoi(tmp);
		if(isPrime(num)){
			printf("%s",tmp.c_str());
			return 0;
		}
	}
	printf("404");
	return 0;
}
