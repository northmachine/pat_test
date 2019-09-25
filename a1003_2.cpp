#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int inf = 0x7fffffff;
int n,m,c1,c2;
int G[maxn][maxn];
int teams[maxn];
int vis[maxn],dis[maxn];
vector<int> pre[maxn];
void dijkstra(int x){
	dis[x] = 0;
	for(int i =0;i<n;i++){
		int min=-1;
		int minf=inf;
		for(int j=0;j<n;j++){
			if(!vis[j]&&dis[j]<minf) {
				min = j;
		//		printf("%d\n",minf);
				minf = dis[j];
			//	printf("AA");
			}
		}
		if(min==-1) return ;
		vis[min] = true;
	//	printf("%d\n",minf);
		for(int j=0;j<n;j++){
			if(!vis[j]&&G[min][j]!=inf){
				if(G[min][j]+dis[min]<dis[j]){
					pre[j].clear();
					pre[j].push_back(min);
					dis[j] = dis[min]+G[min][j];
				}
				else if(G[min][j]+dis[min]==dis[j]) pre[j].push_back(min);
			}
		}
	}
}
int route=0;
int maxv=0;
void dfs(int x,int v){
	if(x!=c1){
		for(int i=0;i<pre[x].size();i++){
			dfs(pre[x][i],v+teams[x]);
		}
	}
	else{
		if(v>maxv){
			maxv = v;
		}
		route++;
	}
}
int main(){
	fill(G[0],G[0]+maxn*maxn,inf);
	scanf("%d %d %d %d",&n,&m,&c1,&c2);
	for(int i =0;i<n;i++) scanf("%d",&teams[i]);
	for(int i=0;i<m;i++){
		int a,b,l;
		scanf("%d %d %d",&a,&b,&l);
		G[a][b] = G[b][a] = l;
	}
	for(int i =0;i<n;i++) G[i][i] =0;
	fill(dis,dis+maxn,inf);
	dijkstra(c1);
	dfs(c2,0);
	printf("%d %d",route,maxv+teams[c1]);
	return 0;
}
