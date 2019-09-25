#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n,m,k;
vector<int> adj[maxn];
struct node{
	int first;
	int second;
};
vector<node> tmp;
bool cmp(node a,node b){
	if(abs(a.first-10000)!=abs(b.first-10000))return abs(a.first-10000)<abs(b.first-10000);
	else return abs(a.second-10000)<abs(b.second-10000);
}
void find(int a,int b){
	tmp.clear();
	for(int i =0;i<adj[a].size();i++){
		if(adj[a][i]!=b&&(adj[a][i]-10000)*(a-10000)>0){
			int t = adj[a][i];
			for(int j=0;j<adj[t].size();j++){
				if((adj[t][j]-10000)*(b-10000)>0&&adj[t][j]!=b&&adj[t][j]!=a){
					int tt = adj[t][j];
					bool f = false;
					for(int ii=0;ii<adj[tt].size();ii++)
						if(adj[tt][ii]==b){
							f = true;
							break;
						}
					if(f) tmp.push_back({t,tt});
				}
			}
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i =0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a+10000].push_back(b+10000);
		adj[b+10000].push_back(a+10000);		
	}
	scanf("%d",&k);
	for(int  i=0;i<k;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		find(a+10000,b+10000);
		printf("%d\n",tmp.size());
		sort(tmp.begin(),tmp.end(),cmp);
		for(int j=0;j<tmp.size();j++){
			printf("%04d %04d\n",abs(tmp[j].first-10000),abs(tmp[j].second-10000));
		}
	}
	return 0;
}
