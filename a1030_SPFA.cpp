#include <bits/stdc++.h>
const int MAXV = 510;
const int INF = 0x3fffffff;
using namespace std;
struct node{
	int v,dis,cost;
	node(int _v,int _dis,int _cost): v(_v),dis(_dis),cost(_cost){}
};
vector<node> Adj[MAXV];
int N,M,S,D;
int d[MAXV],c[MAXV],num[MAXV];
bool inq[MAXV];
int pre[MAXV];
bool SPFA(int s){
	memset(inq,false,sizeof(inq));
	memset(num,0,sizeof(num));
	fill(d,d+MAXV,INF);
	fill(c,c+MAXV,INF);
	fill(pre,pre+MAXV,-1);
	queue<int> Q;
	Q.push(s);
	d[s] = 0;
	inq[s] = true;
	c[s] = 0;
	num[s]++;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		inq[u] = false;
		for(int i=0;i<Adj[u].size();i++){
			int v = Adj[u][i].v;
			int dis = Adj[u][i].dis;
			int cost = Adj[u][i].cost;
			if(d[u]+dis<d[v]){
				d[v] = d[u]+dis;
				c[v] = cost+c[u];
				pre[v] = u;
				if(!inq[v]){
					Q.push(v);
					inq[v] = true;
					num[v]++;
					if(num[v]>N-1) return false;
				}
			}
			if(d[u]+dis==d[v]){
				if(c[u]+cost<c[v]){
					c[v] = c[u]+cost;
					pre[v] = u;
					if(!inq[v]){
						Q.push(v);
						inq[v] = true;
						num[v]++;
						if(num[v]>N-1) return false;
					}
				}
			}
		}
	}
	return true;
}
int main(){
	scanf("%d %d %d %d",&N,&M,&S,&D);
	for(int  i=0;i<M;i++){
		int c1,c2,dis,cost;
		scanf("%d %d %d %d",&c1,&c2,&dis,&cost);
		Adj[c1].push_back(node(c2,dis,cost));
		Adj[c2].push_back(node(c1,dis,cost));
	}
	if(SPFA(S)){
		int d = D;
		stack<int> s;
		s.push(d);
		while(d!=-1){
			s.push(d);
			d = pre[d];
		}
		while(!s.empty()){
			int a = s.top();
			printf("%d ",a);
			s.pop();
		}
		printf("%d",c[D]);
	}
	return 0;
}
