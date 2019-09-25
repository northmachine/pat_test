#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
struct node{
	int data,next=-2;
}link[maxn];
int main(){
	int start,n,k;
	scanf("%d %d %d",&start,&n,&k);
	for(int i =0;i<n;i++){
		int add,data,next;
		scanf("%d %d %d",&add,&data,&next);
		link[add].data = data;
		link[add].next = next;
	} 
	n=0;
	int ts = start;
	while(ts!=-1){
		ts = link[ts].next;
		n++;
	}
	if(link[start].next ==-2) n=0;
	int t = start;
	for(int i =0;i<n/k;i++){
		int temp = t;
		int pre;
		int now = t;
		int next;
		for(int j=0;j<k;j++){
			next = link[now].next;
			link[now].next = pre;
			pre = now;
			now = next;
			if(i==0&&j==k-1)start = pre;
		}
		int j;
		for(j=1;j<k&&next!=-1;j++)next = link[next].next;
		if(next!=-1)link[temp].next = next;
		else link[temp].next = now;
		t=now;
	}
	while(start!=-1&&n--){
		printf("%05d %d ",start,link[start].data);
		if(link[start].next!=-1)printf("%05d\n",link[start].next);
		else printf("-1\n");
		start = link[start].next;
	}
	return 0;
}
