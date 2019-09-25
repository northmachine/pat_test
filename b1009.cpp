#include <cstdio>
#include <iostream>
using namespace std;
void reverse(char s[],int a,int b){
	char temp;
	while(a<b){
		temp = s[a];
		s[a++]=s[b];
		s[b--]=temp;
	}
}
int main(){
	char str[81];
	gets(str);
	int i=0;
	while(str[++i]!='\0');
	int a=0,b=0;
	while(b<=i){
		if(str[b]==' '||b==i){
			reverse(str,a,b-1);
			a=b=b+1;
		}
		++b;
	}
	reverse(str,0,i-1);
	printf("%s",str);
	return 0;
}
