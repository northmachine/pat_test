#include <bits/stdc++.h>
using namespace std;
set<int> guests;
map<int,int> couples;
set<int> ans;
int n,m;
int main(){
	scanf("%d",&n);
	for(int  i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		couples[a+100000] = b+100000;
		couples[b+100000] = a+100000;
	}
	scanf("%d",&m);
	for(int i =0;i<m;i++){
		int x;
		scanf("%d",&x);
		guests.insert(x+100000);
	}
	for(auto iter = guests.begin();iter!=guests.end();iter++){
		if(guests.find(couples[*iter])==guests.end())ans.insert(*iter);
	}
	printf("%d\n",ans.size());
	int counter = 0;
	for(auto iter = ans.begin();iter!=ans.end();iter++){
		printf("%05d",*iter%100000);
		counter++;
		if(counter!=ans.size())printf(" ");
	}
	return 0;
}
