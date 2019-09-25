#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n;
stack<int> topOrder;
struct node{
	int v,w;
};
int ve[maxn],vl[maxn],e[maxn],l[maxn];
int inDegree[maxn];
vector<node> G[maxn];
bool topologicalSort(){
	queue<int> q;
	for(int i=0;i<n;i++){
		if(inDegree[i] ==0) q.push(i);
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		topOrder.push(u);
		for(int i=0;i<G[u].size();i++){
			int v = G[u][i].v;
			inDegree[v]--;
			if(inDegree[v]==0) q.push(v);
			if(ve[u]+G[u][i].w>ve[v]) ve[v]=ve[u]+G[u][i].w;
		}
	}
	if(topOrder.size()==n) return true;
	else return false;
}
int CriticalPath(){
	memset(ve,0,sizeof)ve);
	if(!topologicalSort()) return -1;
	int maxLength = 0;
	for(int i =0;i<n;i++){
		if(ve[i]>maxLength) maxLength = ve[i];
	}
	fill(vl,vl+n,maxLength);
	while(!topOrder.empty()){
		int u = topOrder.top();
		topOrder.pop();
		for(int i =0;i<G[u].size();i++){
			int v = G[u][i].v;
			if(vl[v]-G[u][i].w<vl[u]){
				vl[u] = vl[v]-G[u][i].w;
			}
		}
	}
	for(int u=0;u<n;u++){
		for(int i =0;i<G[u].size();i++){
			int v = G[u][i].v,w = G[u][i].w;
			int e = ve[u],l = vl[v]-w;
			if(e==l){
				printf("%d->%d\n",u,v);
			}
		}
	}
	return maxLength;
}
