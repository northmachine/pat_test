#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 0x3fffffff;
int N,M,c1,c2;
struct node{
	int v,dis;
	node(int _v,int _dis):v(_v),dis(_dis){}
};
vector<node> G[maxn];
int weight[maxn];
int d[maxn],w[maxn],num[maxn];
set<int> pre[maxn];
bool bellman(int s){
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for(int i =0;i<N-1;i++){
		for(int j =0;j<N;j++){
			for(int k =0;k<G[j].size();k++){
				int v = G[j][k].v;
				int dis = G[j][k].dis;
				if(d[j]+dis<d[v]){
					d[v] = dis+d[j];
					w[v] = w[j]+weight[v];
					num[v] = num[j];
					pre[v].clear();
					pre[v].insert(j);
				}
				else if(d[j]+dis==d[v]){
					if(w[v]<w[j]+weight[v])
						w[v] = w[j] + weight[v];
					pre[v].insert(j);
					num[v] = 0;
					for(auto it=pre[v].begin();it!=pre[v].end();it++){
						num[v]+=num[*it];
					}
				}
			}
		}
	}
}
int main(){
	scanf("%d %d %d %d",&N,&M,&c1,&c2);
	for(int i =0;i<N;i++) scanf("%d",&weight[i]);
	for(int  i=0;i<M;i++){
		int a,b,dis;
		scanf("%d %d %d",&a,&b,&dis);
		G[a].push_back(node(b,dis));
		G[b].push_back(node(a,dis));
	}
	fill(w,w+maxn,0);
	fill(d,d+maxn,INF);
	bellman(c1);
	printf("%d %d",num[c2],w[c2]);
	return 0;
}
