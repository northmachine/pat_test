#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int origin[maxn];
int partial[maxn];
int tmp1[maxn];
int tmp2[maxn];
int n;
bool f1,f2;
bool compare(int a[],int b[]){
	for(int i =1;i<=n;i++)
		if(a[i]!=b[i])return false;
	return true; 
}
void downadjust(int root,int n){
	while(root<=n){
		int k=root;
		if(2*root<=n&&tmp2[k]<tmp2[2*root])k = root*2;
		if(2*root+1<=n&&tmp2[k]<tmp2[2*root+1])k = root*2+1;
		if(k == root) return ;
		swap(tmp2[root],tmp2[k]);
		root=k;
	}
}
void downAdjust(int low,int high){
	int i=low;
	int j=2*i;
	while(j<=high){
		if(j+1<=high&&tmp2[j+1]>tmp2[j]) j+=1;
		if(tmp2[i]<tmp2[j]){
			swap(tmp2[i],tmp2[j]);
			i=j;
			j = i*2;
		}
		else return;
	}
}
void heapsort(){
	for(int i =1;i<=n;i++) tmp2[i] = origin[i];
	for(int i =n/2;i>0;i--)downadjust(i,n);
	for(int i=n;i>1;i--){
		if(i!=n&&compare(tmp2,partial)) f2 = true;
		swap(tmp2[1],tmp2[i]);
		downadjust(1,i-1);
		if(f2) return;
	}
}
void insertion(){
	for(int i=1;i<=n;i++)tmp1[i] = origin[i];
	for(int i =1;i<=n;i++){
		if(i!=1&&compare(tmp1,partial)){
			f1 = true;
		}
		int temp = tmp1[i];
		int j=i;
		while(j>1&&tmp1[j-1]>temp){
			tmp1[j] = tmp1[j-1];
			j--;
		}
		tmp1[j] = temp;
		if(f1) return ;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&origin[i]);
	for(int i=1;i<=n;i++) scanf("%d",&partial[i]);
	insertion();
	if(f1){
		printf("Insertion Sort\n");
		for(int i=1;i<=n;i++){
			printf("%d",tmp1[i]);
			if(i!=n)printf(" ");
		}
		return 0;
	}
	else{
		printf("Heap Sort\n");
		heapsort();
		for(int i=1;i<=n;i++){
			printf("%d",tmp2[i]);
			if(i!=n)printf(" ");
		}
	}
	return 0;
}
