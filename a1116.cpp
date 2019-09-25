#include <bits/stdc++.h>
using namespace std;
int n;
map<int,string> mp;
bool vis[10010];
bool isPrime(int x){
	if(x<2) return false;
	for(int i = 2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i =1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(i==1)mp[x] = "Mystery Award";
		else if(isPrime(i)) mp[x] = "Minion";
		else mp[x] = "Chocolate";
	}
	int k;
	scanf("%d",&k);
	for(int  i=0;i<k;i++){
		int x;
		scanf("%d",&x);
		printf("%04d: ",x);
		if(mp[x]!=""&&!vis[x])printf("%s\n",mp[x].c_str());
		else if(mp[x]!="")printf("Checked\n");
		else printf("Are you kidding?\n");
		vis[x] = true;
	}
	return 0;
} 
