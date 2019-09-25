#include <cstdio>
const int maxn = 100010;
int a[maxn];
int n;
int vis[maxn];
int main(){
	scanf("%d",&n);
	int count = 0;
	int no = 0;
	for(int i =0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]==i){
			vis[i] = true;
			no++;
		}
	}
	for(int i =0;i<n;i++){
		bool f=0;
		while(!vis[i]){
			if(!f){
				f = true;
				count++;
			}
			vis[i] = true;
			i = a[i];
		}
	}
	if(a[0]==0) printf("%d",n-no+count);
	else printf("%d",n-no+count-2);
	return 0;
}
