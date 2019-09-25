#include <bits/stdc++.h>
using namespace std;
int k;
string str;
set<char> well;
vector<char> stuck;
bool vis[200];
int main(){
	cin>>k>>str;
	char pre = str[0];
	int pre_count = 1;
	for(int i =1;i<str.length();i++){
		if(str[i]==pre) pre_count++;
		else{
			if(pre_count%k!=0) well.insert(pre);
			pre = str[i];
			pre_count = 1;
		}
		if(i==str.length()-1){
			if(pre_count%k!=0) well.insert(pre);
		}
	}
	for(int i =0;i<str.length();i++){
		if(well.find(str[i])==well.end()&&!vis[str[i]]){
			stuck.push_back(str[i]);
			vis[str[i]] = true;
		}
	}
	for(int i=0;i<stuck.size();i++)printf("%c",stuck[i]);
	printf("\n");
	for(int i =0;i<str.length();i++){
		if(vis[str[i]])i+=k-1;
		printf("%c",str[i]);
	}
	return 0;
} 
