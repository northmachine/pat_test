#include <bits/stdc++.h>
using namespace std;
int m,n,s;
map<string,bool> mp;
int main(){
	scanf("%d %d %d",&m,&n,&s);
	string name;
	int nn=0;
	for(int i =1;i<=m;i++){
		cin>>name;
		if(i<s) continue;
		if(nn==0){
			if(!mp[name]){
				cout<<name<<endl;
				mp[name] = true;
			}
			else continue;
		}
		nn = (nn+1)%n;
	}
	if(m<s)printf("Keep going...");
	return 0;
} 
