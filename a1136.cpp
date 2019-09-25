#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n;
int a[maxn],tmp[maxn];
bool isPalindromic(){
	for(int i =0;i<n/2;i++){
		if(a[i]!=a[n-1-i])return false;
	}
	return true;
}
void add(){
	int c=0,t;
	for(int i =0;i<n;i++){
		t = a[i];
		a[i] = (a[i]+tmp[i]+c)%10;
		c = (t+tmp[i]+c)/10;
	}
	if(c!=0)a[n++] = c;
}
int main(){
	char str[1010];
	scanf("%s",str);
	n = strlen(str);
//	printf("%d",n);
	for(int i=0;i<n;i++){
		a[i] = str[n-1-i]-'0';
	}
	int counter = 0;
	while((!isPalindromic())&&counter<10){
		for(int i=0;i<n;i++) tmp[n-1-i] = a[i];
		for(int i =0;i<n;i++){
			printf("%d",a[n-1-i]);
		}
		printf(" + ");
		for(int i =0;i<n;i++){
			printf("%d",tmp[n-1-i]);
		}
		counter++;
		add();
		printf(" = ");
		for(int i =0;i<n;i++){
			printf("%d",a[n-1-i]);
		}
		printf("\n");
	}
	if(isPalindromic()){
		for(int i =0;i<n;i++){
			printf("%d",a[n-i-1]);
		}
		printf(" is a palindromic number.");
	}
	else printf("Not found in 10 iterations.");
	return 0;
}
