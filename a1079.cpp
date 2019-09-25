#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct node{
	vector<int> childs;
	int layer=0,amount=0;
}tree[maxn];
int n;
double p,r,res;
void dfs(int root,int layer){
	tree[root].layer = layer;
	if(tree[root].childs.size()==0) res+=tree[root].amount*p*pow(1+r,layer);
	else for(int i =0;i<tree[root].childs.size();i++){
		dfs(tree[root].childs[i],layer+1);
	}
}
int main(){
	scanf("%d %lf %lf",&n,&p,&r);
	r/=100;
	for(int i =0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x!=0)
			for(int j=0;j<x;j++){
				int t;
				scanf("%d",&t);
				tree[i].childs.push_back(t);
			}
		else{
			int t;
			scanf("%d",&t);
			tree[i].amount += t;
		}
	}
	dfs(0,0);
	printf("%.1f",res);
	return 0;
}
