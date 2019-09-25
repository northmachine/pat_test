#include <bits/stdc++.h>
using namespace std;
int main(){
	char str[100];
	scanf("%s",str);
	int n;
	sscanf(str,"%d",&n);
	printf("%d\n",n);
	n*=10;
	sprintf(str,"%d",n);
	printf("%s",str);
	return 0;
} 
