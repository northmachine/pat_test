#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int n,k,m;
int p[6];
struct node{
	int id,total=0,s[6] = {0},full;
	bool sub[6] = {false};
	bool pass = false;
}st[maxn];
bool cmp(node a,node b){
	if(a.pass!=b.pass) return a.pass>b.pass;
	else if(a.total!=b.total) return a.total>b.total;
	else if(a.full!=b.full) return a.full>b.full;
	else return a.id<b.id;
}
int main(){
	scanf("%d %d %d",&n,&k,&m);
	for(int i =1;i<=k;i++){
		scanf("%d",&p[i]);
	}
	int id,problem,score;
	for(int i =0;i<m;i++){
		scanf("%d %d %d",&id,&problem,&score);
		st[id].id = id;
		st[id].sub[problem] = true;
		if(score>=0){
			st[id].pass = true;
		}
		if(score==p[problem]&&p[problem]!=st[id].s[problem]) st[id].full++;
		if(score>st[id].s[problem]){
			st[id].total = st[id].total - st[id].s[problem] + score;
			st[id].s[problem] = score;
		}
	}
	sort(st,st+n+1,cmp);
	int j=1;
	for(int i =0;i<n&&st[i].pass;i++){
		printf("%d %05d %d ",j,st[i].id,st[i].total);
		for(int l=1;l<=k;l++){
			if(st[i].sub[l] == true) printf("%d",st[i].s[l]);
			else printf("-");
			if(l!=k) printf(" ");
		}
		if(i<n-1&&st[i+1].pass) printf("\n");
		if(st[i].total!=st[i+1].total) j=i+2;
	}
	return 0;
}
