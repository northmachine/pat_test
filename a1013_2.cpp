#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxv = 1010;
const int INF = 0x3fffffff;
bool G[maxv][maxv];
bool G2[maxv][maxv];
bool vis[maxv];
int C[maxv];
int area = 0;
int N,M,K;
void DFS(int s){
	vis[s] = true;
	for(int i = 1;i<=N;i++){
		if(G[s][i]==true && vis[i] == false){
			DFS(i);
		}
	}
}
int main(){
	scanf("%d %d %d",&N,&M,&K);
	for(int i =0;i<M;i++){
		int c1,c2;
		scanf("%d %d",&c1,&c2);
		G[c1][c2] = true;
		G[c2][c1] = true;
	}
	for(int i=1;i<N+1;i++){
		G[i][i] = true;
	}
	for(int i=0;i<K;i++){
		int c;
		scanf("%d",&c);
		C[i] = c;
	}
	for(int  i=0;i<K;i++){
		/*
		for(int x=1;x<=N;x++){
			for(int y = 1;y<=N;y++){
				G2[x][y] = G[x][y];
				if(x==C[i]||y==C[i])
					G2[x][y] = false;
			}
		}
		for(int x=1;x<=N;x++){
			for(int y = 1;y<=N;y++){
				printf("%d ",G2[x][y]);
			}
			printf("\n");
		}
		*/
		vis[C[i]] =1;
		for(int x=1;x<=N;x++){
			if(vis[x]==false){
				area++;
				DFS(x);
			}
		}
		printf("%d",area-1);
		fill(vis,vis+maxv,0);
		area = 0;
		if(i!=K-1) printf("\n");
	}
	return 0;
}
