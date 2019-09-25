#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int n,l,k;
vector<int> G[maxn];
bool vis[maxn];
int bfs(int x){
	queue<int> q;
	q.push(x);
	vis[x] = true;
	int c = q.back();
	int now,count1=0;
	int layer=0;
	while(!q.empty()){
		now = q.front();
		q.pop();
		for(int i =0;i<G[now].size();i++){
			if(!vis[G[now][i]]){
				q.push(G[now][i]);
				vis[G[now][i]] = true;
				count1++;
			//	printf("%d\n",count1);
			}
		}
		if(now==c){
			layer++;
			c = q.back();
			if(layer>=l) break;
		}
	}
	return count1;
}
int main(){
	scanf("%d %d",&n,&l);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			int v;
			scanf("%d",&v);
			G[v].push_back(i);
		} 
	}
	scanf("%d",&k);
	for(int i =0;i<k;i++){
		int x;
		scanf("%d",&x);
		memset(vis,false,sizeof(vis));
		int c = bfs(x);
		printf("%d\n",c);
	}
	return 0;
} 
