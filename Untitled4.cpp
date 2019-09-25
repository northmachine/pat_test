#include <bits/stdc++.h>
using namespace std; 
int main(){
	string a = "aaa";
	map<string,bool> table;
	table[a] = false;
	string b = "aaa";
	if(table.find(b)!=table.end()) printf("aaaa");
	return 0;
}
