#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int in[maxn],pre[maxn];
map<int,int> pos;
int n,m;
void solve(int ai,int bi,int inL,int inR,int preL,int preR){
//	if(inL>inR)return ;
	int root=pos[pre[preL]];
	if(ai<root&&bi<root) solve(ai,bi,inL,root-1,preL+1,preL+root-inL);
	else if(ai>root&&bi>root) solve(ai,bi,root+1,inR,preL+root-inL+1,preR);
	else if(ai<root&&bi>root||ai>root&&bi<root) {
		printf("LCA of %d and %d is %d.\n",in[ai],in[bi],pre[preL]);
		return ;
	}
	else if(ai==root){
		printf("%d is an ancestor of %d.\n",in[ai],in[bi]);
		return ;
	}
	else if(bi==root){
		printf("%d is an ancestor of %d.\n",in[bi],in[ai]);
		return ;
	}
}
int main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
		pos[in[i]] = i;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		int ai=-1,bi=-1;
		if(pos.find(a)!=pos.end())ai = pos[a];
		if(pos.find(b)!=pos.end())bi = pos[b];
		if(ai==-1&&bi==-1){
			printf("ERROR: %d and %d are not found.\n",a,b);
		}
		else if(ai==-1){
			printf("ERROR: %d is not found.\n",a);
		}
		else if(bi==-1){
			printf("ERROR: %d is not found.\n",b);
		}
		else solve(ai,bi,0,n-1,0,n-1);
	}
	return 0;
}
/*
6 8
7 2 3 4 6 5 1 8
5 3 7 2 6 4 8 1
2 6
8 8
7 9
12 -3
0 8
99 99

*/
