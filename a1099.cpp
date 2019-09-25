#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct node{
	int lchild,rchild,data;
}tree[maxn];
int a[maxn];
int n,c=0;
void dfs(int root){
	if(tree[root].lchild!=-1)dfs(tree[root].lchild);
	tree[root].data = a[c++];
	if(tree[root].rchild!=-1)dfs(tree[root].rchild);
}
void level(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		printf("%d",tree[now].data);
		if(tree[now].lchild!=-1) q.push(tree[now].lchild);
		if(tree[now].rchild!=-1) q.push(tree[now].rchild);
		if(!q.empty()) printf(" ");
	}
}
int main(){
	scanf("%d",&n);
	for(int  i=0;i<n;i++){
		scanf("%d %d",&tree[i].lchild,&tree[i].rchild);
	}
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	dfs(0);
	level(0);
	return 0;
}
