#include <cstdio>
#include <cstdlib>
#include <ctime>
#include  <cmath>
#include <algorithm>
using namespace std;
int Partition(int A[],int left,int right){
	int temp = A[left];
	while(left<right){
		while(left<right&&A[right]>temp)right--;
		A[left]=A[right];
		while(left<right&&A[left]<=temp)left++;
		A[right]=A[left]; 
	}
	A[left]=temp;
	return left;
}
int randPartition(int A[],int left,int right){
	int p = round(1.0*rand()/RAND_MAX*(right-left)+left);
	swap(A[p],A[left]);
	int temp = A[left];
	while(left<right){
		while(left<right&&A[right]>temp)right--;
		A[left]=A[right];
		while(left<right&&A[left]<=temp)left++;
		A[right]=A[left]; 
	}
	A[left]=temp;
	return left;
}
void quickSort(int A[],int left,int right){
	if(left<right){
		int t = randPartition(A,left,right);
		quickSort(A,left,t-1);
		quickSort(A,t+1,right);
	}
}
int randSelect(int A[],int left,int right,int k){
	if(left==right) return A[left];
	int p = randPartition(A,left,right);
	int M = p-left+1;
	if(M==k) return A[p];
	if(M>k)
		return randSelect(A,left,p-1,k);
	else
		return randSelect(A,p+1,right,k-M);
}
int main(){
	srand((unsigned)time(NULL));
	int a[7]={12,33,57,66,18,27,64};
	printf("%d\n",randSelect(a,0,6,3));
	quickSort(a,0,6);
	for(int i =0;i<7;i++)printf("%d ",a[i]);
	return 0; 
}
