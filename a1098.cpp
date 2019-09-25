#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int origin[maxn];
int origin2[maxn];
int half[maxn];
int n;
bool isSame(int a[],int b[],int k){
	for(int i=0;i<n;i++){
		if(a[i]!=b[i+k]) return false;
	}
	return true;
}
bool insertion(){
	bool f = false;
	for(int j=1;j<n;j++){
		int t = origin[j];
		int i=j;
		while(i>0&&t<origin[i-1])i--;
		for(int k=j;k>i;k--){
			origin[k] = origin[k-1];
		}
		origin[i] = t;
		if(f){
			printf("Insertion Sort\n");
			for(int k=0;k<n;k++){
				printf("%d",origin[k]);
				if(k!=n-1) printf(" ");
			}
			return f;
		}
		if(isSame(origin,half,0)) f = true;
	}
	return f;
}
void downAdjust(int low,int high){
	int i=low;
	int j=2*i;
	while(j<=high){
		if(j+1<=high&&origin2[j+1]>origin2[j]) j+=1;
		if(origin2[i]<origin2[j]){
			swap(origin2[i],origin2[j]);
			i=j;
			j = i*2;
		}
		else return;
	}
}
void heap(){
	printf("Heap Sort\n");
	for(int i =n/2;i>=1;i--)downAdjust(i,n);
	bool f = false;
	for(int i =n;i>1;i--){
		if(i!=n&&isSame(half,origin2,1)) f = true;
		swap(origin2[i],origin2[1]);
		downAdjust(1,i-1);
		if(f){
			for(int j=1;j<=n;j++){
				printf("%d",origin2[j]);
				if(j!=n) printf(" ");
			}
			return ;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		origin[i] = origin2[i+1] = x;
	}
	for(int i =0;i<n;i++){
		int x;
		scanf("%d",&x);
		half[i] = x;
	}
	if(insertion());
	else heap();
	return 0;
}
