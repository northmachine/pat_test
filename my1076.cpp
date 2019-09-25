#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
struct node{
	int id;
	int layer;
}; 
vector<node> adj[maxn];
bool vis[maxn];
int BFS(int id,int layer){
	int numForward = 0;
	node user;
	queue<node> q;
	user.id = id;
	user.layer = 0;
	q.push(user);
	vis[id] = true;
	while(!q.empty()){
		node temp = q.front();
		q.pop();
		if(temp.layer<layer){
			for(int i =0;i<adj[temp.id].size();i++){
				if(vis[adj[temp.id][i].id]==false){
					node t=adj[temp.id][i];
					t.layer = temp.layer+1;
					q.push(t);
					vis[t.id] = true;
					numForward++;
				}
			}
		}
	}
	return numForward;
}
int main(){
	node user;
	int n ,l,numFollow,idFollow;
	scanf("%d%d",&n,&l);
	for(int  i=1;i<=n;i++){
		user.id = i;
		scanf("%d",&numFollow);
		for(int j =0;j<numFollow;j++){
			scanf("%d",&idFollow);
			adj[idFollow].push_back(user);
		}
	}
	int numQuery,s;
	scanf("%d",&numQuery);
	for(int i =0;i<numQuery;i++){
		memset(vis,false,sizeof(vis));
		scanf("%d",&s);
		int numForward = BFS(s,l);
		printf("%d\n",numForward);
	}
	return 0;
}
