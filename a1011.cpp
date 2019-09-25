#include <cstdio>
#include <cstdlib>
using namespace std;
double table[3][3];
int main(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%lf",&table[i][j]);
		}
	}
	int res[3] = {0};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(table[i][res[i]]<table[i][j]){
				res[i] = j;
			}
		}
	}
	for(int  i=0;i<3;i++){
		switch(res[i]){
			case 0:
				printf("W ");
				break;
			case 1:
				printf("T ");
				break;
			case 2:
				printf("L ");
				break;
			default:
				break;
		}
	}
	double r;
	r = (table[0][res[0]]*table[1][res[1]]*table[2][res[2]]*0.65-1)*2;
	printf("%.2f",r);
	return 0;
} 
