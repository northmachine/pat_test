#include <cstdio>
int ary[201];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i =0;i<n;i++)
			scanf("%d",&ary[i]);
		int x;
		scanf("%d",&x);
		int j;
		for(j =0;j<n;j++)
			if(x==ary[j]){
				printf("%d\n",j);
				break;
			}
		if(j==n) printf("-1\n");
	}
	return 0;
}
