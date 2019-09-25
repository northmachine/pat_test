#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
set<int> adj[maxn];
int n,m,k;
bool vis[maxn];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].insert(b);
		adj[b].insert(a);
	}
	scanf("%d",&k);
	for(int i =0;i<k;i++){
		memset(vis,false,sizeof(vis));
		int num;
		int pre;
		scanf("%d %d",&num,&pre);
		bool f = true;
		for(int j=1;j<num;j++){
			int x;
			scanf("%d",&x);
			if(!f) continue;
			if(adj[x].find(pre)==adj[x].end()) f = false;
			if(vis[x]==true)f = false;
			vis[x] = true;
			pre = x;
		}
		for(int j =1;j<=n;j++){
			if(vis[j]==false){
				f = false;
				break;
			}
		}
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
