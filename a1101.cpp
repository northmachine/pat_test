#include <cstdio>
#include <algorithm>
using namespace std;
const int maxrn = 100010;
int n;
int a[maxrn],minl[maxrn],maxr[maxrn],res[maxrn];
int counta;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d",&a[i]);
	}
	maxr[0] = a[0];
	for(int i =1;i<n;i++){
		if(a[i]>maxr[i-1]) maxr[i] = a[i];
		else maxr[i] = maxr[i-1];
	}
	minl[n-1] = a[n-1];
	for(int i =n-2;i>=0;i--){
		if(a[i]<minl[i+1]) minl[i] = a[i];
		else minl[i] = minl[i+1];
	}
	for(int i =0;i<n;i++){
		if(i==0){
			if(a[i]<minl[i+1])
				res[counta++] = a[i];
		}	
		else if(i==n-1){
			if(a[i]>maxr[i-1])
				res[counta++] = a[i];
		}
		else{
			if(a[i]>maxr[i-1]&&a[i]<minl[i+1])
				res[counta++] = a[i];
		}
	}
	printf("%d\n",counta);
	if(counta!=0)
		printf("%d",res[0]);
	for(int i=1;i<counta;i++){
		printf(" %d",res[i]);
	}
	printf("\n");
	return 0;
}
