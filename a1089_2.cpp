#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int origin[maxn];
int partial[maxn];
int n;
int tmp1[maxn];
int tmp2[maxn];
bool f1,f2;
bool compare(int a[],int b[]){
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]) return false;
	}
	return true;
}
bool compare2(int a[],int b[]){
	for(int i=0;i<n;i++){
		if(a[i+1]!=b[i]) return false;
	}
	return true;
}
void insertion(){
	for(int i=0;i<n;i++)tmp1[i] = origin[i];
	for(int i =1;i<n;i++){
		if(i!=1&&compare(tmp1,partial)){
			f1 = true;
		}
		int temp = tmp1[i];
		int j=i;
		while(j>0&&tmp1[j-1]>temp){
			tmp1[j] = tmp1[j-1];
			j--;
		}
		tmp1[j] = temp;
		if(f1) return ;
	}
}
void mergesort(){
	for(int i =0;i<n;i++)tmp2[i] = origin[i];
	for(int step = 2;step/2<n;step*=2){
		if(step!=2&&compare(tmp2,partial)){
			f2 = true;
		}
		for(int i=0;i<n;i+=step){
			sort(tmp2+i,tmp2+min(i+step,n));
		}
		if(f2 == true) return ;
	}
}
void merge(int A[],int L1,int R1,int L2,int R2){
	int i = L1,j = L2;
	int temp[maxn],index = 0;
	while(i<=R1&&j<=R2){
		if(A[i]<=A[j]) temp[index++] = A[i++];
		else temp[index++] = A[j++];
	}
	while(i<=R1)temp[index++] = A[i++];
	while(j<=R2)temp[index++] = A[j++];
	for(int i =0;i<index;i++){
		A[L1+i] = temp[i];
	}
}
void mergeSort(int A[]){
	for(int i =1;i<=n;i++)tmp2[i] = origin[i-1];
	for(int step = 2;step/2<n;step*=2){
		if(compare2(tmp2,partial)) f2 =true;
		for(int i=1;i<=n;i+=step){
			int mid = i+step/2-1;
			if(mid+1<=n){
				merge(A,i,mid,mid+1,min(i+step-1,n));
			}
		}
		if(f2) return ;
	}
}
int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++) scanf("%d",&origin[i]);
	for(int i =0;i<n;i++) scanf("%d",&partial[i]);
	insertion();
	if(f1){
		printf("Insertion Sort\n");
		for(int i=0;i<n;i++){
			printf("%d",tmp1[i]);
			if(i!=n-1)printf(" ");
		}
		return 0;
	}
	else{
		printf("Merge Sort\n");
		mergeSort(tmp2);
		for(int i=0;i<n;i++){
			printf("%d",tmp2[i+1]);
			if(i!=n-1)printf(" ");
		}
	}
	return 0;
}
