#include <bits/stdc++.h>
using namespace std;
const int N = 1111;
vector<int> G[N];
int father[N];
bool vis[N];
int findFather(int x){
	int a = x;
	while(father[a]!=a)a = father[a];
	while(x!=a){
		int t = x;
		x = father[x];
		father[t] = a;
	}
	return a;
}
void Union(int a,int b){
	int fa = findFather(a);
	int fb = findFather(b);
	father[fb] = fa;
}
void init(){
	for(int i =0;i<N;i++) father[i]=i;
	memset(vis,false,sizeof(vis));
}
int n,m,k;
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i =0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i =0;i<k;i++){
		init();
		int x;
		scanf("%d",&x);
		for(int j=1;j<=n;j++){
			for(int u=0;u<G[j].size();u++){
				if(j!=x&&G[j][u]!=x)Union(j,G[j][u]);
			}
		}
		int count=0;
		for(int j=1;j<=n;j++){
			if(j==x)continue;
			int f = findFather(j);
			if(vis[f]==false){
				vis[f] =true;
				count++;
			}
		}
		printf("%d\n",count-1);
	}
	return 0;
}
