#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct node {
	vector<int> child;
}tree[maxn];
int lnum[maxn];
int n,m,layer;
void bfs(int root){
	queue<int> q;
	layer=0;
	q.push(root);
	int change = q.back();
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(tree[now].child.size()==0) lnum[layer]++;
		for(int i=0;i<tree[now].child.size();i++){
			q.push(tree[now].child[i]);
		}
		if(now==change){
			layer++;
			change = q.back();
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i =0;i<m;i++){
		int x,cn;
		scanf("%d %d",&x,&cn);
		for(int j=0;j<cn;j++){
			int c;
			scanf("%d",&c);
			tree[x].child.push_back(c);
		}
	}
	bfs(1);
//	printf("%d\n",layer);
	for(int i =0;i<layer;i++){
		printf("%d",lnum[i]);
		if(i!=layer-1) printf(" ");
	}
	return 0;
}
