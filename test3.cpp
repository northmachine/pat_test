#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[10];
	for(int i =0;i<5;i++)scanf("%d",&a[i]);
	printf("%d\n",upper_bound(a,a+5,3));
	printf("%d",a);
	return 0;
} 
