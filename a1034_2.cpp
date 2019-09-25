#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
map<string,int> name_to_id;
map<int,string> id_to_name;
int G[maxn][maxn];
int weight[maxn];
bool vis[maxn];
map<string,int> ans;
int n,k,idnum=0;
int getId(string a){
	if(name_to_id.find(a)==name_to_id.end()){
		id_to_name[idnum] = a;
		name_to_id[a] = idnum;
		++idnum;
	}
	return name_to_id[a];
}
void dfs(int r,int &num,int &kk,int &boss){
	num++;
	vis[r] = true;
	if(weight[r]>weight[boss])boss=r;
	for(int i =0;i<idnum;i++){
		if(G[r][i]>0){
			kk+=G[r][i];
			G[i][r]=0;
			if(!vis[i])dfs(i,num,kk,boss);
		}
	}
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		string a,b;
		int w,ia,ib;
		cin>>a>>b>>w;
		ia = getId(a);
		ib = getId(b);
		G[ia][ib]+=w;
		G[ib][ia]+=w;
		weight[ia]+=w;
		weight[ib]+=w;
	}
	for(int i=0;i<idnum;i++){
		int num=0,kk=0,boss=i;
		dfs(i,num,kk,boss);
		if(num>2&&kk>k){
			ans[id_to_name[boss]] = num;
		}
	}
	printf("%d\n",ans.size());
	for(auto iter = ans.begin();iter!=ans.end();iter++){
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	return 0;
}
