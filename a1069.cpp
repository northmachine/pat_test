#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int getNonIncrease(int x){
	int a[4];
	for(int i = 0;i<4;i++){
		a[i]=x%10;
		x/=10;
	}	
	sort(a+0,a+4);
	int re = 0;
	for(int i =0;i<4;i++)
		re+=a[i]*pow(10,i);
	return re;
}
int getNonDecrease(int x){
	int a[4];
	for(int i = 0;i<4;i++){
		a[i]=x%10;
		x/=10;
	}	
	sort(a+0,a+4);
	int re = 0;
	for(int i =3;i>=0;i--)
		re+=a[i]*pow(10,3-i);
	return re;
}
int main(){
	int n ;
	scanf("%d",&n);
	int con = -1;
	int i=0;
	int d=0;
	while(n!=6174){
		i = getNonIncrease(n);
		d = getNonDecrease(n);
		n = i-d;
		printf("%04d - %04d = %04d",i,d,n);
		if(!n) break;
		if(n!=6174)printf("\n");
	}
	return 0;
}
