#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxv = 1010;
struct node{
	int id;
	int layer;
};
vector<node> adj[maxv];
bool inq[maxv] = {false};
int BFS(int s,int l){
	int numForward = 0;
	queue<node> q;
	node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	inq[start.id] = true;
	while(!q.empty()){
		node topNode = q.front();
		q.pop();
		int u = topNode.id;
		for(int i =0;i<adj[u].size();i++){
			node next = adj[u][i];
			next.layer = topNode.layer+1;
			if(inq[next.id]==false&&next.layer<=l){
				q.push(next);
				inq[next.id] = true;
				numForward++;
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
		memset(inq,false,sizeof(inq));
		scanf("%d",&s);
		int numForward = BFS(s,l);
		printf("%d\n",numForward);
	}
	return 0;
}
