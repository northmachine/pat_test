#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
struct node{
	int l,r;
	string data;
}tree[maxn];
int n;
bool vis[maxn];
int root=0;
void dfs(int r){
	if(r!=root&&(tree[r].l!=-1||tree[r].r!=-1)) printf("(");
	if(tree[r].l!=-1)dfs(tree[r].l);
	printf("%s",tree[r].data.c_str());
	if(tree[r].r!=-1)dfs(tree[r].r);
	if(r!=root&&(tree[r].l!=-1||tree[r].r!=-1))printf(")");
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>tree[i].data>>tree[i].l>>tree[i].r;
		vis[tree[i].l] = true;
		vis[tree[i].r] = true;
	}
	for(int i =1;i<=n;i++)
		if(vis[i] == false) {
			root = i;
			break;
		}
	dfs(root);
	return 0;
}
