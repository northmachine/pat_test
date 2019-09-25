#include <cstdio>
using namespace std;
const int maxn = 2020;
double coe1[maxn];
double coe2[maxn];
double coe3[maxn];
int k1,k2;
int main(){
	scanf("%d",&k1);
	int exp;
	for(int i =0;i<k1;i++){
		scanf("%d",&exp);
		scanf("%lf",&coe1[exp]);
	}
	scanf("%d",&k2);
	for(int i =0;i<k2;i++){
		scanf("%d",&exp);
		scanf("%lf",&coe2[exp]);
	}
	int num3=0;
	for(int i=0,num1 = k1;num1!=0;i++){
		if(coe1[i]!=0.0){
			num1--;
			for(int j=0,num2 = k2;num2!=0;j++){
				if(coe2[j]!=0.0){
					num2--;
					if(coe3[i+j]==0.0) num3++;
					coe3[i+j] += coe1[i]*coe2[j];
					if(coe3[i+j]==0.0) num3--;
				}
			}
		}
	}
	printf("%d",num3);
	if(num3!=0) printf(" ");
	for(int i =maxn-1;i>=0;i--){
		if(coe3[i]!=0.0){
			printf("%d %.1f",i,coe3[i]);
			num3--;
			if(num3!=0)printf(" ");
			else break;
		}
	}
	return 0;
}
