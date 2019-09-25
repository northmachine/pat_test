#include <bits/stdc++.h>
using namespace std;
map<char,bool> table;
map<string,int> counter;
void init(){
	for(char i = '0';i<='9';i++){
		table[i]=true;
	}
	for(char i ='a';i<='z';i++){
		table[i]  =true;
	}
	for(char i ='A';i<='Z';i++){
		table[i] = true;
	}
}
int main(){
	init();
	string str;
	getline(cin,str);
	for(int i =0;i<str.length();i++){
		if(str[i]>='A'&&str[i]<='Z'){
			str[i]+=32;
		}
	}
	//printf("%s\n",str.data());
	int i=0;
	while(!table[str[i]])++i;
	string s;
	string res;
	int max=0;
	for(int j=i;j<=str.length();j++){
		if(table[str[j]]){
			s+=str[j];
		}
		else if(s.length()>0){
			counter[s]++;
			if(counter[s]>max){
				res = s;
				max = counter[s];
			}
			else if(counter[s]==max){
				if(res.length()>s.length()){
					res = s;
				}
			}
			s = "";
		}
	}
	printf("%s %d",res.data(),counter[res]);
	return 0;
}
