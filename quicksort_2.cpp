#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int a[maxn];
int n;
int partition(int a[],int l,int r){
	int tmp = a[l];
	while(l<r){
		while(l<r&&a[r]>tmp)r--;
		a[l] = a[r];
		while(l<r&&a[l]<=tmp)l++;
		a[r] = a[l];
	}
	a[l] = tmp;
	return l;
}
void quicksort(int a[],int l,int r){
	if(l<r){
		int p = partition(a,l,r);
		quicksort(a,l,p-1);
		quicksort(a,p+1,r);
	}
}
int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++)scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	for(int i =0;i<n;i++)printf("%d ",a[i]);
}
