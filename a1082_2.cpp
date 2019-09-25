#include <cstdio>
int a[10];
int n;
char dig[3][5] = {"Shi","Bai","Qian"};
char num[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(){
	scanf("%d",&n);
	int nn = n;
	if(n<0){
		n = -n;
		printf("Fu ");
	}
	int j=8;
	for(int i = 10;j>=0;j--){
		a[j] = n%i;
		n /= i;
	}
	if(a[0]!=0) printf("%s Yi",num[a[0]]);
	if(a[0]!=0&&nn%100000000!=0) printf(" ");
	for(int i=1;i<9;){
		for(;i<9&&a[i]==0;i++);
		printf("%s ",num[a[i]]);
		if((7-i)%4!=3){
			printf("%s",dig[(7-i)%4]);
			if(i!=8) printf(" ");
		}
		i++;
		int j=i;
		while(i<9&&a[i]==0) i++;
		if(j!=i){
			if(j<5){
				if(i<=4) printf("ling ");
				else if(i==5) printf("Wan ");
				else printf("Wan ling ");
			}
			else{
				if(i<=8) printf("ling ");
				else;
			}
		}
	}
	return 0;
}
