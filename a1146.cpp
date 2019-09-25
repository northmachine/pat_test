#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
set<int> adj[maxn];
int fa[maxn];
int tmp[maxn];
int n,m,k;
vector<int> ans;
bool check(){
	int x;
	bool f = true;
	for(int i =1;i<=n;i++)tmp[i] = fa[i];
	for(int  i=0;i<n;i++){
		scanf("%d",&x);
		if(!f) continue; 
		if(tmp[x]!=0)f = false;
		else{
			for(auto iter = adj[x].begin();iter!=adj[x].end();iter++){
				tmp[*iter]--;
			}
		}
	}
	return f;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i =0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].insert(b);
		fa[b]++;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		if(!check()) ans.push_back(i);
	}
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i]);
		if(i!=ans.size()-1)printf(" ");
	}
	return 0;
}
