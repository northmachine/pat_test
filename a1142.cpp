#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
set<int> adj[maxn];
bool tmp[maxn];
int n,m;
bool canJoin(int v){
	for(int i =1;i<=n;i++){
		if(tmp[i]&&adj[i].find(v)==adj[i].end()){
			return false;
		}
	}
	return true;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i =1;i<=n;i++)adj[i].insert(i);
	for(int i =0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].insert(b);
		adj[b].insert(a);
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int l;
		memset(tmp,false,sizeof(tmp));
		scanf("%d",&l);
		for(int j=0;j<l;j++){
			int x;
			scanf("%d",&x);
			tmp[x] = true;
		}
		int status=1;
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				if((tmp[u]&&!tmp[v]||tmp[v]&&!tmp[u])&&status==1){
					if(tmp[u]&&canJoin(v)) status=2;
					if(tmp[v]&&canJoin(u)) status=2;
				}
				if(tmp[u]&&tmp[v]&&adj[u].find(v)==adj[u].end()) status=3;
			}
		}
		if(status==1)printf("Yes\n");
		else if(status==2)printf("Not Maximal\n");
		else if(status==3)printf("Not a Clique\n");
	} 
	return 0;
}
