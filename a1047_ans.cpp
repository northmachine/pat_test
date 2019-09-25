#include <bits/stdc++.h>
using namespace std;
const int maxn = 40010;
const int maxk = 2510;
char name[maxn][5];
vector<int> cour[maxk];
int n,k;
bool cmp(int a,int b){
	return strcmp(name[a],name[b])<0;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int  i=0;i<n;i++){
		scanf("%s",name[i]);
		int x;
		scanf("%d",&x);
		int course;
		for(int j=0;j<x;j++){
			scanf("%d",&course);
			cour[course].push_back(i);
		}
	}
	for(int i =1;i<=k;i++){
		sort(cour[i].begin(),cour[i].end(),cmp);
	}
	for(int i =1;i<=k;i++){
		printf("%d %d\n",i,cour[i].size());
		for(int j =0;j<cour[i].size();j++){
			printf("%s\n",name[cour[i][j]]);
		}
	}
	return 0;
}
