#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
bool vis[maxn];
vector<int> adj[maxn];
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i =0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(i);
		adj[b].push_back(i);
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int l;
		memset(vis,false,sizeof(vis));
		scanf("%d",&l);
		for(int j=0;j<l;j++){
			int x;
			scanf("%d",&x);
			for(int u=0;u<adj[x].size();u++) vis[adj[x][u]] = true;
		}
		bool f=true;
		for(int j=0;j<m;j++) 
			if(vis[j]==false){
				f = false;
				break;
			}
		if(f) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
