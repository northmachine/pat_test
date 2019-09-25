#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n,m,k;
bool G[maxn][maxn];
bool vis[maxn];
void dfs(int r){
	vis[r] = true;
	for(int i=1;i<=n;i++){
		if(G[r][i] == true&&vis[i] ==false) dfs(i);
	}
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		G[a][b] = G[b][a] = true;
	}
	for(int i =0;i<k;i++){
		memset(vis,false,sizeof(vis));
		int r;
		scanf("%d",&r);
		vis[r] = true;
		int count = 0;
		for(int j=1;j<=n;j++){
			if(vis[j]==false){
				dfs(j);
				count++;
			}
		}
		printf("%d\n",count-1);
	}
	return 0;
} 
