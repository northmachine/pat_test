#include <cstdio>
int main(){
	int gsk1[3],gsk2[3];
	scanf("%d.%d.%d %d.%d.%d",&gsk1[0],&gsk1[1],&gsk1[2],&gsk2[0],&gsk2[1],&gsk2[2]);
	int gsk3[3];
	gsk3[2] = (gsk1[2]+gsk2[2])%29;
	gsk3[1] = ((gsk1[2]+gsk2[2])/29 + (gsk1[1]+gsk2[1]))%17;
	gsk3[0] = ((gsk1[2]+gsk2[2])/29 + (gsk1[1]+gsk2[1]))/17 + gsk1[0]+ gsk2[0];
	printf("%d.%d.%d",gsk3[0],gsk3[1],gsk3[2]);
	return 0;
}
