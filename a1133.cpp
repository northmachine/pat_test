#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct node{
	int add,data,next;
}link[maxn],tmp[maxn];
int n,k,start;
bool cmp(node a,node b){
	if(a.data>=0&&b.data<0||a.data<0&&b.data>=0) return a.data<0;
	else if(a.data>k&&b.data<=k||a.data<=k&&b.data>k) return a.data<=k;
	else return a.next<b.next; 
}
int main(){
	scanf("%d %d %d",&start,&n,&k);
	int add,data,next;
	for(int i =0;i<n;i++){
		scanf("%d %d %d",&add,&data,&next);
		tmp[add].add = add;
		tmp[add].data = data;
		tmp[add].next = next;
	}
	int num=0,s = start;
	while(s!=-1){
		link[num] = tmp[s];
		link[num].next = num;
		num++;
		s = tmp[s].next;
	}
	sort(link,link+num,cmp);
	for(int i =0;i<num;i++){
		printf("%05d %d ",link[i].add,link[i].data);
		if(i==num-1) printf("-1\n");
		else printf("%05d\n",link[i+1].add);
	}
	return 0;
}
