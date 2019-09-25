#include <stdio.h>
int table[100001];
int main(){
	int N,school,score,max=0;
	scanf("%d",&N);
	for(int i = 0;i<N;i++){
		scanf("%d%d",&school,&score);
		table[school]+=score;
		max = table[school]>table[max]?school:max;
	}
	printf("%d %d",max,table[max]);
	return 0;
}
