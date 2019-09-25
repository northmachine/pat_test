#include <cstdio>
#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;
map<string,set<int>> table;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i =0;i<k;i++){
		int course,num;
		scanf("%d %d",&course,&num);
		string name;
		for(int j =0;j<num;j++){
			cin>>name;
			table[name].insert(course);
		}
	}
	for(int i =0;i<n;i++){
		string name;
		cin>>name;
		cout<<name;
		printf(" %d",table[name].size());
		for(auto iter = table[name].begin();iter!=table[name].end();iter++){
			printf(" %d",*iter);
		}
		printf("\n");
	}
	return 0;
} 
