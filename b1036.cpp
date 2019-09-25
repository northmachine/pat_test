#include <cstdio>
int main(){
	int N,M;
	char C;
	scanf("%d %c",&N,&C);
	if(N%2==0) M=N/2;
	else M = N/2 +1;
	for(int j =0;j<M;j++){
		for(int i =0;i<N;i++){
			if(i==0||i==N-1||j==0||j==M-1){
				printf("%c",C);
			}
			else printf(" ");
			if(i==N-1&&j!=M-1) printf("\n");
		}
	}
	return 0;
}
