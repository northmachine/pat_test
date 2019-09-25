#include <cstdio>
int n;
char dig[3][5] = {"Shi","Bai","Qian"};
char num[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
void read(int x,bool f1,bool f2){
	int aa[4];
	int t = x;
	for(int i=1000,j=0;i>0;i/=10,j++){
		aa[j] = t/i;
		t%=i; 
	}
	int i=0;
	while(aa[i]==0)i++;
	int j=i;
	for(;i<4;i++){
		if(aa[i]!=0){
			if(i!=j||f1) printf(" "); 
			if(i==0||aa[i-1]!=0||i==j&&!f1){
				printf("%s",num[aa[i]]);
				if(i!=3) printf(" %s",dig[2-i]);
			}
			else {
				printf("ling %s",num[aa[i]]);
				if(i!=3) printf(" %s",dig[2-i]);
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	if(n==0) printf("ling");
	if(n<0){
		n = -n;
		printf("Fu ");
	}
	int a[3];
	a[2] = n % 10000;
	a[1] = (n/10000)%10000;
	a[0] = n/100000000;
	if(a[0]!=0) {
		bool f=0;
		if(a[1]!=0) f = 1;
		read(a[0],0,f);
		printf(" Yi");
	}
	if(a[1]!=0){
		bool f1 = false,f2 = false;
		if(a[0]!=0) f1 = 1;
		if(a[2]!=0) f2 = 1;
		read(a[1],f1,f2);
		printf(" Wan");
	}
	if(a[2]!=0){
		bool f = false;
		if(a[1]!=0) f = 1;
		read(a[2],f,0);
	}
	return 0;
} 
