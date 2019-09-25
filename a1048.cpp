#include <cstdio>
#include <algorithm>
int n,m;
bool a[1010];
int res[100010];
int num;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	scanf("%d %d",&n,&m);
	int x;
	for(int i =0;i<n;i++){
		scanf("%d",&x);
		if(a[m-x]){
			res[num++] = x<m-x?x:m-x;
		}
		a[x] = true;
	}
	std::sort(res,res+num,cmp);
	if(num==0) printf("No Solution");
	else {
		printf("%d %d",res[0],m-res[0]);
	}
	return 0;
} 
