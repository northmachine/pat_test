#include <cstdio>
#include <ctime>
const int maxn = 30;
int n,V,maxValue = 0;
int w[maxn],c[maxn];
void DFS(int index,int sumW,int sumC){
	if(index == n){
		if(sumC>maxValue)
			maxValue = sumC;
		return;
	}
	DFS(index+1,sumW,sumC);
	if(sumW+w[index]<=V)
		DFS(index+1,sumW+w[index],sumC+c[index]);
}
void DFS2(int index,int sumW,int sumC){
	if(index == n){
		if(sumC>maxValue)
			maxValue = sumC;
		return;
	}
	DFS(index+1,sumW,sumC);
	DFS(index+1,sumW+w[index],sumC+c[index]);
}
int main(){
	scanf("%d%d",&n,&V);
	for(int i =0;i<n;i++)
		scanf("%d",&w[i]);
	for(int i =0;i<n;i++)
		scanf("%d",&c[i]);
	clock_t start,end;
	start = clock();
	for(int i =0;i<10000;i++)
		DFS(0,0,0);
	end = clock();
	double time = (double)(end-start)/CLOCKS_PER_SEC;
	printf("result:%d time:%f\n",maxValue,time);
	maxValue = 0;
	start = clock();
	for(int i =0;i<10000;i++)
		DFS2(0,0,0);
	end = clock();
	time = (double)(end-start)/CLOCKS_PER_SEC;
	printf("result:%d time:%f",maxValue,time);
	return 0;
}
