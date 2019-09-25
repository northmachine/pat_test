#include <cstdlib>
#include <algorithm>
using namespace std; 
const int maxn = 100;
int heap[maxn],n=10;// nŒ™ ‰»Î÷µ
void downAdjust(int low,int high){
	int i = low,j = 2*i;
	while(j<=high){
		if(j+1<=high&&heap[j+1]>heap[j]){
			j = j+1;
		}
		if(heap[j]>heap[i]){
			swap(heap[j],heap[i]);
			i = j;
			j = i*2;
		}
		else break;
	}
} 

void downAdjust2(int low,int high){
	int i =low,j = i*2;
	while(j<=high){
		if(j+1<=high&&heap[j+1]>heap[j]){
			j = j+1;
		}
		if(heap[j]>heap[i]){
			swap(heap[j],heap[i]);
			i = j;
			j = i*2;
		}
		else break;
	}
}

void createHeap(){
	for(int i=n/2;i>=1;i--)
		downAdjust(i,n);
}
void deleteTop(){
	heap[1] = heap[n--];
	downAdjust(1,n);
}
void upAdjust(int low,int high){
	int  i =high,j = high/2;
	while(j>=low){
		if(heap[i]>heap[j]){
			swap(heap[i],heap[j]);
			i = j;
			j = i/2;
		}
		else break;
	}
}
void insert(int x){
	heap[++n] = x;
	upAdjust(1,n);
}
void heapSort(){
	createHeap();
	int nn = n;
	while(nn>1){
		swap(heap[1],heap[nn--]);
		downAdjust(1,nn);
	}	
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&heap[i]);
	heapSort();
	for(int  i=1;i<=n;i++) printf("%d ",heap[i]);
	return 0;
}
