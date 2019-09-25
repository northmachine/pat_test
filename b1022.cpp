#include <cstdio>
int main(){
	int a,b,d;
	scanf("%d%d%d",&a,&b,&d);
	int h = a+b;
	int res[31];
	int p=-1;
	do{
		res[++p]=h%d;
		h/=d;
	}while(h!=0);
	while(p>-1) printf("%d",res[p--]);
	return 0;
}
