#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct node{
	vector<int> childs;
	int layer=0;
}tree[maxn];
int n,res2;
double p,r,res;
void dfs(int root,int layer){
	tree[root].layer = layer;
	if(tree[root].childs.size()==0) {
		if(p*pow(1+r,layer)>res){
			res = p*pow(1+r,layer);
			res2=1;
		}
		else if(p*pow(1+r,layer)==res){
			res2++;
		}
	}
	else for(int i =0;i<tree[root].childs.size();i++){
		dfs(tree[root].childs[i],layer+1);
	}
}
int main(){
	scanf("%d %lf %lf",&n,&p,&r);
	r/=100;
	int root=0;
	for(int i =0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x==-1) root=i;
		else tree[x].childs.push_back(i);
	}
	dfs(root,0);
	printf("%.2f %d",res,res2);
	return 0;
}
