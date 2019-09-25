#include <cstdio>
#include <algorithm>
const int maxn = 100010;
int c,p;
int C[maxn],P[maxn];
int main(){
	scanf("%d",&c);
	for(int i =0;i<c;i++){
		scanf("%d",&C[i]);
	}
	scanf("%d",&p);
	for(int i =0;i<p;i++){
		scanf("%d",&P[i]);
	}
	std::sort(C,C+c);
	std::sort(P,P+p);
	int total=0;
	int k;
	for(k=0;k<c&&k<p&&C[k]<0&&P[k]<0;k++){
		total+=C[k]*P[k];
	}
	for(int i =c-1,j=p-1;i>=k&&j>=k&&C[i]>0&&P[j]>0;i--,j--){
		total+=C[i]*P[j];
	}
	printf("%d",total);
	return 0;
} 
