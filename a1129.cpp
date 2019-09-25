#include <bits/stdc++.h>
using namespace std;
const int maxn = 50010;
int a[maxn];
int n,k;
struct node{
	int item;
}b[maxn];
bool cmp(node x,node y){
	return a[x.item]!=a[y.item]?a[x.item]>a[y.item]:x.item<y.item;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i =1;i<=n;i++)b[i].item = i;
	for(int i =0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(i!=0){
			printf("%d:",x);
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=k&&a[b[i].item]>0;i++){
				printf(" %d",b[i].item);
			}
			printf("\n");
		}
		a[x]++;		
	}
	return 0;
}
