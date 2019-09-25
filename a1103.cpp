#include <bits/stdc++.h>
using namespace std;
int n,k,p,sqn;
vector<int> tmp;
vector<int> res;
void dfs(int b,int sum,int layer){
	if(layer>k) return;
	else if(layer<k){
		for(int i = sqrt(n-sum);i>=b;i--){
			if(sum+pow(i,p)>=n);
			else{
				tmp.push_back(i);
				printf("%d ",i);
				dfs(i,sum+pow(i,k),layer+1);
				tmp.pop_back(); 
			}
			printf("aaa\n");
		}
	}
	else{
		for(int i =sqrt(n-sum);i>=b;i--){
			if(sum+pow(i,p)==n){
				printf("ccc\n");
				tmp.push_back(i);
				if(tmp>res) res = tmp;
				tmp.pop_back();
			}
			printf("%d\n",sum);
		}
	}
}
int main(){
	scanf("%d %d %d",&n,&k,&p);
	sqn = sqrt(n);
	dfs(1,0,1);
	for(int i =0;i<res.size();i++){
		printf("%d ",res[i]);
	}
	return 0;
}
