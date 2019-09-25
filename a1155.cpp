#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int tree[maxn];
int n;
vector<int> path;
int status=0;
void dfs(int r){
	path.push_back(tree[r]);
	if(2*r>n){
		for(int i=0;i<path.size()-1;i++){
			if(path[i]<path[i+1]&&status!=4){
				if(status==0)status=1;
				else if(status==2) status=4;
			}
			else if(path[i]>=path[i+1]&&status!=4){
				if(status==0) status=2;
				else if(status==1) status=4;
			}
		}
		for(int i =0;i<path.size();i++){
			printf("%d",path[i]);
			if(i!=path.size()-1)printf(" ");
			else printf("\n");
		}
	}
	if(2*r+1<=n) dfs(2*r+1);
	if(2*r<=n) dfs(2*r);
	path.pop_back();
}
int main(){
	scanf("%d",&n);
	for(int i =1;i<=n;i++){
		scanf("%d",&tree[i]);
	}
	dfs(1);
	if(status==1)printf("Min Heap");
	else if(status==2) printf("Max Heap");
	else printf("Not Heap");
	return 0;
}
