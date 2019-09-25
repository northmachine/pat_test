#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 10010; 
int n;
vector<int> adj[maxn];
int vis[maxn];
int deepests[maxn];
int dnum=0;
int deep=0;
int deepest=0;
queue<int> q;
set<int> root;
void layer(int x){
	q.push(x);
	int now;
	int r=q.back();
//	printf("round:%d",x);
	while(!q.empty()){
		now = q.front();
		vis[now] = true;
		q.pop();
	//	printf("r:%d",r);
		for(int i =0;i<adj[now].size();i++){
			if(!vis[adj[now][i]])
				q.push(adj[now][i]);
		} 
		if(now==r){
			deep++;
			r = q.back();
		}
	}
	//printf("\n");
}
int main(){
	scanf("%d",&n);
	int t1,t2;
	for(int  i=1;i<n;i++){
		scanf("%d %d",&t1,&t2);
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}
	int p=0;
	for(int  i =1;i<=n;i++){
		if(!vis[i]){
			layer(i);
			p++;
		}
	}
	if(p==1){
		for(int i =1;i<=n;i++){
			fill(vis,vis+maxn,0);
			deep=0;
			layer(i);
			if(deep>deepest){
				dnum=0;
				root.clear();
				root.insert(i);
				deepests[dnum++] = i;
				deepest = deep;
			}
			if(deep==deepest){
				deepests[dnum++] = i;
				root.insert(i);
			}
		}
		sort(deepests,deepests+dnum);
		for(auto  i=root.begin();i!=root.end();i++){
			printf("%d\n",*i);
		}
	//	printf("deep:%d",deepest);
	}
	else printf("Error: %d components",p);
	return 0;
}
