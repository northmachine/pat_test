#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int inf = 0x7fffffff;
struct node{
	int add,data,next = -2,order = inf;
	bool first;
}link[maxn];
int n,start;
bool cmp(node a,node b){
	return a.order<b.order;
}
bool cmp2(node a,node b){
	if(a.first!=b.first) return a.first>b.first;
	else return a.order<b.order;
}
bool dup[10010];
int main(){
	scanf("%d %d",&start,&n);
	for(int i =0;i<n;i++){
		int x;
		scanf("%d",&x);
		scanf("%d %d",&link[x].data,&link[x].next);
		link[x].add = x;
	}
	int t = start;
	int i;
	for(i =1;t!=-1&&t!=-2;i++){
		link[t].order = i;
		t = link[t].next; 
	}
	if(link[start].next == -2) i = 0;
	sort(link,link+maxn,cmp);
	int tmp = 0;
	for(int j =0;j<i-1;j++){
		if(!dup[abs(link[j].data)]){
			dup[abs(link[j].data)] = true;
			link[j].first = true;
			tmp++;
		//	printf("%d\n",abs(link[j].data));
		}
	}
	sort(link,link+i-1,cmp2);
	//printf("%d\n",tmp);
	for(int j=0;j<i-1;j++){
		if(j<tmp){
			if(j!=0){
				printf("%05d\n",link[j].add);
			}
			printf("%05d %d ",link[j].add,link[j].data);
		}
		else{
			if(j!=tmp){
				printf("%05d\n",link[j].add);
			}
			else printf("-1\n");
			printf("%05d %d ",link[j].add,link[j].data);
		}
	}
	if(i!=0)printf("-1\n");
	return 0;
} 
/*
00100 2
21314 2 44444
44444 55 12314
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854


*/
