#include <bits/stdc++.h>
using namespace std;
int n,k;
map<int,set<string>>table;
int main(){
	char na[5]; 
	scanf("%d %d",&n,&k);
	for(int i =0;i<n;i++){
		scanf("%s",na);
		string name(na);
		int x;
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			int course;
			scanf("%d",&course);
			table[course].insert(name);
		}
	}
	for(int  i=0;i<k;i++){
		printf("%d %d\n",i+1,table[i+1].size());
		for(auto iter = table[i+1].begin();iter!=table[i+1].end();iter++){
			printf("%s\n",iter->data());
		}
	}
	return 0;
}
