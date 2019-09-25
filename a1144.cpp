#include <bits/stdc++.h>
using namespace std;
int n;
map<int,bool> table;
int main(){
	scanf("%d",&n);
	int x;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		table[x] = true;
	}
	int i=1;
	while(table[i]) i++;
	printf("%d",i);
	return 0;
} 
