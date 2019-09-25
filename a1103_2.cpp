#include <bits/stdc++.h>
using namespace std;
vector<int> fac;
int init(int n,int p){
	int i=0;
	while(pow(i,p)<=n) fac.push_back(pow(i++,p));
} 
int n,k,p;
vector<int> tmp;
vector<int> res;
int maxfsum;
void dfs(int f,int layer,int sum,int fsum){
	if(layer>k) return ;
	else if(layer<k){
		if(sum<n){
			tmp.push_back(f);
			dfs(f,layer+1,sum+fac[f],fsum+f);
			tmp.pop_back();
			if(f>1)dfs(f-1,layer,sum,fsum);
		}
	}
	else{
		if(sum==n){
			if(fsum>maxfsum){
				maxfsum = fsum;
				res = tmp;
			}
			else if(fsum==maxfsum){
				if(tmp>res) res = tmp;
			}
		}
	}
}
int main(){
	scanf("%d %d %d",&n,&k,&p);
	init(n,p);
	dfs(fac.size()-1,0,0,0);
	if(res.size()!=0){
		printf("%d = ",n);
		for(int i =0;i<res.size();i++){
			printf("%d^%d",res[i],p);
			if(i!=res.size()-1) printf(" + ");
		}
	}
	else printf("Impossible");
	return 0;
}
