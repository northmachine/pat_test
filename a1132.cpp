#include <bits/stdc++.h>
using namespace std;
long long z;
int main(){
	long long a,b;
	long long n;
	scanf("%lld",&n);
	for(long long i=0;i<n;i++){
		string str;
		cin>>str;
		long long len  =str.length();
		string as,bs;
		long long j=0;
		for(;j<len/2;j++) as+= str[j];
		for(;j<len;j++) bs+= str[j];
		a = stoll(as);
		b = stoll(bs);
		z = stoll(str);
		if(a*b!=0&&z%(a*b)==0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
