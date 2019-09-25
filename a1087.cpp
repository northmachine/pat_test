#include <bits/stdc++.h>
using namespace std;
const int maxn = 500;
const int inf = 0x7fffffff;
map<string,int> s_to_int;
map<int,string> int_to_s;
int G[maxn][maxn];
int happiness[maxn];
int dis[maxn];
bool vis[maxn];
int n,k,s;
vector<int> pre[maxn];
int getId(string a){
	if(s_to_int.find(a)==s_to_int.end()){
		int c = s_to_int.size();
		int_to_s[c] = a;
		s_to_int[a] = c;
	}
	return s_to_int[a];
}
void dijkstra(int s){
	dis[s] = 0;
	for(int  i=0;i<n;i++){
		int u=-1,min = inf;
		for(int j =0;j<n;j++){
			if(!vis[j]&&dis[j]<min){
				u  =j;
				min = dis[j];
			}
		}
		if(u==-1) return ;
		vis[u] = true;
		for(int v=0;v<n;v++){
			if(!vis[v]&&G[u][v]!=inf){
				if(G[u][v]+dis[u]<dis[v]){
					pre[v].clear();
					pre[v].push_back(u);
					dis[v] = G[u][v] + dis[u];
				}
				else if(G[u][v]+dis[u]==dis[v]) pre[v].push_back(u);
			}
		}
	}
}
vector<int> tmp;
vector<int> res;
int route=0;
int maxh=0;
int avgh=0;
void dfs(int r){
	tmp.push_back(r);
	if(r==s){
		route++;
		int happysum=0;
		for(int i=0;i<tmp.size();i++) happysum+=happiness[tmp[i]];
		if(happysum>maxh){
			maxh = happysum;
			avgh = happysum/(tmp.size()-1);
			res = tmp;
		}
		else if(happysum==maxh){
			int avg = happysum/(tmp.size()-1);
			if(avg>avgh){
				avgh = avg;
				res = tmp;
			}
		}
	}
	for(int i =0;i<pre[r].size();i++){
		dfs(pre[r][i]);
	}
	tmp.pop_back();
}
int main(){
	fill(G[0],G[0]+maxn*maxn,inf);
	fill(dis,dis+maxn,inf);
	scanf("%d %d",&n,&k);
	string start;
	cin>>start;
	s = getId(start);
	for(int i=0;i<n-1;i++){
		string tmp;
		cin>>tmp;
		scanf("%d",&happiness[getId(tmp)]);
	}
	for(int i=0;i<k;i++){
		string a,b;
		int cost;
		cin>>a>>b>>cost;
		int ai,bi;
		ai = getId(a);
		bi = getId(b);
		G[ai][bi] = G[bi][ai] = cost; 
	}
	for(int i=0;i<n;i++) G[i][i] = 0;
	dijkstra(s);
	dfs(s_to_int["ROM"]);
	printf("%d %d %d %d\n",route,dis[s_to_int["ROM"]],maxh,avgh);
	for(int i=res.size()-1;i>=0;i--){
		cout<<int_to_s[res[i]];
		if(i!=0) cout<<"->";
	}
	return 0;
}
