#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int tree[maxn];
int n,m,status;
void check(){
	status=0;
	for(int i =1;i<=n;i++){
		if(2*i<=n){
			if(status==0&&tree[i]>tree[2*i])status=1;
			else if(status==0&&tree[i]<tree[2*i])status=2;
			else if(status==1&&tree[i]<tree[2*i]){
				status=3;
				return ;
			}
			else if(status==2&&tree[i]>tree[2*i]){
				status=3;
				return ;
			}
		}
		if(2*i+1<=n){
			if(status==0&&tree[i]>tree[2*i+1])status=1;
			else if(status==0&&tree[i]<tree[2*i+1])status=2;
			else if(status==1&&tree[i]<tree[2*i+1]){
				status=3;
				return ;
			}
			else if(status==2&&tree[i]>tree[2*i+1]){
				status=3;
				return ;
			}
		}
	}
}
void postOrder(int r){
	if(r>n)return ;
	postOrder(2*r);
	postOrder(2*r+1);
	printf("%d",tree[r]);
	if(r!=1) printf(" ");
	else printf("\n");
}
int main(){
	scanf("%d %d",&m,&n);
	for(int i =0;i<m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&tree[j]);
		}
		check();
		if(status==1)printf("Max Heap\n");
		else if(status==2)printf("Min Heap\n");
		else if(status==3)printf("Not Heap\n");
		postOrder(1);
	}
	return 0;
}
