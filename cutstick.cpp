#include <cstdio>
#include <cstdlib>
int getCut(int *a,int n,int l){
	int cut = 0;
	for(int i =0;i<n;i++){
		cut+=a[i]/l;
	}
	return cut;
}
int main(){
	int n,c;
	scanf("%d%d",&n,&c);
	int *a = (int *)malloc(n*sizeof(int));
	for(int i =0;i<n;i++)
		scanf("%d",&a[i]);
	int left,right,mid;
	left=1;
	right=0;
	for(int i =0;i<n;i++) 
		if(a[i]>right)right = a[i];
	while(left<right){
		mid = (left+right)/2;
		if(getCut(a,n,mid)<c)
			right = mid;
		else
			left = mid+1;
	}
	printf("%d",mid-1);
	return 0;
} 
