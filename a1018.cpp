#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;
const int maxc = 110;
const int maxn = 510;
const int INF = 0x3fffffff;
struct node{
	int s,t;
	node(int _s,int _t):s(_s),t(_t){}
};
int bikes[maxn];
vector<node> adj[maxn];
bool vis[maxn];
int dis[maxn];
set<int> pre[maxn];
int c,n,s,m;
vector<int> best;
vector<int> temp_best;
int bring =INF;
int take = INF;
int go[maxn];
int acc;
void Dijkstra(){
	fill(dis,dis+maxn,INF);
	dis[0] = 0;
	for(int i =0;i<n;i++){
		int d = INF;
		int u = -1;
		for(int j =0;j<n;j++){
			if(vis[j]==false&&dis[j]<d){
				d = dis[j];
				u = j;
			}
		}
		if(u==-1) return;
		vis[u] = true;
		for(int j =0;j<adj[u].size();j++){
			if(vis[adj[u][j].s]==false){
				if(adj[u][j].t+dis[u]<dis[adj[u][j].s]){
					dis[adj[u][j].s]=adj[u][j].t+dis[u];
					pre[adj[u][j].s].clear();
					pre[adj[u][j].s].insert(u);
				}
				else if(adj[u][j].t+dis[u]==dis[adj[u][j].s]){
					pre[adj[u][j].s].insert(u);
				}
			}
		}
	}
}
void DFS(int s){
	temp_best.push_back(s);
	if(pre[s].size()!=0){
		for(auto iter = pre[s].begin();iter!=pre[s].end();iter++){
			DFS(*iter);
		}
	}
	else{
		int _bring=0;
		int _take=0;
		for(int  i=temp_best.size()-2;i>=0;i--){
			acc+=bikes[temp_best[i]];
			go[i] = c/2*(temp_best.size()-1-i)-acc;
		}
		for(int i =temp_best.size()-2;i>=0;i--){
			if(go[i]>_bring) _bring = go[i];
		}
		_take = _bring + acc-c/2*(temp_best.size()-1);
		_bring = _bring>0?_bring:0;
		_take = _take>0?_take:0;
		acc=0;
		if(bring>_bring){
			bring = _bring;
			take = _take;
			best = temp_best;
		}
		else if(bring==_bring&&take>_take){
			take = _take;
			best = temp_best;
		}
	}
	temp_best.pop_back();
}
int main(){
	scanf("%d %d %d %d",&c,&n,&s,&m);
	n++;
	for(int  i=1;i<n;i++){
		scanf("%d",&bikes[i]);
	}
	int s1,s2,t;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&s1,&s2,&t);
		adj[s1].push_back(node(s2,t));
		adj[s2].push_back(node(s1,t));
	}
	Dijkstra();
	DFS(s);
	printf("%d ",bring);
	for(int  i=best.size()-1;i>=0;i--){
		printf("%d",best[i]);
		if(i!=0 )printf("->");
	}
	printf(" %d",take);
	return 0;
}
