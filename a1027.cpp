#include <cstdio>
using namespace std;
int main(){
	int a;
	printf("#");
	for(int i=0;i<3;i++){
		scanf("%d",&a);
		int x,y;
		y = a%13;
		x = a/13;
		if(x==10) printf("A");
		else if(x==11) printf("B");
		else if(x==12) printf("C");
		else printf("%d",x);
		if(y==10) printf("A");
		else if(y==11) printf("B");
		else if(y==12) printf("C");
		else printf("%d",y);
	}
	return 0;
}
/*
#include <cstdio>
char radix[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'}
int main(){
	int rgb[3];
	scanf("%d%d%d",&rgb[0],&rgb[1],&rgb[2]);
	printf("#");
	for(int i =0;i<3;i++)printf("%c%c",radix[rgb[i]/13],radix[rgb[i]%13]);
	return 0;
}
*/
