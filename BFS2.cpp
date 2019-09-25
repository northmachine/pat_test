#include <cstdio>
#include <queue>
#define maxn 100
using namespace std;
struct node{
	int x,y,step;
}S,T,Node; 
int n,m;
char matrix[maxn][maxn];
bool inq[maxn][maxn];
int X[4]{0,1,0,-1};
int Y[4]{-1,0,1,0};
bool test(int x,int y){
	if(x<0||x>n-1||y<0||y>m-1) return false;
	if(inq[x][y]) return false;
	if(matrix[x][y]=='*') return false;
	return true;
}
int BFS(){
	queue<node> q;
	q.push(S);
	while(!q.empty()){
		node top = q.front();
		q.pop();
		if(top.x ==T.x && top.y == T.y) return top.step;
		for(int i =0;i<4;i++){
			Node.x=top.x+X[i];
			Node.y=top.y+Y[i];
			if(test(Node.x,Node.y)){
				Node.step = top.step+1;
				q.push(Node);
			}
		}
	}
	return -1;
} 
int main(){
	scanf("%d%d",&n,&m);
	for(int i =0;i<n;i++){
		for(int j = 0;j<m;j++){
			getchar();q
			scanf("%c",&matrix[i][j]);
			if(matrix[i][j]=='S'){
				S.x = i;S.y = j;
			}
			if(matrix[i][j]=='T'){
				T.x = i;T.y = j;
			}
		}
	}
	printf("%d",BFS());
}

