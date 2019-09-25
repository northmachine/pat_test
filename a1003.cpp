#include <bits/stdc++.h>
#define maxn 510
#define INF 1000000000
using namespace std;
int G[maxn][maxn];
int weight[maxn];
int d[maxn];
int w[maxn];
int num[maxn];
bool vis[maxn];
int n,m,c1,c2;
void Dijkstra(int s){
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for(int  i=0;i<n;i++){
		int u = -1,min = INF;
		for(int j = 0;j<n;j++){
			if(vis[j]==false&&d[j]<min){
				u = j;
				min = d[u];
			}	
		}
		if(u==-1) return;
		vis[u] = true;
		for(int j = 0;j<n;j++){
			if(vis[j]==false&&G[u][j]!=INF&&d[u]+G[u][j]<d[j]){
				d[j] = d[u] + G[u][j];
				w[j] = w[u] + weight[j];
				num[j] = num[u];
			}
			else if(d[u]+G[u][j]==d[j]){
				if(w[u]+weight[j]>w[j])
					w[j] = w[u] + weight[j];
				num[j] = num[u] + num[j];
			}
		}
	}
}
int main(){
	scanf("%d %d %d %d",&n,&m,&c1,&c2);
	for(int i =0;i<n;i++) scanf("%d",&weight[i]);
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int  i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		scanf("%d",&G[a][b]);
		G[b][a] = G[a][b];
	}
	fill(w,w+maxn,0);
	fill(d,d+maxn,INF);
	Dijkstra(c1);
	printf("%d %d",num[c2],w[c2]);
	return 0;
}
