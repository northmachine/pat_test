//#define LOCAL
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct node{
	int add,data,next;
	bool f = false;
}link[maxn]; 
int n,start;
bool cmp(node a,node b){
	if(a.f!=b.f) return a.f>b.f;
	else return a.data<b.data;
}
int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	#endif
	scanf("%d %d",&n,&start);
	int cnt=0;
	for(int i=0;i<n;i++){
		int add,data,next;
		scanf("%d %d %d",&add,&data,&next);
		link[add].add = add;
		link[add].data = data;
		link[add].next = next;
	}
	int s = start;
	while(n!=0&&s!=-1){
		link[s].f = true;
		s = link[s].next;
		cnt++;
	}
	sort(link,link+maxn,cmp);
	printf("%d",cnt);
	if(n!=0)printf(" %05d\n",link[0].add);
	for(int i=0;i<cnt;i++){
		printf("%05d %d ",link[i].add,link[i].data);
		if(i!=cnt-1)printf("%05d\n",link[i+1].add);
		else printf("-1\n");
	}
	return 0;
}
