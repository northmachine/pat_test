#include <cstdio>
using namespace std;
const int maxn = 1010;
double coe1[maxn];
double coe2[maxn];
double coe3[maxn];
bool nozero[maxn];
int k;
int main(){
	scanf("%d",&k);
	int exp;
	for(int i =0;i<k;i++){
		scanf("%d",&exp);
		scanf("%f",&coe1[exp]);
	}
	scanf("%d",&k);
	for(int i =0;i<k;i++){
		scanf("%d",&exp);
		scanf("%f",&coe2[exp]);
	}
	int num = 0;
	for(int i =0;i<maxn;i++){
		coe3[i] = coe1[i]+coe2[i];
		if(coe3[i]!=0){
			num++;
		}
	}
	printf("%d",num);
	if(num!=0) printf(" ");
	for(int i =maxn-1;i>=0;i--){
		if(coe3[i]!=0){
			printf("%d %.1f",i,coe3[i]);
			num--;
			if(num!=0)printf(" ");
			else break;
		}
	}
	return 0;
} 
