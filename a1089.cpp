#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;
int n;
int ori[maxn],mid[maxn],res[maxn];
bool isSame(){
	for(int i =0;i<n;i++){
		if(res[i]!=mid[i]) return false;
	}
	return true;
}
bool cmp(int a,int b){
	return a<b;
}
bool inseration(){
	bool f = false;
	for(int i =1;i<n;i++){
		if(i!=1&&isSame()){
			printf("Insertion Sort\n");
			f = true;
		}
		int j=i-1;
		for(;j>-1&&mid[i]<mid[j];j--);
		j++;
		int tmp = mid[i];
		for(int k=i;k>j;k--){
			mid[k] = mid[k-1];
		}
		mid[j] = tmp;
		if(f){
			printf("%d",mid[0]);
			for(int k =1;k<n;k++ )printf(" %d",mid[k]);
			break;
		}
	}
	return f;
}
bool merge(){
	bool f=false;
	for(int step =2;step/2<=n;step*=2){
		if(step!=2&&isSame()){
			printf("Merge Sort\n");
			f = true;
		}
		for(int i=0;i<n;i+=step){
			sort(mid+i,mid+min(i+step,n));
		}
		if(f){
			printf("%d",mid[0]);
			for(int k =1;k<n;k++ )printf(" %d",mid[k]);
			return f;
		}
	}
	return f;
}
int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d",&ori[i]);
		mid[i] = ori[i];
	}
	for(int i =0;i<n;i++){
		scanf("%d",&res[i]);
	}
	if(inseration());
	else{
		for(int i =0;i<n;i++)mid[i] = ori[i];
		merge();
	}
	return 0;
}
