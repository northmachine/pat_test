#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
	string str;
	cin>>str;
	int a = (str.size()+2)/3;
	int b =a;
	while(b+2*a<str.size()+2){
		b++;
	}
	for(int i=0;i<a-1;i++){
		printf("%c",str[i]);
		for(int j=0;j<b-2;j++) printf(" ");
		printf("%c\n",str[str.size()-1-i]);
	}
	for(int i =a-1;i<a+b-1;i++) printf("%c",str[i]);
	return 0;
}
