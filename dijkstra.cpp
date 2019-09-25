#include <bits/stdc++.h>
using namespace std;
const int maxv = 510;
const int INF = 0x3fffffff;
int n,m,S,D;
int G[maxv][maxv];
bool vis[maxv];
int pre[maxv]; 
int d[maxv];
void Dijkstra(int s){
	d[s] = 0;
	for(int i=0;i<n;i++){
		int min = INF;
		int x = -1;
		for(int k=0;k<n;k++){
			if(d[k]<min)
				x=k;
		} 
		for(int j=0;j<n;j++){
			if(d[x]+G[x][j]<d[j]){
				d[j] = d[x]+G[x][j];
				pre[j] = x;
			}
		}
	}
}
int main(){
	fill(d,d+maxv,INF);
	fill(pre,pre+maxv,-1);
	fill(G[0],G[0]+maxv*maxv,INF);
	scanf("%d %d %d %d",&n,&m,&S,&D);
	int c1,c2,dd;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&c1,&c2,&dd);
		G[c1][c2] = dd;
		G[c2][c1] = dd;
	}
	for(int  i=0;i<n;i++){
		G[i][i]=0;
	}
	Dijkstra(S);
	int y = D;
	stack<int> s;
	while(y!=-1){
		s.push(y);
		y = pre[y];
	}
	while(!s.empty()){
		printf("%d ",s.top());
		s.pop();
	}
	printf("\n");
	printf("%d",d[D]);
	return 0;
}
