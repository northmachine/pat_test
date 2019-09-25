#define LOCAL
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int in[maxn],pre[maxn];
map<int,int> pos;
int n,m;
void lca(int ai,int bi,int inL,int inR,int preL,int preR){
	int k=pos[pre[preL]];
	int a = in[ai];
	int b = in[bi];
	if(k>ai&&k>bi) lca(ai,bi,inL,k-1,preL+1,preL+k);
	else if(k<ai&&k<bi) lca(ai,bi,k+1,inR,preL+k+1,preR);
	else if((k-ai)*(k-bi)<0) printf("LCA of %d and %d is %d.\n",a,b,pre[preL]);
	else if(k==ai) printf("%d is an ancestor of %d.\n",a,b);
	else if(k==bi) printf("%d is an ancestor of %d.\n",b,a);
}
int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
		pos[in[i]]=i;
	}
	for(int i=0;i<n;i++)scanf("%d",&pre[i]);
	for(int i =0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		int ai = -1,bi = -1;
		if(pos.find(a)!=pos.end()) ai = pos[a];
		if(pos.find(b)!=pos.end()) bi = pos[b];
		if(ai==-1&&bi==-1)printf("ERROR: %d and %d are not found.\n",a,b);
		else if(ai==-1) printf("ERROR: %d is not found.\n",a);
		else if(bi==-1) printf("ERROR: %d is not found.\n",b);
		else lca(ai,bi,0,n-1,0,n-1);
	}
	return 0;
}
