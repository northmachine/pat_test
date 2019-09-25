#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct node{
	vector<int> child;
}tree[maxn];
int n,m;
int genum[maxn];
void dfs(int root,int layer){
	genum[layer]++;
	for(int i =0;i<tree[root].child.size();i++){
		dfs(tree[root].child[i],layer+1);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i =0;i<m;i++){
		int x,cn;
		scanf("%d %d",&x,&cn);
		for(int j=0;j<cn;j++){
			int child;
			scanf("%d",&child);
			tree[x].child.push_back(child);
		}
	}
	dfs(1,1);
	int res=1;
	for(int i=0;i<n;i++){
		if(genum[i]>genum[res])res = i;
	}
	printf("%d %d",genum[res],res);
	return 0;
}
