#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
const int inf = 0x7fffffff;
int lG[maxn][maxn];
int tG[maxn][maxn];
int dis[maxn];
int times[maxn];
bool vis[maxn];
int n,m;
int start,finish;
vector<int> pre1[maxn];
vector<int> pre2[maxn];
vector<int> tmp,bestl,bestt;
void dijkstral(int s){
	fill(dis,dis+maxn,inf);
	memset(vis,false,sizeof(vis));
	dis[s] = 0;
	for(int i =0;i<n;i++){
		int u = -1,min = inf;
		for(int j=0;j<n;j++){
			if(!vis[j]&&dis[j]<min){
				min = dis[j];
				u = j;
			}
		}
		if(u==-1) return;
		vis[u] = true;
		for(int v = 0;v<n;v++){
			if(!vis[v]&&lG[u][v]!=inf){
				if(lG[u][v]+dis[u]<dis[v]){
					pre1[v].clear();
					pre1[v].push_back(u);
					dis[v] = lG[u][v]+dis[u];
				}
				else if(lG[u][v]+dis[u]==dis[v]){
					pre1[v].push_back(u);
				}
			}
		} 
	} 
}
int mintime = inf;
void dfsl(int e){
	tmp.push_back(e);
	if(e==start){
		int ans = 0;
		int t = tmp[tmp.size()-1];
		for(int i =tmp.size()-2;i>=0;i--){
			ans+=tG[t][tmp[i]];
			t = tmp[i];
		}
		if(ans<mintime){
			mintime = ans;
			bestl = tmp;
		}
	}
	for(int i=0;i<pre1[e].size();i++){
		dfsl(pre1[e][i]);
	}
	tmp.pop_back();
}
void dijkstrat(int s){
	fill(times,times+maxn,inf);
	memset(vis,false,sizeof(vis));
	times[s] = 0;
	for(int i =0;i<n;i++){
		int u = -1,min = inf;
		for(int j=0;j<n;j++){
			if(!vis[j]&&times[j]<min){
				min = times[j];
				u = j;
			}
		}
		if(u==-1) return;
		vis[u] = true;
		for(int v = 0;v<n;v++){
			if(!vis[v]&&tG[u][v]!=inf){
				if(tG[u][v]+times[u]<times[v]){
					pre2[v].clear();
					pre2[v].push_back(u);
					times[v] = tG[u][v]+times[u];
				}
				else if(tG[u][v]+times[u]==times[v]){
					pre2[v].push_back(u);
				}
			}
		} 
	} 
}
int minstop = inf;
void dfst(int e){
	tmp.push_back(e);
	if(e==start){
		int ans = tmp.size();
		if(ans<minstop){
			minstop = ans;
			bestt = tmp;
		}
	}
	for(int i=0;i<pre2[e].size();i++){
		dfst(pre2[e][i]);
	}
	tmp.pop_back();
}
int main(){
	scanf("%d %d",&n,&m);
	int v1,v2,dir,l,t;
	fill(lG[0],lG[0]+maxn*maxn,inf);
	fill(tG[0],tG[0]+maxn*maxn,inf);
	for(int i =0;i<m;i++){
		scanf("%d %d %d %d %d",&v1,&v2,&dir,&l,&t);
		lG[v1][v2] = l;
		tG[v1][v2] = t;
		if(dir==0){
			lG[v2][v1] = l;
			tG[v2][v1] = t;
		}
	}
	scanf("%d %d",&start,&finish);
	dijkstral(start);
	dijkstrat(start);
	dfsl(finish);
	dfst(finish);
	if(bestl==bestt){
		printf("Distance = %d; Time = %d: %d",dis[finish],times[finish],bestl[bestl.size()-1]);
		for(int i = bestl.size()-2;i>=0;i--){
			printf(" -> %d",bestl[i]);
		}
	}
	else{
		printf("Distance = %d: %d",dis[finish],bestl[bestl.size()-1]);
		for(int i = bestl.size()-2;i>=0;i--){
			printf(" -> %d",bestl[i]);
		}
		printf("\n");
		printf("Time = %d: %d",times[finish],bestt[bestt.size()-1]);
		for(int i = bestt.size()-2;i>=0;i--){
			printf(" -> %d",bestt[i]);
		}
	}
	return 0;
}
