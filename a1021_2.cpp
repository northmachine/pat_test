#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
vector<int> G[maxn];
bool vis[maxn];
int n,deepest=0,tmpd=0;
set<int> root;
void dfs(int r,int l){
	vis[r] = true;
	if(l>tmpd) tmpd = l;
	for(int i =0;i<G[r].size();i++){
		if(!vis[G[r][i]]) dfs(G[r][i],l+1);
	}
}
void layer(int r){
	queue<int> q;
	q.push(r);
	vis[r] = true;
	int now;
	int l = q.back();
	tmpd = 0;
	while(!q.empty()){
		now = q.front();
		q.pop();
		for(int i=0;i<G[now].size();i++){
			if(!vis[G[now][i]]){
				q.push(G[now][i]);
				vis[G[now][i]] = true;
			}
		}
		if(now==l){
			tmpd++;
			l = q.back();
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i =0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int count=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,1);
			count++;
		}
	}
	if(count==1){
		for(int i =1;i<=n;i++){
			memset(vis,false,sizeof(vis));
			layer(i);
			if(tmpd>deepest) {
				root.clear();
				deepest = tmpd;
				root.insert(i);
			}
			else if(tmpd==deepest) root.insert(i);
		}
		for(auto iter = root.begin();iter!=root.end();iter++){
			printf("%d\n",*iter);
		}
	}
	else printf("Error: %d components",count);
	return 0;
}
