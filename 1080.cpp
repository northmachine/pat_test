#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 40010;
const int maxm = 110;
const int maxk = 6;
int n,m,k;
struct school{
	set<int> acc;
	int r,quota;
}sc[maxm];
struct node{
	int id,g1,g2,choice[maxk],rank,total;
}st[maxn];
bool cmp(node a,node b){
	if(a.total!=b.total) return a.total>b.total;
	else return a.g1>b.g2;
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i =0;i<m;i++){
		scanf("%d",&sc[i].quota);
	}
	for(int i =0;i<n;i++){
		scanf("%d %d",&st[i].g1,&st[i].g2);
		st[i].total = st[i].g1+st[i].g2;
		st[i].id = i;
		for(int j =0;j<k;j++){
			scanf("%d",&st[i].choice[j]);
		}
	} 
	sort(st,st+n,cmp);
	int rr = 1;
	for(int i =0;i<n;i++){
		st[i].rank = rr;
		for(int j=0;j<k;j++){
			int s = st[i].choice[j];
			if(sc[s].acc.size()<sc[s].quota){
				sc[s].acc.insert(st[i].id);
				sc[s].r = st[i].rank;
				break;
			}
			else if(st[i].rank<=sc[s].r){
				sc[s].acc.insert(st[i].id);
				sc[s].r = st[i].rank;
				break;
			}
		}
		if(st[i].total==st[i+1].total&&st[i].g1==st[i+1].g1);
		else rr = i+2;
		printf("%d %d\n",st[i].id,st[i].rank);
	}
	for(int i =0;i<m;i++){
		if(sc[i].acc.size()>0){
			auto iter = sc[i].acc.begin();
			printf("%d",*iter);
			iter++;
			for(;iter!=sc[i].acc.end();iter++){
				printf(" %d",*iter);
			}
		}
		printf("\n");
	}
	return 0;
}
