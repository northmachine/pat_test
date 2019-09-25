#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const int maxn = 3000;
int G[maxn][maxn];
int dis[20][maxn];
bool vis[maxn];
int n,m,k,ds;
void dijkstra(int s){
	dis[s-n][s] = 0;
	for(int i=0;i<n+m;i++){
		int u=-1,min = inf;
		for(int j=1;j<=n+m;j++){
			if(!vis[j]&&dis[s-n][j]<min){
				u=j;
				min = dis[s-n][j];
			}
		}
		if(u==-1) return ;
		vis[u] = true;
		for(int v=1;v<=n+m;v++){
			if(!vis[v]&&G[u][v]!=inf&&G[u][v]+dis[s-n][u]<dis[s-n][v]){
				dis[s-n][v] = G[u][v] + dis[s-n][u];
			}
		}
	}
}
int main(){
	fill(G[0],G[0]+maxn*maxn,inf);
	fill(dis[0],dis[0]+20*maxn,inf);
	scanf("%d %d %d %d",&n,&m,&k,&ds);
	for(int i=0;i<k;i++){
		string a,b;
		int d;
		cin>>a>>b>>d;
		int ai,bi;
		if(a[0]=='G'){
			a.erase(a.begin());
			ai = stoi(a);
			ai+=n;
		}
		else ai = stoi(a);
		if(b[0]=='G'){
			b.erase(b.begin());
			bi = stoi(b);
			bi+=n;
		}
		else bi = stoi(b);
		G[ai][bi] = G[bi][ai] = d;
	}
	for(int i=1;i<=n+m;i++){
		G[i][i] = 0;
	}
	for(int i=1;i<=m;i++){
		memset(vis,false,sizeof(vis));
		dijkstra(i+n);
	}
	int maxd = 0,g=-1;
	for(int i=1;i<=m;i++){
		int mind=inf,maxdd=0;
		for(int j=1;j<=n;j++){
			if(dis[i][j]<mind) mind = dis[i][j];
			if(dis[i][j]>maxdd) maxdd = dis[i][j];
		}
		if(mind>maxd&&maxdd<=ds){
			maxd = mind;
			g = i;
		}
		else if(mind==maxd&&maxdd<=ds){
			int sum1=0,sum2=0;
			for(int l=1;l<=n;l++){
				sum1+=dis[g][l];
				sum2+=dis[i][l];
			}
			if(sum2<sum1) g = i;
		}
	}
	if(g==-1)printf("No Solution");
	else{
		printf("G%d\n",g);
		int sum=0;
		for(int i=1;i<=n;i++) sum+=dis[g][i];
		double avg = (double)sum/(double)n;
		avg = round(avg*10)/10;
		double d = maxd;
		printf("%.1f %.1f",d,avg);
	}
	return 0;
} 
