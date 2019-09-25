#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const int maxn = 1010;
int lG[maxn][maxn];
int tG[maxn][maxn];
int n,m;
int start,endd;
bool vis[maxn];
int dis[maxn];
int times[maxn];
vector<int> pre[maxn];
vector<int> pre2[maxn];
void dijkstra1(){
	fill(dis,dis+maxn,inf);
	memset(vis,false,sizeof(vis));
	dis[start] = 0;
	for(int i =0;i<n;i++){
		int u = -1,min = inf;
		for(int j=0;j<n;j++){
			if(dis[j]<min&&!vis[j]){
				u = j;
				min = dis[j];
			}
		}
		if(u==-1) return;
		vis[u] = true;
		for(int v = 0;v<n;v++){
			if(lG[u][v]!=inf&&!vis[v]){
				if(lG[u][v]+dis[u]<dis[v]){
					dis[v] = lG[u][v]+dis[u];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(lG[u][v]+dis[u]==dis[v]) pre[v].push_back(u);
			}
		}
	}
}
void dijkstra2(){
	fill(times,times+maxn,inf);
	memset(vis,false,sizeof(vis));
	times[start] = 0;
	for(int i =0;i<n;i++){
		int u = -1,min = inf;
		for(int j=0;j<n;j++){
			if(times[j]<min&&!vis[j]){
				u = j;
				min = times[j];
			}
		}
		if(u==-1) return;
		vis[u] = true;
		for(int v = 0;v<n;v++){
			if(tG[u][v]!=inf&&!vis[v]){
				if(tG[u][v]+times[u]<times[v]){
					times[v] = tG[u][v]+times[u];
					pre2[v].clear();
					pre2[v].push_back(u);
				}
				else if(tG[u][v]+times[u]==times[v]) pre2[v].push_back(u);
			}
		}
	}
}
vector<int> tmp;
int minres = inf;
vector<int> bestl,bestt;
void dfs1(int r){
	tmp.push_back(r);
	if(r==start){
		int res = 0;
		int s = tmp[tmp.size()-1];
		for(int i =tmp.size()-2;i>=0;i--){
			res+=tG[s][tmp[i]];
			s = i;
		}
		if(res<minres){
			minres = res;
			bestl = tmp;
		}
	}
	for(int i = 0;i<pre[r].size();i++){
		dfs1(pre[r][i]);
	}
	tmp.pop_back();
}
void dfs2(int r){
	tmp.push_back(r);
	if(r==start){
		int counter = tmp.size();
		if(counter<minres){
			minres = counter;
			bestt = tmp;
		}
	}
	for(int i = 0;i<pre2[r].size();i++){
		dfs2(pre2[r][i]);
	}
	tmp.pop_back();
}
int main(){
	fill(lG[0],lG[0]+maxn*maxn,inf);
	fill(tG[0],tG[0]+maxn*maxn,inf);
	scanf("%d %d",&n,&m);
	int v1,v2,o,l,t;
	for(int i =0;i<m;i++){
		scanf("%d %d %d %d %d",&v1,&v2,&o,&l,&t);
		lG[v1][v2] = l;
		tG[v1][v2] = t;
		if(!o){
			lG[v2][v1] = l;
			tG[v2][v1] = t;
		}
	}
	scanf("%d %d",&start,&endd);	
	dijkstra1();
	dfs1(endd);
	minres = inf;
	dijkstra2();
	dfs2(endd);
	if(bestl==bestt){
		printf("Distance = %d; Time = %d: %d",dis[endd],times[endd],bestl[bestl.size()-1]);;
		for(int i =bestl.size()-2;i>=0;i--){
			printf(" -> %d",bestl[i]);
		}
	}
	else {
		printf("Distance = %d: %d",dis[endd],bestl[bestl.size()-1]);;
		for(int i =bestl.size()-2;i>=0;i--){
			printf(" -> %d",bestl[i]);
		}
		printf("\nTime = %d: %d",times[endd],bestt[bestt.size()-1]);;
		for(int i =bestt.size()-2;i>=0;i--){
			printf(" -> %d",bestt[i]);
		}
	}
	return 0;
}
