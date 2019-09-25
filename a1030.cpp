#include <bits/stdc++.h>
#define maxn 510
#define INF 1000000000
using namespace std;
int G[maxn][maxn];
int C[maxn][maxn];
int d[maxn];
bool vis[maxn];
vector<int> pre[maxn];
vector<int> path,tempPath;
int optValue = INF;
int n,m,S,D;
void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s] = 0;
	for(int i = 0;i<n;i++){
		int u = -1,min = INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false && d[j]<min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0;v<n;v++){
			if(vis[v]==false && G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v] = d[u] + G[u][v]; 
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
void DFS(int d){
	if(d == S){
		tempPath.push_back(d);
		int value = 0;
		for(int i = tempPath.size()-1;i>0;i--){
			int a = tempPath[i];
			int b = tempPath[i-1];
			value+=C[a][b];
		}
		if(value<optValue){
			path = tempPath;
			optValue = value;
		}
		tempPath.pop_back();
		return ;
	}
	tempPath.push_back(d);
	for(int i =0;i<pre[d].size();i++){
		DFS(pre[d][i]);
	}
	tempPath.pop_back();
}
int main(){
	scanf("%d %d %d %d",&n,&m,&S,&D);
	fill(G[0],G[0]+maxn*maxn,INF);
	fill(C[0],C[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		int a,b,l,c;
		scanf("%d %d %d %d",&a,&b,&l,&c);
		G[a][b] = G[b][a] = l;
		C[a][b] = C[b][a] = c;
	}
	Dijkstra(S);
	DFS(D);
	for(int i=path.size()-1;i>=0;i--){
		printf("%d ",path[i]);
	}
	printf("%d %d",d[D],optValue);
	return 0;
}
