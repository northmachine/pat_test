#include <bits/stdc++.h>
using namespace std;
const int maxn = 50010;
struct node{
	int id,cnt;
	bool operator < (const node &x)const{
		return cnt!=x.cnt?cnt>x.cnt:id<x.id;
	}
};
int counter[maxn];
set<node> s;
int n,k;
int main(){
	scanf("%d %d",&n,&k);
	for(int i =0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(i!=0){
			printf("%d:",x);
			int j=0;
			for(auto iter = s.begin();iter!=s.end()&&j<k;j++,iter++){
				printf(" %d",iter->id);
			}
			printf("\n");
		}
		auto iter = s.find(node{x,counter[x]});
		if(iter!=s.end())s.erase(iter);
		counter[x]++;
		s.insert({x,counter[x]});
	}
	return 0;
}
