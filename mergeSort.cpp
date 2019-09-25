#include <cstdio>
#define maxn 100
#define min(x,y) (((x)<(y))?(x):(y))
void merge(int A[],int L1,int R1,int L2,int R2){
	int temp[maxn];
	int index=0;
	int p1=L1,p2=L2;
	while(p1<=R1&&p2<=R2){
		if(A[p1]<=A[p2])
			temp[index++]=A[p1++];
		else
			temp[index++]=A[p2++];
	}
	while(p1<=R1)
		temp[index++]=A[p1++];
	while(p2<=R2)
		temp[index++]=A[p2++];
	for(int i =0;i<index;i++)
		A[L1+i]=temp[i];
}
void mergeSort(int A[],int n){
	int mid;
	for(int step = 2;step/2<n;step*=2){
		for(int i = 0;i<n;i+=step){
			mid = i+ step/2 -1;
			if(mid+1<n)
				merge(A,i,mid,mid+1,min((i+step-1),(n-1)));
		}
	}
}
int main(){
	int a[7]={12,33,57,66,18,27,64};
	mergeSort(a,7);
	for(int i =0;i<7;i++) printf("%d ",a[i]);
	return 0;
}
