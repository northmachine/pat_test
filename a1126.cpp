#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int n,m;
vector<int> adj[510];
bool vis[510];
void dfs(int r){
	vis[r] = true;
	for(int i=0;i<adj[r].size();i++){
		if(vis[adj[r][i]]==false) dfs(adj[r][i]);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i =0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		mp[a]++;
		mp[b]++;
	}
	int counter=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			counter++;
			dfs(i);
		}
	}
	int odd=0;
	for(int i=1;i<=n;i++){
		if(mp[i]%2!=0)odd++;
		printf("%d",mp[i]);
		if(i!=n) printf(" ");
		else printf("\n");
	}
	if(counter>1){
		printf("Non-Eulerian");
		return 0;
	}
	if(odd==0)printf("Eulerian");
	else if(odd==2)printf("Semi-Eulerian");
	else printf("Non-Eulerian");
	return 0;
}
