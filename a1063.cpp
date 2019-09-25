#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n,k;
set<int> sts[maxn];
int main(){
	scanf("%d",&n);
	for(int i =1;i<=n;i++){
		int m;
		scanf("%d",&m);
		for(int j =0;j<m;j++){
			int x;
			scanf("%d",&x);
			sts[i].insert(x);
		}
	}
	scanf("%d",&k);
	for(int i =0;i<k;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		int same=0,total = sts[a].size();
		for(auto iter = sts[b].begin();iter!=sts[b].end();iter++){
			if(sts[a].find(*iter)!=sts[a].end()) same++;
			else total++;
		}
		float r = (float)same/(float)total*100;
		printf("%.1f%\n",r);
	}
	return 0;
}
