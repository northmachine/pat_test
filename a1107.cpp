#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int course[maxn];
int father[maxn];
int root[maxn];
bool cmp(int a,int b){
	return a>b;
}
int findFather(int a){
	int fa=father[a];
	while(fa!=father[fa]) fa = father[fa];
	while(a!=father[a]){
		int t = a;
		a = father[a];
		father[t] = fa;
	}
	return fa;
}
void Union(int a,int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa!=fb){
		father[fa] = fb; 
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int  i=0;i<=n;i++) father[i]=i;
	for(int i =1;i<=n;i++){
		int x;
		scanf("%d:",&x);
		for(int j=0;j<x;j++){
			int h;
			scanf("%d",&h);
			if(course[h]==0)course[h] = i;
			Union(i,findFather(course[h]));
		}
	}
	int count = 0;
	for(int i=1;i<=n;i++){
		root[findFather(i)]++;
	}
	for(int i =1;i<=n;i++){
		if(root[i]!=0)count++;
	}
	sort(root,root+n+1,cmp);
	printf("%d\n",count);
	for(int i =0;i<count;i++){
		printf("%d",root[i]);
		if(i!=count-1)printf(" "); 
	}
	return 0;
} 
