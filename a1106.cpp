#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct node{
	vector<int> child;
}tree[maxn];
int n,res2 = maxn,res1;
double p,r;
void dfs(int root,int layer){
	if(tree[root].child.size()==0){
		if(layer<res2){
			res2 = layer;
			res1 = 1;
		}
		else if(res2==layer) res1++;
	}
	for(int i=0;i<tree[root].child.size();i++){
		dfs(tree[root].child[i],layer+1);
	}
}
int main(){
	scanf("%d %lf %lf",&n,&p,&r);
	r/=100;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			int c;
			scanf("%d",&c);
			tree[i].child.push_back(c);
		}
	}
	dfs(0,0);
	printf("%.4f %d",p*pow(r+1,res2),res1);
	return 0;
}
