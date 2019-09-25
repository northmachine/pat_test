#include <cstdio>
int n,tmp;
int hash_table[10010];
int ary[100010];
int main(){
	scanf("%d",&n);
	for(int  i=0;i<n;i++){
		scanf("%d",&ary[i]);
		hash_table[ary[i]]++;
	}
	int i;
	for(i =0;i<n;i++){
		if(hash_table[ary[i]]==1){
			printf("%d",ary[i]);
			break;
		}
	}
	if(i==n) printf("None");
	return 0;
}
