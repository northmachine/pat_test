#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXV = 510;
const int INF = 0x3fffffff;
vector<Node> Adj[MAXV];
int n,d[MAXV],num[MAXV];
bool inq[MAXV];
struct Node{
	int v,dis;
	Node(int _v,int _dis): v(_v),dis(_dis){}
};
bool SPFA(int s){
	memset(inq,false,sizeof(inq));
	memset(num,0,sizeof(num));
	fill(d,d+MAXV,INF);
	queue<int> Q;
	Q.push(s);
	inq[s] = true;
	num[s]++;
	d[s]= 0;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		inq[u] = false;
		for(int j =0;j<Adj[u].size();j++){
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if(d[u]+dis<d[v]){
				d[v] = dis+ d[u];
				if(!inq[v]){
					Q.push(v);
					inq[v] = true;
					num[v]++;
					if(num[v]>=n) return false;
				}
			}
		}
	}
	return true;
} 
